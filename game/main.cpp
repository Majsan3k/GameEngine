#define SDL_MAIN_HANDLED
#include <iostream>
#include <functional>
#include "../engine/GameEngine.h"
#include "../components/Button.h"
#include "../components/Label.h"
#include "../components/Movable.h"
#include "Item.h"
#include "Player.h"
#include "SoundButton.h"
#include "../components/FuncTemplate.h"

using namespace std;
using namespace gameEngine;
using namespace myGame;


int main() {

    const char* music = "C:/Users/majal/Documents/Prog3/Inlupp/music.mp3";
    const char* backgroundPic = "C:/Users/majal/Documents/Prog3/Inlupp/bg.jpg";
    const char* playerPic = "C:/Users/majal/Documents/Prog3/Inlupp/hat.png";
    const char* elephantPic = "C:/Users/majal/Documents/Prog3/Inlupp/elephant.jpg";
    const char* btnPicFront = "C:/Users/majal/Documents/Prog3/Inlupp/soundOn.png";
    const char* btnPicBack = "C:/Users/majal/Documents/Prog3/Inlupp/soundOff.png";
    const char* animated = "C:/Users/majal/Documents/Prog3/Inlupp/spritesheet.png";

    Label* points;
    Movable* player;
    Item* elephant;
    Item* elephant1;
    Item* elephant2;
    Item* elephant3;
    Item* human;
    Button* soundButton;

    try {
        points = Label::getInstance({450, 10, 40, 40}, "0", "C:/Windows/Fonts/Arial.ttf");
        player = Player::getInstance({50, 250, 100, 100}, *points, playerPic);
        elephant = Item::getInstance({200, 1, 50, 50}, elephantPic, 1);
        elephant1 = Item::getInstance({70, 10, 50, 50}, elephantPic,1);
        elephant2 = Item::getInstance({10 , 10, 50, 50}, elephantPic,1);
        elephant3 = Item::getInstance({317, 22, 50, 50}, elephantPic,1);
        soundButton = SoundButton::getInstance({450, 60, 40, 40}, btnPicFront, btnPicBack);
        human = Item::getAnimatedInstance({150, 0, 128, 64}, animated, 4, 200,-1);
    }catch(runtime_error e){
        cerr << e.what() << endl;
    }

    GameEngine gameEngine;

    gameEngine.add(player);
//    gameEngine.add(elephant);
//    gameEngine.add(elephant1);
    gameEngine.add(elephant2);
    gameEngine.add(elephant3);
    gameEngine.add(human);
    gameEngine.add(points);
    gameEngine.add(soundButton);
    gameEngine.run(60, music, backgroundPic);


    return 0;
}