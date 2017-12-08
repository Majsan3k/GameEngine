#ifndef GAMEENGINE_SPRITE_H
#define GAMEENGINE_SPRITE_H
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>

namespace gameEngine{
    class GameEngine;
    class Sprite {
    public:
        bool collision(Sprite*);
        virtual void draw() = 0;
        virtual void tick(const Uint8 *, GameEngine &) = 0;
        virtual void mouseButtonDown(SDL_Event&);
        virtual void mouseButtonUp(SDL_Event&, GameEngine&);
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