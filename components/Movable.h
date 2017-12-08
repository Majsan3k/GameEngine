#ifndef GAMEENGINE_MOVABLE_H
#define GAMEENGINE_MOVABLE_H
#include <SDL2/SDL_system.h>
#include "Sprite.h"
#include "Label.h"

namespace game {
    class Movable : public Sprite {
    public:
        virtual void changeState(const Uint8*, GameEngine&) = 0;
        virtual void collisionItem(Sprite&, GameEngine&) = 0;
        void tick(const Uint8*, GameEngine&);
        void draw();
        ~Movable();

    protected:
        Movable(SDL_Rect&);
    private:
        SDL_Texture* texture;
        Movable(const Movable&) = delete; //delete copy constructor
        const Movable& operator=(const Movable&) = delete; //delete "tilldelningskonstruktor"
    };
}
#endif //GAMEENGINE_MOVABLE_H
