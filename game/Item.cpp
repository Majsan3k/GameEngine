#include <SDL2/SDL_image.h>
#include "../frame/Frame.h"
#include "../engine/GameEngine.h"
#include "../components/Movable.h"
#include "Item.h"

using namespace gameEngine;
using namespace std;

namespace myGame{
    Item* Item::getInstance(SDL_Rect rect, const char* pictureSrc) {
        return new Item(rect, pictureSrc);
    }

    Item::Item(SDL_Rect rect, const char* pictureSrc) : Movable(rect, pictureSrc) {}

    Item* Item::getAnimatedInstance(SDL_Rect rect, const char* pictureSrc, int frames, int speed) {
        return new Item(rect, pictureSrc, frames, speed);
    }

    Item::Item(SDL_Rect rect, const char* pictureSrc, int frames, int speed) : Movable(rect, pictureSrc, frames, speed) {}

    void Item::move(const Uint8 *state, GameEngine &engine) {
        int rectBottom = spriteRect.y + spriteRect.h;
        int rectTop = spriteRect.y;
        int rectRight = spriteRect.x + spriteRect.w;
        int rectLeft = spriteRect.x;

        int windowW = frame.getWidth();
        int windowH = frame.getHeight();

        if(rectBottom < 0 || rectTop > windowH || rectRight < 0 || rectLeft > windowW){
            engine.remove(this);
        }else {
            spriteRect.y++;
        }
    }

    //TODO: Fixa så item tar bort sig själv. Nu tar Playern bort det
    void Item::collisionOtherSprite(Sprite* otherSprite, GameEngine& engine){
//            if(dynamic_cast<Player*>(otherSprite)){
//                engine.updateItemsToRemove(this);
//            }
    }
}