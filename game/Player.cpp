#include <iostream>
#include "../components/Movable.h"
#include "Player.h"
#include "Item.h"
#include "../engine/GameEngine.h"
#include "../frame/Frame.h"

using namespace gameEngine;
using namespace std;

namespace myGame {

    Player* Player::getInstance(SDL_Rect picture, Label& lbl, const char* pictureSrc, int speed){
        return new Player(picture, lbl, pictureSrc, speed);
    }

    Player* Player::getInstance(SDL_Rect picture, Label& lbl, const char* pictureSrc, int speed,
            SDL_Keycode right, SDL_Keycode left, SDL_Keycode up, SDL_Keycode down){
        return new Player(picture, lbl, pictureSrc, speed, right, left, up, down);
    }

    Player::Player(SDL_Rect rect, Label& lbl, const char* pictureSrc, int speed) :
            pointLabel(lbl), Movable(rect, pictureSrc), speed(speed){}

    Player::Player(SDL_Rect rect, Label& lbl, const char* pictureSrc, int speed,
            SDL_Keycode right, SDL_Keycode left, SDL_Keycode up, SDL_Keycode down) :
            pointLabel(lbl), Movable(rect, pictureSrc), speed(speed), right(right), left(left), up(up), down(down){}

    void Player::move(const Uint8 *state, GameEngine &engine) {

        int rectBottom = spriteRect.y + spriteRect.h;
        int rectTop = spriteRect.y;
        int rectRight = spriteRect.x + spriteRect.w;
        int rectLeft = spriteRect.x;
        int windowW = frame.getWidth();
        int windowH = frame.getHeight();

        if (state[right] && rectRight < windowW) {
            spriteRect.x += speed;
        }
        if (state[left] && rectLeft > 0) {
            spriteRect.x -= speed;
        }
        if (state[down] && rectBottom < windowH) {
            spriteRect.y += speed;
        }
        if (state[up] && rectTop > 0) {
            spriteRect.y -= speed;
        }
    }

    void Player::handleCollision(Sprite *otherSprite, GameEngine& engine) {
        if (Item *item = dynamic_cast<Item *>(otherSprite)) {
            points += item->getPoints();
            pointLabel.setText(to_string(points));
        }
    }
}

