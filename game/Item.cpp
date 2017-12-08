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

        void Item::changeState(const Uint8 *state, GameEngine &engine) {
            spriteRect.y++;
        }

        void Item::collisionOtherSprite(Sprite* otherSprite, GameEngine& engine){
//            if(dynamic_cast<Player*>(otherSprite)){
//                engine.updateItemsToRemove(this);
//            }
        }
}