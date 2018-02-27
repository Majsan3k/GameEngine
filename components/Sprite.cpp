#include "Sprite.h"

namespace gameEngine{

    Sprite::Sprite(SDL_Rect& spritePicture):spriteRect(spritePicture) {
    }

    bool Sprite::collision(Sprite& otherSprite){
        SDL_Rect otherRect = otherSprite.getSpriteRect();
        int bottom = spriteRect.y + spriteRect.h;
        int top = spriteRect.y;
        int right = spriteRect.x + spriteRect.w;
        int left = spriteRect.x;

        int otherBottom = otherRect.y + otherRect.h;
        int otherTop = otherRect.y;
        int otherRight = otherRect.x + otherRect.w;
        int otherLeft = otherRect.x;

        if(bottom <= otherTop || top >= otherBottom){
            return false;
        }
        if(right <= otherLeft || left >= otherRight ){
            return false;
        }
        return true;
    }
}