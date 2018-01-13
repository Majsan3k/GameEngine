#include <SDL2/SDL_image.h>
#include <algorithm>
#include "../frame/Frame.h"
#include "../engine/GameEngine.h"
#include "Player.h"

using namespace gameEngine;
using namespace std;

namespace myGame {

    bool Item::moveRight = true;

    Item *Item::getInstance(SDL_Rect rect, const char *pictureSrc, int points, bool moveHorizontal) {
        return new Item(rect, pictureSrc, points, moveHorizontal);
    }

    Item::Item(SDL_Rect rect, const char *pictureSrc, int points, bool moveHorizontal) : valuePoints(points), Movable(rect, pictureSrc), moveHorizontal(moveHorizontal){
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
            if(checkLastItem(engine)){
                engine.levelUp();
            }
        } else {
            if(moveHorizontal){
                if(direction){
                    spriteRect.x++;
                }else{
                    spriteRect.x--;
                }
            }else{
                spriteRect.y++;
            }
        }
    }

    bool Item::checkLastItem(GameEngine& engine){
        int items = 0;
        vector<Sprite*> activeSprites = engine.getActiveSprites();
        for(Sprite* sprite : activeSprites){
            if(dynamic_cast<Item*>(sprite)){
                items++;
            }
        }
        return items == 1 ? true : false;
    }

    void Item::handleCollision(Sprite* otherSprite, GameEngine& engine) {
        if (dynamic_cast<Player*>(otherSprite)) {
            setRemove(true);
        }
        if(checkLastItem(engine)){
            engine.levelUp();
        }
    }
}