#include <SDL2/SDL_image.h>
#include "../frame/Frame.h"
#include "../engine/GameEngine.h"
#include "../components/Movable.h"

using namespace gameEngine;
using namespace std;

namespace myGame{
    class Item : public Movable {

    public:
        Item(SDL_Rect rect) : Movable(rect) {}
        void changeState(const Uint8 *state, GameEngine &engine) override {
            spriteRect.y++;
        }
    };
}