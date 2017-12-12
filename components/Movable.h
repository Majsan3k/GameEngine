#ifndef GAMEENGINE_MOVABLE_H
#define GAMEENGINE_MOVABLE_H
#include <SDL2/SDL_system.h>
#include "Sprite.h"
#include "Label.h"

namespace gameEngine {
    class Movable : public Sprite {
    public:
        virtual void move(const Uint8 *, GameEngine &) = 0;
        virtual void collisionOtherSprite(Sprite *, GameEngine &){}
        void tick(const Uint8*, GameEngine&);
        void draw();
        ~Movable();

    protected:
        Movable(SDL_Rect&, const char*);
    private:
        SDL_Texture* texture;
        Movable(const Movable&) = delete;
        const Movable&operator=(const Movable&) = delete;
    };
}
#endif //GAMEENGINE_MOVABLE_H
