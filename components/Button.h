#ifndef GAMEENGINE_BUTTON_H
#define GAMEENGINE_BUTTON_H
#include "../engine/GameEngine.h"

namespace gameEngine {
    class Button : public Sprite {
    public:
        virtual void perform(GameEngine&){}
        void tick(const Uint8* state, GameEngine& engine){}
        void draw(Uint32);
        void mouseButtonUp(GameEngine&);
        void mouseButtonDown();
        ~Button();
    protected:
        Button(SDL_Rect& rect, const char* frontPic, const char* backPic, bool active);
        /* active is protected to make it possible for sub classes
         * to change it */
        bool active;
    private:
        bool isDown = false;
        SDL_Texture* frontIcon, *backIcon;
        Button(const Button&) = delete;
        const Button& operator=(const Button&) = delete;
    };
}


#endif //GAMEENGINE_BUTTON_H
