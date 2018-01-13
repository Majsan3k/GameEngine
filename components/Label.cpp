#include "Label.h"
#include "../frame/Frame.h"
#include "SDL2/SDL_ttf.h"
#include <iostream>
using namespace std;

namespace gameEngine {
    Label* Label::getInstance(SDL_Rect rect, std::string txt, const char* fontSrc, int fontSize, bool editable, int maxLength) {
        return new Label(rect, txt, fontSrc, fontSize, editable, maxLength);
    }

    Label::Label(SDL_Rect& rect, std::string text, const char* fontSrc, int fontSize, bool editable, int maxLength) :
                Sprite(rect), defaultText(text), editable(editable), maxTextLength(maxLength) {

        if(TTF_Init() == -1){
            throw runtime_error(string("Problem with TTF init: ") + SDL_GetError());
        }

        font = TTF_OpenFont(fontSrc, fontSize);
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
        setText(defaultText);
        SDL_FreeSurface(surf);
    }

    void Label::draw(Uint32){
        SDL_RenderCopy(frame.getRen(), labelTexture, NULL, &spriteRect);
    }

    void Label::setDefaultText() {
        setText(defaultText);
    }

    void Label::setText(std::string newText){
        text = newText;
        SDL_DestroyTexture(labelTexture);
        SDL_Surface* surf = TTF_RenderText_Solid(font, text.c_str(), {0,0,0});

        if(surf == nullptr){
            throw std::runtime_error(string("Something went wrong while creating surface") + SDL_GetError());
        }
        labelTexture = SDL_CreateTextureFromSurface(frame.getRen(), surf);

        spriteRect.w = surf->w;
        spriteRect.h = surf->h;

        if(labelTexture == nullptr){
            throw std::runtime_error(string("Something went wrong while creating texture") + SDL_GetError());
        }
        SDL_FreeSurface(surf);
    }

    Label::~Label(){
        SDL_DestroyTexture(labelTexture);
        TTF_CloseFont(font);
        TTF_Quit();
    }
}