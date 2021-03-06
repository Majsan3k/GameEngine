#ifndef GAMEENGINE_SPRITE_H
#define GAMEENGINE_SPRITE_H
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>

namespace gameEngine{
    class GameEngine;
    class Sprite {
    public:
        virtual void draw(Uint32) = 0;
        virtual void tick(const Uint8 *, GameEngine &) = 0;
        virtual void mouseButtonDown(){}
        virtual void mouseButtonUp(GameEngine&){}
        bool collision(Sprite&);
        const bool getShouldRemove() const { return shouldRemove; }
        void setRemove(bool remove){shouldRemove = remove; }
        const SDL_Rect& getSpriteRect() const { return spriteRect; }
        virtual ~Sprite(){}
    protected:
        /* SpriteRect is protected since sub classes need to update the position of it */
        SDL_Rect spriteRect;
        Sprite(SDL_Rect& spritePicture);
    private:
        bool shouldRemove = false;
        Sprite(const Sprite&) = delete; /* delete copy constructor */
        const Sprite& operator=(const Sprite&) = delete; /* delete =operator */
    };
}

#endif