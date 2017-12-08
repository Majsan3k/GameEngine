#ifndef GAMEENGINE_ITEM_H
#define GAMEENGINE_ITEM_H
#include "../engine/GameEngine.h"
#include "Sprite.h"

namespace game {
    class Item : public Sprite {
    public:
        static Item* getInstance(SDL_Rect);
        void tick(const Uint8*, GameEngine&);
        void draw();
        ~Item();



    protected:
        Item(SDL_Rect&);
    private:
        SDL_Texture* itemTexture;
    };
}

#endif //GAMEENGINE_ITEM_H
