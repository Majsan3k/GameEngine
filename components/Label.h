#ifndef GAMEENGINE_LABEL_H
#define GAMEENGINE_LABEL_H
#include <string>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_ttf.h>
#include "Sprite.h"

namespace game {
    class Label : public Sprite {

    public:
        static Label* getInstance(SDL_Rect, std::string);
        void tick(const Uint8*, GameEngine&);
        void draw();
        const std::string getText(){return text;}
        void setText(std::string);
        ~Label();

    protected:
        Label(SDL_Rect&, std::string);
    private:
        std::string text;
        TTF_Font* font;
        SDL_Texture* labelTexture;

    };
}


#endif //GAMEENGINE_LABEL_H
