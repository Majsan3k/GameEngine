#ifndef GAMEENGINE_MOVABLE_H
#define GAMEENGINE_MOVABLE_H
#include <SDL2/SDL_system.h>
#include "Sprite.h"
#include "Label.h"

namespace gameEngine {
    class Movable : public Sprite {
    public:
        virtual void move(const Uint8* state, GameEngine& engine) = 0;
        void checkCollisionOtherSprite(GameEngine& engine);
        virtual void handleCollision(Sprite* sprite, GameEngine& engine) = 0;
        void setDefaultPos();
        void tick(const Uint8* state, GameEngine& engine);
        void draw(Uint32);
        ~Movable();
    protected:
        Movable(SDL_Rect& rect, const char* pictureSrc);
        Movable(SDL_Rect& rect, const char* pictureSrc, int frames, int speed);
    private:
        SDL_Texture* texture;
        SDL_Rect srcrect;
        Movable(const Movable&) = delete;
        const Movable&operator=(const Movable&) = delete;
        bool animated = false;
        int animatedFrames;
        int animatedSpeed;
        int defaultPosX;
        int defaultPosY;
    };
}
#endif //GAMEENGINE_MOVABLE_H
