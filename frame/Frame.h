#ifndef GAMEENGINE_SYSTEM_H
#define GAMEENGINE_SYSTEM_H
#include <SDL2/SDL_render.h>

namespace gameEngine {

    class Frame {
    public:
        Frame();
        SDL_Renderer *getRen() { return ren; }
        int getWidth(){ return SDL_GetWindowSurface(window)->w; }
        int getHeight(){ return SDL_GetWindowSurface(window)->h; }
        ~Frame();
    private:
        SDL_Window *window;
        SDL_Renderer *ren;
    };

    extern Frame frame;
}
#endif //GAMEENGINE_SYSTEM_H

