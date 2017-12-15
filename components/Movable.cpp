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

        if(picture == nullptr){
            throw std::runtime_error(string("Something went wrong while creating surface: ") + SDL_GetError());
        }

        Uint32 white = SDL_MapRGB(picture->format, 255, 255, 255);
        SDL_SetColorKey(picture, SDL_ENABLE, white);

        texture = SDL_CreateTextureFromSurface(frame.getRen(), picture);

        if(texture == nullptr){
            throw std::runtime_error(string("Something went wrong while creating texture: ") + SDL_GetError());
        }

        SDL_FreeSurface(picture);
    }

    Movable::Movable(SDL_Rect& spritePicture, const char* pictureSrc, int frames, int speed) : Movable(spritePicture, pictureSrc){
        srcrect = {0, 0, (spritePicture.w)/frames, spritePicture.h};
        animated = true;
        animatedFrames = frames;
        animatedSpeed = speed;
    }

    void Movable::tick(const Uint8 *state, GameEngine &engine){
        move(state, engine);

        std::vector<Sprite*> sprites = engine.getSprites();
        for(Sprite* sprite : sprites){
            if(sprite != this && collision(sprite)){
                collisionOtherSprite(sprite, engine);
            }
        }
    }

    //TODO: Snyggare lösning med spriteRect.w
    void Movable::draw(Uint32 ticks) {
        if(animated){
            spriteRect.w /= animatedFrames;
            srcrect.x = srcrect.w * ((ticks / animatedSpeed) % animatedFrames);
            SDL_RenderCopy(frame.getRen(), texture, &srcrect, &spriteRect);
            spriteRect.w *= animatedFrames;
        }else {
            SDL_RenderCopy(frame.getRen(), texture, NULL, &spriteRect);
        }
    }

    Movable::~Movable(){
        SDL_DestroyTexture(texture);
    }
}