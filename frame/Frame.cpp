#include <iostream>
#include <SDL2/SDL.h>
#include "Frame.h"
using namespace std;

namespace gameEngine {
    Frame::Frame() {

        if (SDL_Init(SDL_INIT_EVERYTHING == -1)) {
            throw runtime_error(string("Unexpected problem with SDL init. ") + SDL_GetError());
        }

        //Ska användaren få ange storlek?
        window = SDL_CreateWindow("Game map", 100, 100, 700, 600, 0);
        if (window == nullptr) {
            throw runtime_error(string("Problem with SDL_Window. ") + SDL_GetError());
        }

        ren = SDL_CreateRenderer(window, -1, 0);
        if (ren == nullptr) {
            throw runtime_error(string("Problem with Renderer. ") + SDL_GetError());
        }
    }

    Frame::~Frame() {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(window);
        SDL_Quit;
    }

    Frame frame;
}