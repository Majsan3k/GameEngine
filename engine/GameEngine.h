#ifndef GAMEENGINE_GAMEENGINE_H
#define GAMEENGINE_GAMEENGINE_H
#include <vector>
#include <unordered_map>
#include <SDL2/SDL_render.h>
#include <functional>
#include "Level.h"
#include "../components/Sprite.h"
#include "../game/Item.h"

using namespace myGame;

namespace gameEngine {

    class GameEngine {
    public:
        GameEngine(std::unordered_map<int, Level> levels) : levels(levels){}
        GameEngine(std::unordered_map<int, Level> levels, std::unordered_map<unsigned, std::function<void()>> shortcuts) : levels (levels), shortcuts(shortcuts){}
        void setLevel(int);
        void updateBackground(const char*);
        void addShortcut(unsigned, std::function<void()>);
        void add(Sprite *sprite);
        void remove();
        void run(int, const char*, bool, int);
        void playMusic(bool);
        const std::vector<Sprite*> getSprites() const { return sprites; }
        ~GameEngine();



    private:
        SDL_Texture* background;
        bool levelChange = false;
        int newLevel;
        void changeLevel(int);
        std::vector<Sprite*> sprites;
        std::unordered_map<unsigned, std::function<void()>> shortcuts;
        std::unordered_map<int, Level> levels;
    };
}
#endif
