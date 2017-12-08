#include <SDL2/SDL_image.h>
#include "../frame/Frame.h"
#include "../engine/GameEngine.h"
#include "../components/Movable.h"
#include <iostream>

using namespace game;
using namespace std;

namespace gameImpl{
    class Item : public Movable {

    public:
        Item(SDL_Rect rect) : Movable(rect) {}
        void changeState(const Uint8 *state, GameEngine &engine) override {
            spriteRect.y++;
        }
    };
}