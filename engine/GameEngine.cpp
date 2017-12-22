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
        for (Sprite *sprite : sprites) {
            delete sprite;
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
        this->newLevel = newLevel;
        levelChange = true;
    }

    void GameEngine::changeLevel(int i){

        vector<Sprite*> newSprites;

        const char* newBackground;
        auto contains = levels.find(i);
        if(contains != levels.end()){
            newSprites = contains->second.getSprites();
            newBackground = contains->second.getBackground();
            updateBackground(newBackground);
        }else{
            cout << "No such level" << endl;
        }
        levelChange = false;


//        for (Sprite *sprite : sprites) {
//
//            std::vector<Sprite* >::iterator it;
//            it = find(sprites.begin(), newSprites.end(), sprite);
//            if(it == newSprites.end()){
//                delete sprite;
//            }
//        }

        sprites = newSprites;
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
        sprites.push_back(sprite);
    }

    void GameEngine::remove() {
        for (vector<Sprite *>::iterator iter = sprites.begin();
             iter != sprites.end();)
            if ((*iter)->getShouldRemove()) {
                delete (*iter);
                iter = sprites.erase(iter);
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

    void GameEngine::run(int FPS, const char* musicSrc, bool musicOn, int level) {
        Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 4096);
        Mix_Chunk *music = Mix_LoadWAV(musicSrc);
        Mix_PlayChannel(-1, music, -1);
        playMusic(musicOn);

        const int roundTime = 1000 / FPS;
        Uint32 frameStart;
        int frameTime;

        changeLevel(level);
        std::string inputText = "";
        SDL_StartTextInput();
        bool goOn = true;
        Label* labelChanged = NULL;

        while (goOn) {
            frameStart = SDL_GetTicks();
            SDL_Event event;
            bool textChanged = false;

            while (SDL_PollEvent(&event)) {
                switch (event.type) {
                    case SDL_QUIT:
                        goOn = false;
                        break;
                    case SDL_MOUSEBUTTONDOWN :
                        //TODO: Flytta över dessa event till Button?
                        for (Sprite *s : sprites) {
                            if (dynamic_cast<Button *>(s)) {
                                s->mouseButtonDown(event);
                            }
                        }
                        break;
                    case SDL_MOUSEBUTTONUP :
                        for (Sprite *s : sprites) {
                            if (dynamic_cast<Button *>(s)) {
                                s->mouseButtonUp(event, *this);
                            }

                            //TODO: Se över upplägget på denna. Finns exakt samma point-check i Button-klassen på mouseButtonUp
                            if (dynamic_cast<Label *>(s) && (((Label*)s)->getEditable())) {
                                SDL_Point p = {event.button.x, event.button.y};
                                if(SDL_PointInRect(&p, &s->getSpriteRect())){
                                    labelChanged = (Label*)s;
                                }
                            }
                        }
                        break;
                    case SDL_KEYDOWN :
                        if(shortcuts[event.key.keysym.sym]){
                            shortcuts[event.key.keysym.sym]();
                        }
                }

                if(labelChanged != NULL && event.type == SDL_TEXTINPUT){
                    if(inputText.length() < 5)  {
                        inputText += event.text.text;
                        textChanged = true;
                    }
                }
            }
            if(textChanged){
                for (Sprite *s : sprites) {
                    if(labelChanged != NULL) {
//                    if (dynamic_cast<Label *>(s) && (((Label*)s)->getEditable())) {
                        if (inputText != "") {
//                            ((Label*)s)->setText(inputText.c_str());
                            labelChanged->setText(inputText.c_str());
                        } else if (labelChanged != NULL) {
//                            ((Label*)s)->setText("");
                            labelChanged->setText("");
//                        }
                        }
                    }
                }
            }

            frameTime = SDL_GetTicks() - frameStart;
            if (roundTime > frameTime) {
                SDL_Delay(roundTime - frameTime);
            }

            const Uint8 *state = SDL_GetKeyboardState(NULL);
            for (Sprite *sprite : sprites) {
                sprite->tick(state, *this);
            }

            remove();

            if(levelChange){
                changeLevel(newLevel);
            }

            SDL_SetRenderDrawColor(frame.getRen(), 255, 255, 255, 0);
            SDL_RenderClear(frame.getRen());
            SDL_RenderCopy(frame.getRen(), background, NULL, NULL);
            for (Sprite *s : sprites)
                s->draw(SDL_GetTicks());
            SDL_RenderPresent(frame.getRen());
        }
        SDL_StopTextInput();
    }
}
