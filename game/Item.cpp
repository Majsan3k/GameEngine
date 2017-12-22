#include <SDL2/SDL_image.h>
#include "../frame/Frame.h"
#include "../engine/GameEngine.h"
#include "Player.h"

using namespace gameEngine;
using namespace std;

namespace myGame{
    Item* Item::getInstance(SDL_Rect rect, const char* pictureSrc, int points){
        return new Item(rect, pictureSrc, points);
    }

    Item::Item(SDL_Rect rect, const char* pictureSrc, int points) : valuePoints(points), Movable(rect, pictureSrc) {}

    Item* Item::getAnimatedInstance(SDL_Rect rect, const char* pictureSrc, int frames, int speed, int points) {
        return new Item(rect, pictureSrc, frames, speed, points);
    }

    Item::Item(SDL_Rect rect, const char* pictureSrc, int frames, int speed, int points) : valuePoints(points), Movable(rect, pictureSrc, frames, speed) {}

    void Item::move(const Uint8 *state, GameEngine &engine) {
        int rectBottom = spriteRect.y + spriteRect.h;
        int rectTop = spriteRect.y;
        int rectRight = spriteRect.x + spriteRect.w;
        int rectLeft = spriteRect.x;

        int windowW = frame.getWidth();
        int windowH = frame.getHeight();

        if(rectBottom < 0 || rectTop > windowH || rectRight < 0 || rectLeft > windowW){
            shouldRemove = true;
        }else {
            spriteRect.y++;
        }
    }

    //TODO: Funkar inte som den ska, gör enbart check i player nu, ändra?
    //Bryta ut collisionschecken på något sätt? Eller inte ens göra den i Item?
    void Item::collisionOtherSprite(Sprite& otherSprite, GameEngine& engine){
//        if(dynamic_cast<Player*>(otherSprite)){
//            shouldRemove = true;
//            ((Player*)otherSprite)->collisionOtherSprite(this, engine);
//        }
    }
}