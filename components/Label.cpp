#include "Label.h"
#include "../frame/Frame.h"
#include "SDL2/SDL_ttf.h"
#include <iostream>
using namespace std;

namespace gameEngine {
    Label* Label::getInstance(SDL_Rect rect, std::string txt, const char* fontSrc) {
        return new Label(rect, txt, fontSrc);
    }

    Label::Label(SDL_Rect& rect, std::string text, const char* fontSrc) : Sprite(rect), text(text) {

        TTF_Init();
        font = TTF_OpenFont(fontSrc, 15);
        if (font == nullptr) {
            throw std::runtime_error(string("Something went wrong while creating TFF: ") + SDL_GetError());
        }

        SDL_Surface *surf = TTF_RenderText_Solid(font, text.c_str(), {0, 0, 0});

        if (surf == nullptr){
            throw std::runtime_error(string("Something went wrong while creating surface: ") + SDL_GetError());
        }

        labelTexture = SDL_CreateTextureFromSurface(frame.getRen(), surf);

        if(labelTexture == nullptr){
            throw std::runtime_error(string("Something went wrong while creating texture: ") + SDL_GetError());
        }

        SDL_FreeSurface(surf);
    }

    void Label::draw(Uint32){
        SDL_RenderCopy(frame.getRen(), labelTexture, NULL, &spriteRect);
    }

    void Label::setText(std::string newText){
        text = newText;
        SDL_DestroyTexture(labelTexture);
        SDL_Surface* surf = TTF_RenderText_Solid(font, text.c_str(), {0,0,0});
        labelTexture = SDL_CreateTextureFromSurface(frame.getRen(), surf);
        SDL_FreeSurface(surf);
    }

    Label::~Label(){
        SDL_DestroyTexture(labelTexture);
        TTF_Quit();
    }
}