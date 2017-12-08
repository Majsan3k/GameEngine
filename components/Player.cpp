#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Player.h"
#include "../frame/Frame.h"
#include "../engine/GameEngine.h"
#include "Item.h"


using namespace std;

namespace game {

    Player* Player::getInstance(SDL_Rect spritePicture, Label& pointLabel) {
        return new Player(spritePicture, pointLabel);
    }

    Player::Player(SDL_Rect& spritePicture, Label& pointLbl) : Sprite(spritePicture), pointLabel(pointLbl) {
        SDL_Surface* playerPic = IMG_Load("C:/Users/majal/Documents/Prog3/Inlupp/hat.png");
//        Uint32 white = SDL_MapRGB(playerPic->format, 255, 255, 255);
//        SDL_SetColorKey(playerPic, SDL_ENABLE, white);

        playerTexture = SDL_CreateTextureFromSurface(frame.getRen(), playerPic);
        SDL_FreeSurface(playerPic);
    }

    //TODO: För specifik för generella delen?
    void Player::tick(const Uint8 *state, GameEngine &engine){

        static int point;
        std::vector<Sprite*> sprites = engine.getSprites();
        for(Sprite* sprite : sprites){
            if(sprite != this && dynamic_cast<Item*>(sprite) && collision(sprite)){
                point++;
                pointLabel.setText(to_string(point));
                engine.updateItemsToRemove(sprite);
            }
        }

        if (state[SDL_SCANCODE_RIGHT]) {
            spriteRect.x += 5;
        }
        if(state[SDL_SCANCODE_LEFT]){
            spriteRect.x -= 5;
        }
        if(state[SDL_SCANCODE_DOWN]){
            spriteRect.y += 5;
        }
        if(state[SDL_SCANCODE_UP]){
            spriteRect.y -= 5;
        }if(state[SDL_SCANCODE_DELETE]){
            engine.remove(this);
        }
    }

    void Player::draw() {
        SDL_RenderCopy(frame.getRen(), playerTexture, NULL, &spriteRect);
    }

    Player::~Player(){
        SDL_DestroyTexture(playerTexture);
    }
}