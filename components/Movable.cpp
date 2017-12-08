#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Movable.h"
#include "../frame/Frame.h"
#include "../engine/GameEngine.h"


using namespace std;

namespace gameEngine {

    Movable::Movable(SDL_Rect& spritePicture, const char* pictureSrc) : Sprite(spritePicture) {
        SDL_Surface* picture = IMG_Load(pictureSrc);
        Uint32 white = SDL_MapRGB(picture->format, 255, 255, 255);
        SDL_SetColorKey(picture, SDL_ENABLE, white);

        texture = SDL_CreateTextureFromSurface(frame.getRen(), picture);
        SDL_FreeSurface(picture);
    }

    void Movable::tick(const Uint8 *state, GameEngine &engine){
        changeState(state, engine);

        std::vector<Sprite*> sprites = engine.getSprites();
        for(Sprite* sprite : sprites){
            if(collision(sprite)){
                collisionOtherSprite(sprite, engine);
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