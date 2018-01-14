#ifndef GAMEENGINE_SOUNDBUTTON_H
#define GAMEENGINE_SOUNDBUTTON_H
#include<SDL2/SDL_rect.h>
#include "../engine/GameEngine.h"
#include "../components/Button.h"

using namespace gameEngine;

namespace myGame {
    class SoundButton : public Button{
    public:
        static SoundButton* getInstance(SDL_Rect rect, const char* frontIconSrc, const char* backIconSrc, bool active);
        void perform(GameEngine&) override;
    protected:
        SoundButton(SDL_Rect rect, const char* frontIconSrc, const char* backIconSrc, bool active);
    };
}
#endif //GAMEENGINE_SOUNDBUTTON_H