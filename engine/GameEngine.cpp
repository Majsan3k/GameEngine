#include <iostream>
#include "GameEngine.h"
#include "../frame/Frame.h"
#include "../components/Button.h"
#include "Level.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

using namespace std;
namespace gameEngine {

    GameEngine::~GameEngine() {
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

    void GameEngine::changeLevel(int i){
        const char* newBackground;
        auto contains = levels.find(i);
        if(contains != levels.end()){
            sprites = contains->second.getSprites();
            newBackground = contains->second.getBackground();
            updateBackground(newBackground);
        }else{
            cout << "No such level" << endl;
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

    void GameEngine::test(){
        std::vector<Sprite*> newSprites;
        const char* animated = "C:/Users/majal/Documents/Prog3/Inlupp/spritesheet.png";
        Item* human = Item::getAnimatedInstance({150, 0, 128, 64}, animated, 4, 200,-1);
        newSprites.push_back((Sprite*)human);
        Level level123("C:/Users/majal/Documents/Prog3/Inlupp/elephant.jpg", newSprites);

        levels.insert(make_pair(1, level123));
        changeLevel(1);
    }

    //TODO: Ta bort background härifrån ska fixas när gameEngine skapas med levels
    void GameEngine::run(int FPS, const char* musicSrc, bool musicOn, int level) {
        Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 4096);
        Mix_Chunk *music = Mix_LoadWAV(musicSrc);
        Mix_PlayChannel(-1, music, -1);
        playMusic(musicOn);

        const int roundTime = 1000 / FPS;
        Uint32 frameStart;
        int frameTime;

        changeLevel(level);

        bool goOn = true;
        while (goOn) {
            frameStart = SDL_GetTicks();
            SDL_Event event;

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
                        }
                        break;
                    case SDL_KEYDOWN :
                        if(shortcuts[event.key.keysym.sym]){
                            shortcuts[event.key.keysym.sym]();
                        }
                }
            }

            frameTime = SDL_GetTicks() - frameStart;
            if (roundTime > frameTime) {
                SDL_Delay(roundTime - frameTime);
            }

            const Uint8 *state = SDL_GetKeyboardState(NULL);
            for (Sprite *sprite : sprites)
                sprite->tick(state, *this);

            remove();

            SDL_SetRenderDrawColor(frame.getRen(), 255, 255, 255, 0);
            SDL_RenderClear(frame.getRen());
            SDL_RenderCopy(frame.getRen(), background, NULL, NULL);
            for (Sprite *s : sprites)
                s->draw(SDL_GetTicks());
            SDL_RenderPresent(frame.getRen());
        }
    }
}
