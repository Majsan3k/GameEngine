#define SDL_MAIN_HANDLED
#include <iostream>
#include "../engine/GameEngine.h"
#include "../components/Button.h"
#include "../components/Label.h"
#include "../components/Movable.h"
#include "Item.h"
#include "Player.h"

using namespace std;
using namespace gameEngine;
using namespace myGame;

int main() {
    GameEngine gameEngine;
    const char* music = "C:/Users/majal/Documents/Prog3/Inlupp/music.mp3";
    const char* backgroundPic = "C:/Users/majal/Documents/Prog3/Inlupp/bg.jpg";
    const char* playerPic = "C:/Users/majal/Documents/Prog3/Inlupp/hat.png";
    const char* elephant = "C:/Users/majal/Documents/Prog3/Inlupp/elephant.jpg";
    const char* btnPic = "C:/Users/majal/Documents/Prog3/Inlupp/soundOff.png";

    Label* points = Label::getInstance({450, 10, 40, 40}, "0");
    Movable* player = Player::getInstance({50, 250, 100, 100}, *points, playerPic);
    Item* item = Item::getInstance({200, 1, 50, 50}, elephant);
    Item* item1 = Item::getInstance({70, 10, 50, 50}, elephant);
    Item* item2 = Item::getInstance({10 , 10, 50, 50}, elephant);
    Item* item3 = Item::getInstance({317, 22, 50, 50}, elephant);
    Button* soundButton = Button::getInstance({450, 60, 40, 40}, btnPic);
//    Button* btn = Button::getInstance({450, 22, 50, 50});

    gameEngine.add(player);
    gameEngine.add(item);
    gameEngine.add(item1);
    gameEngine.add(item2);
    gameEngine.add(item3);
    gameEngine.add(points);
    gameEngine.add(soundButton);
    gameEngine.run(60, music, backgroundPic);
    return 0;
}