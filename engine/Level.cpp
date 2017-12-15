#include "Level.h"

namespace gameEngine{

    Level::Level(const char* background, std::vector<Sprite*> sprites) :
            background(background), sprites(sprites){}
}
