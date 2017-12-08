#ifndef GAMEENGINE_PLAYER_H
#define GAMEENGINE_PLAYER_H
#include "../components/Movable.h"
#include "../components/Label.h"

using namespace gameEngine;

namespace myGame{
    class Player : public Movable{
    public:
        static Player* getInstance(SDL_Rect, Label&, const char*);
        void collisionOtherSprite(Sprite*, GameEngine&) override;
        void changeState(const Uint8*, GameEngine&) override;
    protected:
        Player(SDL_Rect, Label&, const char*);
    private:
        Label& pointLabel;
        int point;

    };

}

#endif //GAMEENGINE_PLAYER_H
