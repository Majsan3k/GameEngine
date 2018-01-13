#ifndef GAMEENGINE_PLAYER_H
#define GAMEENGINE_PLAYER_H
#include "../components/Movable.h"
#include "../components/Label.h"

using namespace gameEngine;

namespace myGame{
    class Player : public Movable{
    public:
        static Player* getInstance(SDL_Rect rect, Label& pointLabel, const char* picSrc, int speed);
        static Player* getInstance(SDL_Rect rect, Label& pointLabel, const char* picSrc, int speed,
                                   SDL_Keycode right, SDL_Keycode left, SDL_Keycode up, SDL_Keycode down);
        void handleCollision(Sprite* otherSprite, GameEngine& engine) override;
        void move(const Uint8* state, GameEngine& gameEngine) override;
        void setSpeed(int newSpeed){speed = newSpeed;}
        int getSpeed() const {return speed;}
        ~Player(){}
    protected:
        Player(SDL_Rect rect, Label& pointLabel, const char* picSrc, int speed);

        /* Constructor that can be used if default keys shouldn't move the player */
        Player(SDL_Rect rect, Label& pointLabel, const char* picSrc, int speed,
               SDL_Keycode right, SDL_Keycode left, SDL_Keycode up, SDL_Keycode down);
    private:
        Label& pointLabel;
        int points;
        int speed;
        const SDL_Keycode right = SDL_SCANCODE_RIGHT;
        const SDL_Keycode left = SDL_SCANCODE_LEFT;
        const SDL_Keycode up = SDL_SCANCODE_UP;
        const SDL_Keycode down = SDL_SCANCODE_DOWN;
    };
}

#endif //GAMEENGINE_PLAYER_H

