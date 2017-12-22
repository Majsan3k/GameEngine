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
        bool collision(Sprite&);
        virtual void draw(Uint32) = 0;
        virtual void tick(const Uint8 *, GameEngine &) = 0;
        virtual void mouseButtonDown(SDL_Event&);
        virtual void mouseButtonUp(SDL_Event&, GameEngine&);
        const bool getShouldRemove(){ return shouldRemove; }
        void setRemove(bool remove){shouldRemove = remove; }
        const SDL_Rect& getSpriteRect() const { return spriteRect; }
        virtual ~Sprite(){ delete &spriteRect; }

    protected:
        SDL_Rect spriteRect;
        Sprite(SDL_Rect& spritePicture);
        bool shouldRemove = false;

    private:
        Sprite(const Sprite&) = delete; //delete copy constructor
        const Sprite& operator=(const Sprite&) = delete; //delete "tilldelningskonstruktor"
    };
}

#endif