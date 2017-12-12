#ifndef GAMEENGINE_GAMEENGINE_H
#define GAMEENGINE_GAMEENGINE_H
#include <vector>
#include <SDL2/SDL_render.h>
#include "../components/Sprite.h"

namespace gameEngine {

    class GameEngine {

    public:
        void add(Sprite *sprite);
        void remove(Sprite*);
        void run(int, const char*, const char*);
        void playMusic(bool);
        const std::vector<Sprite*> getSprites() const { return sprites; };
        ~GameEngine();

    private:
        SDL_Texture* background;
        std::vector<Sprite*> sprites;
    };
}
#endif
