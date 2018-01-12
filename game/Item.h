//TODO: Lägg in i spelmotorn?

#ifndef GAMEENGINE_ITEM_H
#define GAMEENGINE_ITEM_H
#include "../components/Movable.h"

using namespace gameEngine;
namespace myGame{
    class Item : public Movable{
    public:
        static Item* getInstance(SDL_Rect, const char*, int);
        static Item* getAnimatedInstance(SDL_Rect, const char*, int, int, int);
        void collisionOtherSprite(Sprite&, GameEngine&) override;
        void move(const Uint8*, GameEngine&);
        int getPoints() const { return valuePoints; }
        void test(){std::cout << "Item" << std::endl; }
        ~Item(){}
    protected:
        Item(SDL_Rect, const char*, int);
        Item(SDL_Rect, const char*, int, int, int);
    private:
        int valuePoints;
    };

}


#endif //GAMEENGINE_ITEM_H
