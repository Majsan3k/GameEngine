#ifndef GAMEENGINE_BUTTON_H
#define GAMEENGINE_BUTTON_H
#include "../engine/GameEngine.h"

namespace gameEngine {
    class Button : public Sprite {
    public:
        virtual void perform(GameEngine&){}
        void tick(const Uint8*, GameEngine&){}
        void draw(Uint32);
        void mouseButtonUp(SDL_Event&, GameEngine&);
        void mouseButtonDown(SDL_Event&);
        ~Button();
    protected:
        Button(SDL_Rect&, const char*, const char*);
        bool active = true;
    private:
        bool isDown = false;
        SDL_Texture* frontIcon, *backIcon;
        Button(const Button&) = delete;
        const Button& operator=(const Button&) = delete;
    };
}


#endif //GAMEENGINE_BUTTON_H
