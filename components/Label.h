#ifndef GAMEENGINE_LABEL_H
#define GAMEENGINE_LABEL_H
#include <string>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_ttf.h>
#include "Sprite.h"

namespace gameEngine {
    class Label : public Sprite {

    public:
        static Label* getInstance(SDL_Rect, std::string, const char*, bool);
        void tick(const Uint8*, GameEngine&){}
        void draw(Uint32);
        const std::string getText(){return text;}
        const bool getEditable(){return editable;}
        void setText(std::string);
        int getMaxLength(){return maxTextLength;}
        ~Label();

    protected:
        Label(SDL_Rect&, std::string, const char*, bool);
    private:
        std::string text;
        TTF_Font* font;
        SDL_Texture* labelTexture;
        bool editable = true;
        int maxTextLength;
    };
}


#endif //GAMEENGINE_LABEL_H
