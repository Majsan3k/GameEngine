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
        GameEngine(std::unordered_map<int, Level*> levels) : levels(levels){addAllSprites();}
        GameEngine(std::unordered_map<int, Level*> levels, std::unordered_map<unsigned, std::function<void()>> shortcuts) : levels (levels), shortcuts(shortcuts){addAllSprites();}
        void setLevel(int newLevel);
        int getLevel() const { return level; }
        void updateBackground(const char* bgPic);
        void addShortcut(unsigned shortCutKey, std::function<void()> function);
        void add(Sprite *sprite);
        void removeSprite(Sprite* sprite);
        void remove();
        void run(int FPS, const char* musicSrc, bool musicOn, int level);
        void playMusic(bool);
        const std::vector<Sprite*> getActiveSprites() const { return activeSprites; }
        void clearSprites();
        void clearLevels();
        void setPaused() {paused = !paused; }
        ~GameEngine();
    private:
        void addAllSprites();
        SDL_Texture* background;
        bool levelChange = false;
        bool paused = false;
        int level;
        void updateLevel();
        std::vector<Sprite*> activeSprites;
        std::vector<Sprite*> allSprites;
        std::unordered_map<unsigned, std::function<void()>> shortcuts;
        std::unordered_map<int, Level*> levels;
    };
}
#endif
