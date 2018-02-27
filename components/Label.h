#ifndef GAMEENGINE_LABEL_H
#define GAMEENGINE_LABEL_H
#include <string>
#include <SDL2/SDL_ttf.h>
#include "Sprite.h"

namespace gameEngine {
    class Label : public Sprite {

    public:
        static Label* getInstance(SDL_Rect rect , std::string txt, const char* fontSrc, int fontSize, bool editable, int maxLength);
        void tick(const Uint8*, GameEngine&){}
        void draw(Uint32);
        const std::string getText() const {return text;}
        const bool getEditable() const {return editable;}
        void setText(std::string);
        void setDefaultText();
        int getMaxLength() const {return maxTextLength;}
        ~Label();
    protected:
        Label(SDL_Rect& rect, std::string txt, const char* fontSrc, int fontsize, bool editable, int maxLength);
    private:
        std::string text;
        std::string defaultText;
        TTF_Font* font;
        SDL_Texture* labelTexture;
        bool editable;
        int maxTextLength;
    };
}
#endif //GAMEENGINE_LABEL_H
