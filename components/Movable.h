#ifndef GAMEENGINE_MOVABLE_H
#define GAMEENGINE_MOVABLE_H
#include <SDL2/SDL_system.h>
#include "Sprite.h"
#include "Label.h"

namespace gameEngine {
    class Movable : public Sprite {
    public:
        static Movable* getInstance(SDL_Rect);
        virtual void changeState(const Uint8*, GameEngine&){}
        virtual void collisionOtherSprite(Sprite *, GameEngine &){}
        void tick(const Uint8*, GameEngine&);
        void draw();
        ~Movable();

    protected:
        Movable(SDL_Rect&);
    private:
        SDL_Texture* texture;
    };
}
#endif //GAMEENGINE_MOVABLE_H
