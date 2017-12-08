#ifndef GAMEENGINE_BUTTON_H
#define GAMEENGINE_BUTTON_H
#include "../engine/GameEngine.h"

namespace gameEngine {
    class Button : public Sprite {
    public:
        static Button* getInstance(SDL_Rect);
        void tick(const Uint8*, GameEngine&);
        void draw();
        void mouseButtonUp(SDL_Event&, GameEngine&);
        void mouseButtonDown(SDL_Event&);
        ~Button();
    protected:
        Button(SDL_Rect&);
    private:
        bool isDown = false;
        bool soundOn = true;
        SDL_Texture* soundOnIcon, *soundOffIcon;
    };
}


#endif //GAMEENGINE_BUTTON_H
