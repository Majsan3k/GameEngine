#ifndef GAMEENGINE_PLAYER_H
#define GAMEENGINE_PLAYER_H
#include <SDL2/SDL_system.h>
#include "Sprite.h"

namespace game {
    class Player : public Sprite {
    public:
        static Player* getInstance(SDL_Rect);
        void tick(const Uint8*, GameEngine&);
        bool collision(Sprite*);
//        void mouseButtonDown(const SDL_Event&);
//        void mouseButtonUp(const SDL_Event&);
//        void mouseMotion(const SDL_Event);
        void draw();
        ~Player();

    protected:
        Player(SDL_Rect&);
    private:
        bool active;
        SDL_Texture* playerTexture;
    };
}
#endif //GAMEENGINE_PLAYER_H
