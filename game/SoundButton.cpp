#include "SoundButton.h"

namespace myGame{

    //TODO: Gör klart klassen

    SoundButton* SoundButton::getInstance(SDL_Rect rect, const char* pictureSrc){
        return new SoundButton(rect, pictureSrc);
    }

    SoundButton::SoundButton(SDL_Rect rect, const char * pictureSrc) : Button(rect, pictureSrc) {


    }
}
