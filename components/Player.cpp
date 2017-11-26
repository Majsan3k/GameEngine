#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Player.h"
#include "../frame/Frame.h"
#include "../engine/GameEngine.h"

using namespace std;

namespace game {

    Player* Player::getInstance(SDL_Rect spritePicture) {
        return new Player(spritePicture);
    }

    Player::Player(SDL_Rect& spritePicture) : Sprite(spritePicture) {
        SDL_Surface* playerPic = IMG_Load("C:/Users/majal/Documents/Prog3/Inlupp/test.png");
//        Uint32 white = SDL_MapRGB(playerPic->format, 255, 255, 255);
//        SDL_SetColorKey(playerPic, SDL_ENABLE, white);

        playerTexture = SDL_CreateTextureFromSurface(frame.getRen(), playerPic);
        SDL_FreeSurface(playerPic);
    }

    void Player::tick(const Uint8 *state, GameEngine &engine){
        if (state[SDL_SCANCODE_RIGHT]) {
            spriteRect.x++;
        }
        if(state[SDL_SCANCODE_LEFT]){
            spriteRect.x--;
        }
        if(state[SDL_SCANCODE_DOWN]){
            spriteRect.y++;
        }
        if(state[SDL_SCANCODE_UP]){
            spriteRect.y--;
        }if(state[SDL_SCANCODE_DELETE]){
            engine.remove(this);
        }
    }

    bool Player::collision(Sprite*) {
        return true;
    }

    void Player::draw() {
        SDL_RenderCopy(frame.getRen(), playerTexture, NULL, &spriteRect);
    }

    Player::~Player(){
        SDL_DestroyTexture(playerTexture);
    }
}