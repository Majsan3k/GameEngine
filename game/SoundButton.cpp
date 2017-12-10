#include "SoundButton.h"

namespace myGame{

    //TODO: Gör klart klassen

    SoundButton* SoundButton::getInstance(SDL_Rect rect, const char* frontIconSrc, const char* backIconSrc){
        return new SoundButton(rect, frontIconSrc, backIconSrc);
    }

    SoundButton::SoundButton(SDL_Rect rect, const char * frontIconSrc, const char* backIconSrc) : Button(rect, frontIconSrc, backIconSrc) {
    }

    void SoundButton::perform(GameEngine& engine) {
        active = !active;
        engine.playMusic(active);
    }
}
