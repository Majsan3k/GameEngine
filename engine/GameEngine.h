#ifndef GAMEENGINE_GAMEENGINE_H
#define GAMEENGINE_GAMEENGINE_H
#include <vector>
#include <SDL2/SDL_render.h>
#include "../components/Sprite.h"

namespace gameEngine {

    class GameEngine {

    public:
        void add(Sprite *sprite);
        void updateItemsToRemove(Sprite* sprite);
        void remove(Sprite*);
        void run(int);
        void playMusic(bool);
        const std::vector<Sprite*> getSprites() const { return sprites; };
        ~GameEngine();

    private:
        SDL_Texture* background;
        std::vector<Sprite*> sprites;
        std::vector<Sprite*> itemsToRemove;
    };
}
#endif
