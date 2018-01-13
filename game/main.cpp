//TODO: Se över minnesläckage i hela programmet!!!
//TODO: Skriv README

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

    const char* music = "C:/MediaProg3/music.mp3";
    const char* backgroundPic = "C:/MediaProg3/bg.jpg";
    const char* playerPic = "C:/MediaProg3/hat.png";
    const char* elephantPic = "C:/MediaProg3/elephant.jpg";
    const char* btnPicFront = "C:/MediaProg3/soundOn.png";
    const char* btnPicBack = "C:/MediaProg3/soundOff.png";
    const char* animated = "C:/MediaProg3/spritesheet.png";

    Movable* player1;
    Label* inputField1;
    Label* points1;

    Movable* player2;
    Label* inputField2;
    Label* points2;
    Item* elephant;
    Item* elephant1;
    Item* elephant2;
    Item* elephant3;
    Item* human;
    Button* soundButton;

    try {
        inputField1 = Label::getInstance({5, 5, 100, 40}, "Player 1", "C:/Windows/Fonts/Arial.ttf", 20, true, 10);
        points1 = Label::getInstance({5, 30, 40, 40}, "0", "C:/Windows/Fonts/Arial.ttf", 20, false, 1);
        inputField2 = Label::getInstance({5, 60, 100, 40}, "Player 2", "C:/Windows/Fonts/Arial.ttf", 20, true, 10);
        points2 = Label::getInstance({5, 85, 40, 40}, "0", "C:/Windows/Fonts/Arial.ttf", 20, false, 1);
        player1 = Player::getInstance({50, 250, 80, 60}, *points1, playerPic, 5);
        player2 = Player::getInstance({400, 250, 80, 60}, *points2, playerPic, 5,
                                     SDL_SCANCODE_D, SDL_SCANCODE_A, SDL_SCANCODE_W, SDL_SCANCODE_S);
        elephant = Item::getInstance({200, 1, 50, 50}, elephantPic, 1);
        elephant1 = Item::getInstance({70, 10, 50, 50}, elephantPic,1);
        elephant2 = Item::getInstance({10 , 10, 50, 50}, elephantPic,1);
        elephant3 = Item::getInstance({317, 22, 50, 50}, elephantPic,1);
        soundButton = SoundButton::getInstance({650, 10, 40, 40}, btnPicFront, btnPicBack, false);
        human = Item::getAnimatedInstance({150, 0, 128, 64}, animated, 4, 200,-1);

        /* Prepare activeSprites for level 1 */
        sprites1.push_back((Sprite*)player1);
        sprites1.push_back((Sprite*)points1);
        sprites1.push_back((Sprite*)inputField1);
        sprites1.push_back((Sprite*)player2);
        sprites1.push_back((Sprite*)points2);
        sprites1.push_back((Sprite*)inputField2);
        sprites1.push_back((Sprite*)elephant);
        sprites1.push_back((Sprite*)elephant1);
        sprites1.push_back((Sprite*)elephant2);
        sprites1.push_back((Sprite*)elephant3);
        sprites1.push_back((Sprite*)soundButton);
        sprites1.push_back((Sprite*)human);

        /* Prepare activeSprites for level 2 */
        sprites2.push_back((Sprite*)player1);
        sprites2.push_back((Sprite*)points1);
        sprites2.push_back((Sprite*)player2);
        sprites2.push_back((Sprite*)points2);

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
    std::function<void()> pause = std::bind(&GameEngine::setPaused, &gameEngine);
    gameEngine.addShortcut(SDLK_SPACE, pause);
//    gameEngine.run(60, music, true, 1);
    //TODO: Ta bort denna, musiken ska vara på!
    gameEngine.run(60, music, false, 1);

    return 0;
}