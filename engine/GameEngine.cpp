#include <iostream>
#include "GameEngine.h"
#include "../frame/Frame.h"
#include "../components/Button.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
//#define FPS 60

using namespace std;

namespace gameEngine {

    void GameEngine::add(Sprite *sprite) {
        sprites.push_back(sprite);
    }

    void GameEngine::updateItemsToRemove(Sprite *sprite) {
        itemsToRemove.push_back(sprite);
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

    //TODO: Kan man lägga in tpy String music och String background som argument?
    void GameEngine::run(int FPS) {
        bool musicPlay = true;
        playMusic(true);

        Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 4096);
        Mix_Chunk *music = Mix_LoadWAV("C:/Users/majal/Documents/Prog3/Inlupp/music.mp3");
        Mix_PlayChannel(-1, music, -1);

        const int roundTime = 1000 / FPS;
        Uint32 frameStart;
        int frameTime;

        SDL_Surface *backgroundPicture = IMG_Load("C:/Users/majal/Documents/Prog3/Inlupp/bg.jpg");
        background = SDL_CreateTextureFromSurface(frame.getRen(), backgroundPicture);
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
                }
            }

                frameTime = SDL_GetTicks() - frameStart;
                if (roundTime > frameTime) {
                    SDL_Delay(roundTime - frameTime);
                }

                const Uint8 *state = SDL_GetKeyboardState(NULL);
                for (Sprite *sprite : sprites)
                    sprite->tick(state, *this);

                for (Sprite *sprite : itemsToRemove)
                    remove(sprite);

                SDL_SetRenderDrawColor(frame.getRen(), 255, 255, 255, 0);
                SDL_RenderClear(frame.getRen());
                SDL_RenderCopy(frame.getRen(), background, NULL, NULL);
                for (Sprite *s : sprites)
                    s->draw();
                SDL_RenderPresent(frame.getRen());
            }
        }
    }
