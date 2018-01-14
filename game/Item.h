#ifndef GAMEENGINE_ITEM_H
#define GAMEENGINE_ITEM_H
#include "../components/Movable.h"

namespace myGame{
    class Item : public gameEngine::Movable{
    public:
        static Item* getInstance(SDL_Rect rect, const char *pictureSrc, int points, bool moveHorizontal);
        static Item* getAnimatedInstance(SDL_Rect rect, const char *pictureSrc, int frames, int speed, int points, bool moveHorizontal);
        int getPoints() const { return valuePoints; }
    private:
        Item(SDL_Rect rect, const char *pictureSrc, int points, bool moveHorizontal);
        Item(SDL_Rect rect, const char *pictureSrc, int frames, int speed, int points, bool moveHorizontal);
        void handleCollision(gameEngine::Sprite*, gameEngine::GameEngine& engine) override;
        void move(const Uint8*, gameEngine::GameEngine&) override ;
        int valuePoints;
        bool moveHorizontal;
        static bool moveRight;
        bool direction;
        static double speed;
        void tryLevelUp(gameEngine::GameEngine &engine);
    };
}
#endif //GAMEENGINE_ITEM_H