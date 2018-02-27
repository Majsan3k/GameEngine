#ifndef GAMEENGINE_MOVABLE_H
#define GAMEENGINE_MOVABLE_H
#include <SDL2/SDL_system.h>
#include "Sprite.h"
#include "Label.h"

namespace gameEngine {
    class Movable : public Sprite {
    public:
        void checkCollisionOtherSprite(GameEngine& engine);
        void setDefaultPos();
        void tick(const Uint8* state, GameEngine& engine);
        void draw(Uint32);
        ~Movable();
    protected:
        Movable(SDL_Rect& rect, const char* pictureSrc);
        /* Create animated sprite with sprite sheet */
        Movable(SDL_Rect& rect, const char* pictureSrc, int frames, int speed);

    private:
        virtual void move(const Uint8* state, GameEngine& engine) = 0;
        virtual void handleCollision(Sprite* otherSprite, GameEngine& engine) = 0;
        SDL_Texture* texture;
        SDL_Rect srcrect;
        bool animated = false;
        int animatedFrames;
        int animatedSpeed;
        int defaultPosX;
        int defaultPosY;

        Movable(const Movable&) = delete; /* delete copy constructor */
        const Movable&operator=(const Movable&) = delete; /* delete =operator */
    };
}
#endif //GAMEENGINE_MOVABLE_H
