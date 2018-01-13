#include <iostream>
#include <algorithm>
#include <vector>
#include "GameEngine.h"
#include "../frame/Frame.h"
#include "../components/Button.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

using namespace std;
namespace gameEngine {

    GameEngine::~GameEngine() {
        SDL_DestroyTexture(background);
    }

    void GameEngine::addAllSprites(){
        //TODO: Går det att använda unique_copy?
        for(auto level = levels.begin(); level != levels.end(); level++){

            vector<Sprite*> newSprites = (level->second) -> getSprites();
            for(Sprite* sprite : newSprites){
                if (find(allSprites.begin(), allSprites.end(),sprite)== allSprites.end()){
                    allSprites.push_back(sprite);
                }
            }
        }
    }

    void GameEngine::clearSprites(){
        for(Sprite* sprite : allSprites){
            delete sprite;
        }
    }

    void GameEngine::clearLevels(){
        for(auto level = levels.begin(); level!= levels.end(); level++){
            delete level->second;
        }
    }

    void GameEngine::updateBackground(const char* newBackgroundPic){
        SDL_Surface *backgroundPicture = IMG_Load(newBackgroundPic);

        if(backgroundPicture == nullptr){
            throw std::runtime_error(string("Something went wrong while creating surface: ") + SDL_GetError());
        }

        background = SDL_CreateTextureFromSurface(frame.getRen(), backgroundPicture);
        if(background == nullptr){
            throw std::runtime_error(string("Something went wrong while creating texture: ") + SDL_GetError());
        }

        SDL_FreeSurface(backgroundPicture);
    }

    void GameEngine::setLevel(int newLevel){
        this->level = newLevel;
        levelChange = true;
    }

    void GameEngine::updateLevel(){
        levelChange = false;

        auto contains = levels.find(level);
        if(contains != levels.end()){
            activeSprites = (contains->second)->getSprites();
            updateBackground((contains->second)->getBackground());
        }else{
            cout << "No such level" << endl;
            return;
        }
    }

    void GameEngine::addShortcut(unsigned key, std::function<void()> function){
        std::unordered_map<unsigned,std::function<void()>>::const_iterator contains = shortcuts.find (key);

        if ( contains == shortcuts.end() ){
            shortcuts.insert(make_pair(key, function));
        }else {
            shortcuts[key] = function;
        }
    }

    void GameEngine::add(Sprite *sprite) {
        activeSprites.push_back(sprite);
    }

    void GameEngine::removeSprite(Sprite *sprite) {
        for (vector<Sprite *>::iterator iter = activeSprites.begin();
             iter != activeSprites.end();)
            if (*iter == sprite) {
                iter = activeSprites.erase(iter);
            } else {
                iter++;
            }
    }

    void GameEngine::remove() {
        for (vector<Sprite *>::iterator iter = activeSprites.begin();
             iter != activeSprites.end();)
            if ((*iter)->getShouldRemove()) {
                iter = activeSprites.erase(iter);
            } else {
                iter++;
            }
    }

    void GameEngine::playMusic(bool play) {
        if (play) {
            Mix_Resume(-1);
        } else {
            Mix_Pause(-1);
        }
    }

    void GameEngine::setPaused(){
        paused = !paused;
        labelChanged = NULL;
    }

    void GameEngine::run(int FPS, const char* musicSrc, bool musicOn, int level) {
        Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 4096);
        Mix_Chunk *music = Mix_LoadWAV(musicSrc);
        Mix_PlayChannel(-1, music, -1);
        playMusic(musicOn);

        const int roundTime = 1000 / FPS;
        Uint32 frameStart;
        int frameTime;

        this->level = level;
        levelChange = true;
        std::string inputText = "";
        SDL_StartTextInput();
        bool goOn = true;
        bool changeText;
        paused = false;

        bool textChanged = false;

        while (goOn) {
            frameStart = SDL_GetTicks();
            SDL_Event event;

            while (SDL_PollEvent(&event)) {
                switch (event.type) {
                    case SDL_QUIT:
                        goOn = false;
                        break;
                    case SDL_MOUSEBUTTONDOWN :
                        for (Sprite *s : activeSprites) {
                            SDL_Point p = {event.button.x, event.button.y};
                            if (SDL_PointInRect(&p, &s->getSpriteRect()) && dynamic_cast<Button *>(s)) {
                                s->mouseButtonDown();
                            }
                        }
                        break;
                    case SDL_MOUSEBUTTONUP :
                        changeText = false;
                        for (Sprite *s : activeSprites) {
                            SDL_Point p = {event.button.x, event.button.y};
                            if (SDL_PointInRect(&p, &s->getSpriteRect())) {

                                if (dynamic_cast<Button *>(s)) {
                                    s->mouseButtonUp(*this);
                                    break;
                                }
                                if (dynamic_cast<Label *>(s) && (((Label *) s)->getEditable())) {
                                    if(labelChanged != (Label*) s){
                                        inputText = "";
                                    }
                                    labelChanged = (Label *) s;
                                    changeText = true;
                                    paused = true;
                                    break;
                                }
                            }
                        }
                        break;
                    case SDL_KEYDOWN :
                        if (shortcuts[event.key.keysym.sym]) {
                            shortcuts[event.key.keysym.sym]();
                        } else if (event.key.keysym.sym == SDLK_BACKSPACE && inputText.size() > 0 && changeText) {
                            inputText.pop_back();
                            textChanged = true;
                        }
                        break;
                }

                if (labelChanged != NULL && changeText && event.type == SDL_TEXTINPUT) {
                    if (inputText.length() < labelChanged->getMaxLength()) {
                        inputText += event.text.text;
                        textChanged = true;
                    }
                    break;
                }
            }
            if (textChanged) {
                if (labelChanged != NULL) {
                    if (!inputText.empty()) {
                        labelChanged->setText(inputText.c_str());
                    } else {
                        labelChanged->setDefaultText();
                    }
                }
            }

            frameTime = SDL_GetTicks() - frameStart;
            if (roundTime > frameTime) {
                SDL_Delay(roundTime - frameTime);
            }

            if (!paused) {
                /* Move sprites */
                const Uint8 *state = SDL_GetKeyboardState(NULL);
                for (Sprite *sprite : activeSprites) {
                    sprite->tick(state, *this);
                }

                /*Handle collisions */
                for (Sprite *sprite : activeSprites) {
                    if (Movable *m = dynamic_cast<Movable *>(sprite)) {
                        m->checkCollisionOtherSprite(*this);
                    }
                }

                remove();
                if (levelChange) {
                    updateLevel();
                }
            }

            SDL_SetRenderDrawColor(frame.getRen(), 255, 255, 255, 0);
            SDL_RenderClear(frame.getRen());
            SDL_RenderCopy(frame.getRen(), background, NULL, NULL);
            for (Sprite *s : activeSprites)
                s->draw(SDL_GetTicks());
            SDL_RenderPresent(frame.getRen());
        }
        SDL_StopTextInput();

        clearSprites();
        clearLevels();
    }
}
