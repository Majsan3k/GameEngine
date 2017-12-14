#include <iostream>
#include "GameEngine.h"
#include "../frame/Frame.h"
#include "../components/Button.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

using namespace std;

namespace gameEngine {

    void GameEngine::addShortcut(unsigned key, void (*keyFunction)()){
        std::unordered_map<unsigned,void(*)()>::const_iterator contains = shortcuts.find (key);

        if ( contains == shortcuts.end() ){
            shortcuts.insert(make_pair(key, keyFunction));
        }else {
            shortcuts[key] = keyFunction;
        }
    }

    void GameEngine::add(Sprite *sprite) {
        sprites.push_back(sprite);
    }

    void GameEngine::remove(Sprite *sprite) {
        for (vector<Sprite *>::iterator iter = sprites.begin();
             iter != sprites.end();)
            if (*iter == sprite) {
                delete (sprite);
                iter = sprites.erase(iter);
            } else {
                iter++;
            }
    }

    GameEngine::~GameEngine() {
        for (Sprite *sprite : sprites) {
            delete sprite;
        }
    }

    void GameEngine::playMusic(bool play) {
        if (play) {
            Mix_Resume(-1);
        } else {
            Mix_Pause(-1);
        }
    }

    void GameEngine::run(int FPS, const char* musicSrc, const char* backgroundSrc) {
        bool musicPlay = true;
        playMusic(true);

        Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 4096);
        Mix_Chunk *music = Mix_LoadWAV(musicSrc);
        Mix_PlayChannel(-1, music, -1);

        const int roundTime = 1000 / FPS;
        Uint32 frameStart;
        int frameTime;

        SDL_Surface *backgroundPicture = IMG_Load(backgroundSrc);

        if(backgroundPicture == nullptr){
            throw std::runtime_error(string("Something went wrong while creating surface: ") + SDL_GetError());
        }

        background = SDL_CreateTextureFromSurface(frame.getRen(), backgroundPicture);
        if(background == nullptr){
            throw std::runtime_error(string("Something went wrong while creating texture: ") + SDL_GetError());
        }

        SDL_FreeSurface(backgroundPicture);

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

            SDL_SetRenderDrawColor(frame.getRen(), 255, 255, 255, 0);
            SDL_RenderClear(frame.getRen());
            SDL_RenderCopy(frame.getRen(), background, NULL, NULL);
            for (Sprite *s : sprites)
                s->draw(SDL_GetTicks());
            SDL_RenderPresent(frame.getRen());
        }
    }
}
