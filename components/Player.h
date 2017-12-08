#ifndef GAMEENGINE_PLAYER_H
#define GAMEENGINE_PLAYER_H
#include <SDL2/SDL_system.h>
#include "Sprite.h"
#include "Label.h"

namespace game {
    class Player : public Sprite {
    public:
        static Player* getInstance(SDL_Rect, Label&);
        void tick(const Uint8*, GameEngine&);
        void draw();
        ~Player();

    protected:
        Player(SDL_Rect&, Label&);
    private:
        bool active;
        Label& pointLabel;
        SDL_Texture* playerTexture;
    };
}
#endif //GAMEENGINE_PLAYER_H
