#include <iostream>
#include "../components/Movable.h"
#include "Item.cpp"

using namespace game;
using namespace std;

namespace gameImpl {
    class Player : public Movable {
    public:
        Player(SDL_Rect rect, Label& label) : Movable(rect), pointLabel(label) {}

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

    private:
        Label& pointLabel;
        int point;
    };
}

