#include "SoundButton.h"

namespace myGame{

    SoundButton* SoundButton::getInstance(SDL_Rect rect, const char* frontIconSrc, const char* backIconSrc, bool active){
        return new SoundButton(rect, frontIconSrc, backIconSrc, active);
    }

    SoundButton::SoundButton(SDL_Rect rect, const char * frontIconSrc, const char* backIconSrc, bool active) :
            Button(rect, frontIconSrc, backIconSrc, active) {
    }

    void SoundButton::perform(GameEngine& engine) {
        active = !active;
        engine.playMusic(active);
    }
}
