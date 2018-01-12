#include "Level.h"

namespace gameEngine{

    Level* Level::getInstance(const char *background, std::vector<Sprite *> sprites) {
        return new Level(background, sprites);
    }
    Level::Level(const char* background, std::vector<Sprite*> sprites) :
            background(background), sprites(sprites){}

    Level::~Level() {
        std::cout << "Delete level" << std::endl;
    }
}
