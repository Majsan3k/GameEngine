#include <iostream>
#include "../components/Movable.h"
#include "Player.h"
#include "Item.h"
#include "../engine/GameEngine.h"

using namespace gameEngine;
using namespace std;

namespace myGame {

    Player* Player::getInstance(SDL_Rect picture, Label& lbl, const char* pictureSrc){
        return new Player(picture, lbl, pictureSrc);
    }

    Player::Player(SDL_Rect picture, Label& lbl, const char* pictureSrc) : pointLabel(lbl), Movable(picture, pictureSrc){}

    void Player::move(const Uint8 *state, GameEngine &engine) {
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

    void Player::collisionOtherSprite(Sprite& otherSprite, GameEngine &engine) {

        if (dynamic_cast<Item*>(&otherSprite)) {
            points += ((Item*)&otherSprite)->getPoints();
            pointLabel.setText(to_string(points));
            otherSprite.setRemove(true);

            //TODO: Kolla på att ändra level om tid finns
//            if(points > 1){
//                engine.setLevel(2);
//            }
        }
    }
}

