
#include <SDL2/SDL_image.h>
#include "Button.h"
#include "../frame/Frame.h"
#include <iostream>
using namespace std;

namespace game{

    Button* Button::getInstance(SDL_Rect rect){
        return new Button(rect);
    }

    Button::Button(SDL_Rect& button) : Sprite(button){
        SDL_Surface* buttonSurf =  IMG_Load("C:/Users/majal/Documents/Prog3/Inlupp/soundOff.png");
        Uint32 white = SDL_MapRGB(buttonSurf->format, 255, 255, 255);
        SDL_SetColorKey(buttonSurf, SDL_ENABLE, white);

        soundOffIcon = SDL_CreateTextureFromSurface(frame.getRen(), buttonSurf);
        SDL_FreeSurface(buttonSurf);

        soundOnIcon = IMG_LoadTexture(frame.getRen(), "C:/Users/majal/Documents/Prog3/Inlupp/soundOn.png");
    }

    Button::~Button() {
        SDL_DestroyTexture(soundOnIcon);
        SDL_DestroyTexture(soundOffIcon);
    }


    //TODO: Ta bort soundOn-variabeln och bara kolla om knappen är nedtryckt?
    void Button::mouseButtonUp(SDL_Event& event, GameEngine& gameEngine) {
        SDL_Point p = {event.button.x, event.button.y};
        if(isDown && SDL_PointInRect(&p, &spriteRect)){
            soundOn = !soundOn;
            isDown = false;
            gameEngine.playMusic(soundOn);
        }
    }

    void Button::mouseButtonDown(SDL_Event& event) {
        SDL_Point p = {event.button.x, event.button.y};
        if(SDL_PointInRect(&p, &spriteRect)){
            isDown = true;
        }
    }

    //TODO: Kolla på vad som egentligen ska göras här? När jag kollade om knappen var nedtryckt här kaosade det.
    void Button::tick(const Uint8* state, GameEngine& gameEngine){



//        if(SDL_GetMouseState(&x, &y) && SDL_BUTTON_LEFT){
//            soundOn = !soundOn;
//        }

        /*static bool press = false;
        SDL_Point point = {event.button.x, event.button.y};
        switch(event.type){

            case SDL_MOUSEBUTTONDOWN :
                if(SDL_PointInRect(&point, &spriteRect)){
                    soundOn = !soundOn;
                    press = true;
                }
                break;
            case SDL_MOUSEBUTTONUP :
                if(press && SDL_PointInRect(&point, &spriteRect)){
                    soundOn = !soundOn;
                    gameEngine.playMusic(soundOn);
                break;
                }

        }*/
    }

    //TODO: Ha detta i en subklass i min implementation?
    void Button::draw(){
        if(soundOn) {
            SDL_RenderCopy(frame.getRen(), soundOnIcon, NULL, &spriteRect);
        }else{
            SDL_RenderCopy(frame.getRen(), soundOffIcon, NULL, &spriteRect);
        }
    }
}
