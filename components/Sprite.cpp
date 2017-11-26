#include "Sprite.h"

namespace game{

    Sprite::Sprite(SDL_Rect& spritePicture):spriteRect(spritePicture) {
    }
    Sprite::~Sprite() {}
}