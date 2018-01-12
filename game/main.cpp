//TODO: Se över minnesläckage i hela programmet!!!

#define SDL_MAIN_HANDLED
#include <iostream>
#include "../engine/GameEngine.h"
#include "../components/Button.h"
#include "Player.h"
#include "SoundButton.h"

using namespace std;
using namespace gameEngine;
using namespace myGame;


void test(){
    cout << "test" << endl;
}

int main() {
    vector<char*> media;

    unordered_map<int, Level*> levels;
    vector<Sprite*> sprites1;
    vector<Sprite*> sprites2;

    const char* music = "C:/Users/majal/Documents/Prog3/Inlupp/music.mp3";
    const char* backgroundPic = "C:/Users/majal/Documents/Prog3/Inlupp/bg.jpg";
    const char* playerPic = "C:/Users/majal/Documents/Prog3/Inlupp/hat.png";
    const char* elephantPic = "C:/Users/majal/Documents/Prog3/Inlupp/elephant.jpg";
    const char* btnPicFront = "C:/Users/majal/Documents/Prog3/Inlupp/soundOn.png";
    const char* btnPicBack = "C:/Users/majal/Documents/Prog3/Inlupp/soundOff.png";
    const char* animated = "C:/Users/majal/Documents/Prog3/Inlupp/spritesheet.png";

    Label* points;
    Label* points2;
    Movable* player;
    Item* elephant;
    Item* elephant1;
    Item* elephant2;
    Item* elephant3;
    Item* human;
    Button* soundButton;

    try {
        points = Label::getInstance({450, 10, 40, 40}, "0", "C:/Windows/Fonts/Arial.ttf", false);
        points2 = Label::getInstance({50, 10, 200, 40}, "0", "C:/Windows/Fonts/Arial.ttf", true);
        player = Player::getInstance({50, 250, 100, 100}, *points, playerPic);
        elephant = Item::getInstance({200, 1, 50, 50}, elephantPic, 1);
        elephant1 = Item::getInstance({70, 10, 50, 50}, elephantPic,1);
        elephant2 = Item::getInstance({10 , 10, 50, 50}, elephantPic,1);
        elephant3 = Item::getInstance({317, 22, 50, 50}, elephantPic,1);
        soundButton = SoundButton::getInstance({450, 60, 40, 40}, btnPicFront, btnPicBack);
        human = Item::getAnimatedInstance({150, 0, 128, 64}, animated, 4, 200,-1);

        /* Prepare activeSprites for level 1*/
        sprites1.push_back((Sprite*)points);
        sprites1.push_back((Sprite*)points2);
        sprites1.push_back((Sprite*)player);
        sprites1.push_back((Sprite*)elephant);
        sprites1.push_back((Sprite*)elephant1);
        sprites1.push_back((Sprite*)elephant2);
        sprites1.push_back((Sprite*)elephant3);
        sprites1.push_back((Sprite*)soundButton);
        sprites1.push_back((Sprite*)human);

        /* Prepare activeSprites for level 2 */
        sprites2.push_back((Sprite*)player);
        sprites2.push_back((Sprite*)points);

    }catch(runtime_error e){
        cerr << e.what() << endl;
    }

    /* Create levels */
    Level* first = Level::getInstance(backgroundPic, sprites1);
    Level* second = Level::getInstance(elephantPic, sprites2);

    /* Add levels to level map */
    levels.insert(make_pair(1, first));
    levels.insert(make_pair(2, second));

    /* Create function map and game engine */
    unordered_map<unsigned, std::function<void()>> funcs;
    std::function<void()> testfunc = test;
    funcs.insert(make_pair(SDLK_DOWN, testfunc));


    /* Create game engine and start it*/
    GameEngine gameEngine(levels, funcs);
    std::function<void()> test2 = std::bind(&Item::test, human); //add shortcut to member function
//    std::function<void()> pause = std::bind(&GameEngine::setPaused, gameEngine);
//    gameEngine.addShortcut(SDLK_SPACE, pause);
    gameEngine.run(60, music, true, 1);


    //TODO: Ska detta göras i respektive klass istället?
    /* Remove all media */
    delete [] music;
    delete [] backgroundPic;
    delete [] playerPic;
    delete [] elephantPic;
    delete [] btnPicFront;
    delete [] btnPicBack;
    delete [] animated;

    return 0;
}