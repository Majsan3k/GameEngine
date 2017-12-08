#include <iostream>
#include "../components/Movable.h"
#include "Item.cpp"

using namespace gameEngine;
using namespace std;

namespace myGame {
    class Player : public Movable {
    public:
        static Player* getInstance(SDL_Rect picture, Label& lbl){
            return new Player(picture, lbl);
        }

        void changeState(const Uint8 *state, GameEngine &engine) override {
            if (state[SDL_SCANCODE_RIGHT]) {
                spriteRect.x += 5;
            }
            if (state[SDL_SCANCODE_LEFT]) {
                spriteRect.x -= 5;
            }
            if (state[SDL_SCANCODE_DOWN]) {
                spriteRect.y += 5;
            }
            if (state[SDL_SCANCODE_UP]) {
                spriteRect.y -= 5;
            }
        }

        void collisionOtherSprite(Sprite *otherSprite, GameEngine &engine) {
            if (otherSprite != this && dynamic_cast<Item *>(otherSprite)) {
                point++;
                pointLabel.setText(to_string(point));
                engine.updateItemsToRemove(otherSprite);
            }
        }
    protected:
        Player(SDL_Rect picture, Label& lbl) : pointLabel(lbl), Movable(picture){}
    private:
        Label& pointLabel;
        int point;
    };
}

