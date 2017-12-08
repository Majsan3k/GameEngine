#define SDL_MAIN_HANDLED
#include <iostream>
#include "../engine/GameEngine.h"
#include "../components/Item.h"
#include "../components/Button.h"
#include "../components/Label.h"
#include "../components/Movable.h"
#include "Player.cpp"

using namespace std;
using namespace game;
using namespace gameImpl;

class SoundBtn : public Button{
public:
    SoundBtn (SDL_Rect rect) : Button(rect){}
    void perform(GameEngine& engine, bool soundOn){
        engine.playMusic(soundOn);
    }
};

int main() {
    GameEngine gameEngine;
    Label* points = Label::getInstance({450, 10, 40, 40}, "0");

    Movable* player = new Player({50, 250, 100, 100});

    Item* item = Item::getInstance({200, 1, 50, 50});
    Item* item1 = Item::getInstance({70, 10, 50, 50});
    Item* item2 = Item::getInstance({10 , 10, 50, 50});
    Item* item3 = Item::getInstance({317, 22, 50, 50});
    Button* soundButton = new SoundBtn({450, 60, 40, 40});
//    Button* btn = Button::getInstance({450, 22, 50, 50});

    gameEngine.add(player);
    gameEngine.add(item);
    gameEngine.add(item1);
    gameEngine.add(item2);
    gameEngine.add(item3);
    gameEngine.add(points);
    gameEngine.add(soundButton);
    gameEngine.run(60);
    return 0;
}