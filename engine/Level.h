#ifndef GAMEENGINE_LEVEL_H
#define GAMEENGINE_LEVEL_H
#include <vector>
#include "../components/Sprite.h"

namespace gameEngine {
    class Level {
    public:
        static Level* getInstance(const char* background, std::vector<Sprite*> sprites);
        std::vector<Sprite*> getSprites() { return sprites; }
        const char* getBackground(){ return background; }
        ~Level(){std::cout << "Delete level" << std::endl;}
    protected:
        Level(const char*, std::vector<Sprite*>);
    private:
        const char* background;
        std::vector<Sprite*> sprites;
    };
}

#endif //GAMEENGINE_LEVEL_H
