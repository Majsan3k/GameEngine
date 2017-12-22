#ifndef GAMEENGINE_LEVEL_H
#define GAMEENGINE_LEVEL_H
#include <vector>
#include "../components/Sprite.h"

namespace gameEngine {
    class Level {
    public:
        Level(const char*, std::vector<Sprite*>);
        std::vector<Sprite*> getSprites(){ return sprites; }
        const char* getBackground(){ return background; }
        ~Level(){} //TODO: HANDLEDNING, vill jag ens göra nåt här?
    private:
        const char* background;
        std::vector<Sprite*> sprites;
    };
}

#endif //GAMEENGINE_LEVEL_H
