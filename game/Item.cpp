#include <SDL2/SDL_image.h>
#include <algorithm>
#include "../frame/Frame.h"
#include "../engine/GameEngine.h"
#include "Player.h"

using namespace gameEngine;
using namespace std;

namespace myGame {

    double Item::speed = 1;
    bool Item::moveRight = true;

    Item *Item::getInstance(SDL_Rect rect, const char *pictureSrc, int points, bool moveHorizontal) {
        return new Item(rect, pictureSrc, points, moveHorizontal);
    }

    Item::Item(SDL_Rect rect, const char *pictureSrc, int points, bool moveHorizontal) :
            valuePoints(points), Movable(rect, pictureSrc), moveHorizontal(moveHorizontal){
        Item::moveRight = !moveRight;
        direction = !moveRight;
    }

    Item *Item::getAnimatedInstance(SDL_Rect rect, const char *pictureSrc, int frames, int speed, int points, bool moveHorizontal) {
        return new Item(rect, pictureSrc, frames, speed, points, moveHorizontal);
    }

    Item::Item(SDL_Rect rect, const char *pictureSrc, int frames, int speed, int points, bool moveHorizontal) :
            valuePoints(points), Movable(rect, pictureSrc,frames, speed), moveHorizontal(moveHorizontal) {
        Item::moveRight = !moveRight;
        direction = moveRight;
    }

    void Item::move(const Uint8 *state, GameEngine &engine) {
        int rectBottom = spriteRect.y + spriteRect.h;
        int rectTop = spriteRect.y;
        int rectRight = spriteRect.x + spriteRect.w;
        int rectLeft = spriteRect.x;

        int windowW = frame.getWidth();
        int windowH = frame.getHeight();

        if (rectBottom < 0 || rectTop > windowH || rectRight < 0 || rectLeft > windowW) {
            setRemove(true);
            tryLevelUp(engine);
        } else {
            if(moveHorizontal){
                if(direction){
                    spriteRect.x += speed;
                }else{
                    spriteRect.x -= speed;
                }
            }else{
                spriteRect.y += speed;
            }
        }
    }

    void Item::tryLevelUp(GameEngine &engine){
        int items = 0;
        vector<Sprite*> activeSprites = engine.getActiveSprites();
        for(Sprite* sprite : activeSprites){
            if(Item* item = dynamic_cast<Item*>(sprite)) {
                if (!item->getShouldRemove()) {
                    items++;
                }
            }
        }
        if(items == 1){
            engine.levelUp();
            speed += 0.5;
        }
    }

    void Item::handleCollision(Sprite* otherSprite, GameEngine& engine) {
        if (dynamic_cast<Player*>(otherSprite)) {
            setRemove(true);
        }
        tryLevelUp(engine);
    }
}