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
        /* Create a game engine without levels and sprites.
         * Can add sprites manually later with the method addSprite and
         * create a background with the method updateBackground */
        GameEngine(){}

        /* Create game engine with levels */
        GameEngine(std::unordered_map<int, Level*> levels) : levels(levels){addAllSprites();}

        /* Create game engine with both levels and shortcuts */
        GameEngine(std::unordered_map<int, Level*> levels, std::unordered_map<unsigned, std::function<void()>> shortcuts) : levels (levels), shortcuts(shortcuts){addAllSprites();}

        void setLevel(int newLevel);
        int getLevel() const { return level; }
        void levelUp(){setLevel(++level);}
        void updateBackground(const char* bgPic);
        void addShortcut(unsigned shortcutKey, std::function<void()> function);
        void addSprite(Sprite *newSprite);
        void removeSprite(Sprite* sprite);
        void run(int FPS, const char* musicSrc, bool musicOn, int level);
        void playMusic(bool);
        const std::vector<Sprite*> getActiveSprites() const { return activeSprites; }
        void setPaused();
        ~GameEngine();
    private:
        void clearSprites();
        void clearLevels();
        void removeInactiveSprites();
        void addAllSprites();
        SDL_Texture* background;
        Label* labelChanged = NULL;
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
