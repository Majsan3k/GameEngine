#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Frame.h"
using namespace std;

namespace game {
    Frame::Frame() {

        if (SDL_Init(SDL_INIT_EVERYTHING == -1)) {
            throw std::runtime_error(string("Unexpected problem with SDL init. ") + SDL_GetError());
        }

        window = SDL_CreateWindow("Game map", 100, 100, 500, 400, SDL_WINDOW_RESIZABLE);
        if (window == nullptr) {
            throw std::runtime_error(string("Problem with SDL_Window. ") + SDL_GetError());
        }

        ren = SDL_CreateRenderer(window, -1, 0);
        if (ren == nullptr) {
            throw std::runtime_error(string("Problem with Renderer. ") + SDL_GetError());
        }

        SDL_Surface *backgroundPicture = IMG_Load("C:/Users/majal/Documents/Prog3/Inlupp/background.jpg");
        SDL_Texture* test = SDL_CreateTextureFromSurface(frame.getRen(), backgroundPicture);
        SDL_FreeSurface(backgroundPicture);
        SDL_RenderCopy(ren, test, NULL, NULL);
    }

    Frame::~Frame() {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(window);
        SDL_Quit;
    }

    Frame frame;
}