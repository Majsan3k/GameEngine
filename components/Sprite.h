#ifndef GAMEENGINE_SPRITE_H
#define GAMEENGINE_SPRITE_H
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>

#include <iostream>

namespace gameEngine{
    class GameEngine;
    class Sprite {
    public:
        //TODO: Ta bort, bara test
        static void hej(){ std::cout << "Sprite" << std::endl; }

        bool collision(Sprite*);
        virtual void draw(Uint32) = 0;
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