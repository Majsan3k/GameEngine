#ifndef GAMEENGINE_ITEM_H
#define GAMEENGINE_ITEM_H
#include "../components/Movable.h"

using namespace gameEngine;
namespace myGame{
    class Item : public Movable{
    public:
        static Item* getInstance(SDL_Rect rect, const char *pictureSrc, int points, bool moveHorizontal);
        static Item* getAnimatedInstance(SDL_Rect rect, const char *pictureSrc, int frames, int speed, int points, bool moveHorizontal);
        void handleCollision(Sprite*, GameEngine& engine) override;
        void move(const Uint8*, GameEngine&) ;
        int getPoints() const { return valuePoints; }
        ~Item(){}
    protected:
        Item(SDL_Rect rect, const char *pictureSrc, int points, bool moveHorizontal);
        Item(SDL_Rect rect, const char *pictureSrc, int frames, int speed, int points, bool moveHorizontal);
    private:
        int valuePoints;
        bool moveHorizontal;
        static bool moveRight;
        bool direction;
        static int speed;
        bool checkLastItem(GameEngine& engine);
    };
}


#endif //GAMEENGINE_ITEM_H
