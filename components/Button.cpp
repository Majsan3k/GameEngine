#include <SDL2/SDL_image.h>
#include "Button.h"
#include "../frame/Frame.h"
#include <iostream>
using namespace std;

namespace gameEngine{

    Button::Button(SDL_Rect& button, const char* frontPicSrc, const char* backPicSrc) : Sprite(button){
        SDL_Surface* frontSurf = IMG_Load(frontPicSrc);
        SDL_Surface* backSurf = IMG_Load(backPicSrc);

        if(frontSurf == nullptr || backSurf == nullptr){
            throw std::runtime_error(string("Something went wrong while creating surface: ") + SDL_GetError());
        }

        Uint32 white = SDL_MapRGB(frontSurf->format, 255, 255, 255);
        SDL_SetColorKey(frontSurf, SDL_ENABLE, white);
        SDL_SetColorKey(backSurf, SDL_ENABLE, white);

        frontIcon = SDL_CreateTextureFromSurface(frame.getRen(), frontSurf);
        backIcon = SDL_CreateTextureFromSurface(frame.getRen(), backSurf);

        if(frontIcon == nullptr || backIcon == nullptr){
            throw std::runtime_error(string("Something went wrong while creating texture: ") + SDL_GetError());
        }

        SDL_FreeSurface(frontSurf);
        SDL_FreeSurface(backSurf);
    }

    Button::~Button() {
        SDL_DestroyTexture(backIcon);
        SDL_DestroyTexture(frontIcon);
    }

    void Button::mouseButtonUp(SDL_Event& event, GameEngine& gameEngine) {
        SDL_Point p = {event.button.x, event.button.y};
        if(isDown && SDL_PointInRect(&p, &spriteRect)){
            perform(gameEngine);
            isDown = false;
        }
    }

    void Button::mouseButtonDown(SDL_Event& event) {
        SDL_Point p = {event.button.x, event.button.y};
        if(SDL_PointInRect(&p, &spriteRect)){
            isDown = true;
        }
    }

    void Button::draw(Uint32){
        if(active) {
            SDL_RenderCopy(frame.getRen(), frontIcon, NULL, &spriteRect);
        }else{
            SDL_RenderCopy(frame.getRen(), backIcon, NULL, &spriteRect);
        }
    }
}