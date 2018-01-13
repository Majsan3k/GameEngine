#include <iostream>
#include "../components/Movable.h"
#include "Player.h"
#include "Item.h"
#include "../engine/GameEngine.h"
#include "../frame/Frame.h"

using namespace gameEngine;
using namespace std;

namespace myGame {

    Player* Player::getInstance(SDL_Rect picture, Label& lbl, const char* pictureSrc){
        return new Player(picture, lbl, pictureSrc);
    }

    Player::Player(SDL_Rect picture, Label& lbl, const char* pictureSrc) : pointLabel(lbl), Movable(picture, pictureSrc){}

    void Player::move(const Uint8 *state, GameEngine &engine) {

        int rectBottom = spriteRect.y + spriteRect.h;
        int rectTop = spriteRect.y;
        int rectRight = spriteRect.x + spriteRect.w;
        int rectLeft = spriteRect.x;
        
        int windowW = frame.getWidth();
        int windowH = frame.getHeight();

        if (state[SDL_SCANCODE_RIGHT] && rectRight < windowW) {
                spriteRect.x += 5;
        }
        if (state[SDL_SCANCODE_LEFT] && rectLeft > 0) {
                spriteRect.x -= 5;
        }
        if (state[SDL_SCANCODE_DOWN] && rectBottom < windowH) {
            spriteRect.y += 5;
        }
        if (state[SDL_SCANCODE_UP] && rectTop > 0) {
            spriteRect.y -= 5;
        }
    }

    void Player::handleCollision(Sprite *otherSprite) {
        if (Item *item = dynamic_cast<Item *>(otherSprite)) {
            points += item->getPoints();
            pointLabel.setText(to_string(points));
        }
    }

//            //TODO: Kolla på att ändra level om tid finns
////            if(points > 1){
////                engine.setLevel(2);
////            }
//        }
}

