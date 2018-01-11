#ifndef GAMEENGINE_GAMEENGINE_H
#define GAMEENGINE_GAMEENGINE_H
#include <vector>
#include <unordered_map>
#include <SDL2/SDL_render.h>
#include <functional>
#include "Level.h"
#include "../components/Sprite.h"
#include "../game/Item.h"

namespace gameEngine {

    class GameEngine {
    public:
        GameEngine(std::unordered_map<int, Level*> levels) : levels(levels){}
        GameEngine(std::unordered_map<int, Level*> levels, std::unordered_map<unsigned, std::function<void()>> shortcuts) : levels (levels), shortcuts(shortcuts){}
        void setLevel(int newLevel);
        int getLevel() const { return level; }
        void updateBackground(const char* bgPic);
        void addShortcut(unsigned shortCutKey, std::function<void()> function);
        void add(Sprite *sprite);
        void remove();
        void run(int FPS, const char* musicSrc, bool musicOn, int level);
        void playMusic(bool);
        const std::vector<Sprite*> getSprites() const { return sprites; }
        ~GameEngine();
    private:
        SDL_Texture* background;
        bool levelChange = false;
        int level;
        void updateLevel();
        std::vector<Sprite*> sprites;
        std::unordered_map<unsigned, std::function<void()>> shortcuts;
        std::unordered_map<int, Level*> levels;
    };
}
#endif
