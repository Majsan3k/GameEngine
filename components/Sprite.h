#ifndef GAMEENGINE_SPRITE_H
#define GAMEENGINE_SPRITE_H
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_events.h>

namespace game{
    class GameEngine;
    class Sprite {
    public:
        virtual void draw() = 0;
        virtual void tick(const Uint8 *, GameEngine &) = 0;
        virtual bool collision(Sprite*) = 0;
        const SDL_Rect& getSpriteRect() const { return spriteRect; }
        virtual ~Sprite();

    protected:
        SDL_Rect spriteRect;
        Sprite(SDL_Rect& spritePicture);

    private:

        Sprite(const Sprite&) = delete; //delete copy constructor
        const Sprite& operator=(const Sprite&) = delete; //delete "tilldelningskonstruktor"
    };
}

#endif