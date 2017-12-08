#include "Sprite.h"

namespace game{

    //TODO: Flytta över kollisionshanteringen hit.

    Sprite::Sprite(SDL_Rect& spritePicture):spriteRect(spritePicture) {
    }

    bool Sprite::collision(Sprite*){}

    void Sprite::mouseButtonUp(SDL_Event&, GameEngine& gameEngine){}

    void Sprite::mouseButtonDown(SDL_Event&){}

    Sprite::~Sprite() {}
}