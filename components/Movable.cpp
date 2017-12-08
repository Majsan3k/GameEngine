#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Movable.h"
#include "../frame/Frame.h"
#include "../engine/GameEngine.h"
#include "Item.h"


using namespace std;

namespace game {

    Movable::Movable(SDL_Rect& spritePicture) : Sprite(spritePicture) {
        SDL_Surface* picture = IMG_Load("C:/Users/majal/Documents/Prog3/Inlupp/hat.png");
//        Uint32 white = SDL_MapRGB(picture->format, 255, 255, 255);
//        SDL_SetColorKey(picture, SDL_ENABLE, white);

        texture = SDL_CreateTextureFromSurface(frame.getRen(), picture);
        SDL_FreeSurface(picture);
    }

    //TODO: För specifik för generella delen?
    void Movable::tick(const Uint8 *state, GameEngine &engine){
        changeState(state, engine);

        std::vector<Sprite*> sprites = engine.getSprites();
        for(Sprite* sprite : sprites){
            if(sprite != this && dynamic_cast<Item*>(sprite) && collision(sprite)){
               collisionItem(*sprite, engine);
            }
        }
    }

    void Movable::draw() {
        SDL_RenderCopy(frame.getRen(), texture, NULL, &spriteRect);
    }

    Movable::~Movable(){
        SDL_DestroyTexture(texture);
    }
}