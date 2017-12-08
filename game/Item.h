#ifndef GAMEENGINE_ITEM_H
#define GAMEENGINE_ITEM_H
#include "../components/Movable.h"

using namespace gameEngine;

namespace myGame{

    class Item : public Movable{
        class Player;
    public:
        static Item* getInstance(SDL_Rect, const char*);
        void collisionOtherSprite(Sprite*, GameEngine&) override;
        void changeState(const Uint8*, GameEngine&);

    protected:
        Item(SDL_Rect, const char*);

    };

}


#endif //GAMEENGINE_ITEM_H
