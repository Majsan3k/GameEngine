#include <SDL2/SDL_image.h>
#include "Item.h"
#include "../frame/Frame.h"
#include <iostream>

using namespace std;

namespace game{

    Item* Item::getInstance(SDL_Rect itemPic){
        return new Item(itemPic);
    }

    Item::Item(SDL_Rect& itemPic) : Sprite(itemPic){
        SDL_Surface* surf = IMG_Load("C:/Users/majal/Documents/Prog3/Inlupp/elephant.jpg");
        Uint32 white = SDL_MapRGB(surf->format, 255, 255, 255);
        SDL_SetColorKey(surf, SDL_ENABLE, white);
        itemTexture = SDL_CreateTextureFromSurface(frame.getRen(), surf);
        SDL_FreeSurface(surf);
    }

    Item::~Item(){
        SDL_DestroyTexture(itemTexture);
    }

    //TODO: För specifik för generella delen?
    void Item::tick(const Uint8* state, GameEngine& gameEngine){
        std::vector<Sprite*> sprites = gameEngine.getSprites();
        for(Sprite* sprite : sprites){
//            if(sprite != this && collision(sprite)){
//                gameEngine.remove(this);
//                return;
//            }
        }
        spriteRect.y++;
    }

    void Item::draw(){
        SDL_RenderCopy(frame.getRen(), itemTexture, NULL, &spriteRect);
    }
}