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

/* Players */
Movable* player1;
Movable* player2;

/* Immobile sprites */
Label* inputField1;
Label* points1;
Label* inputField2;
Label* points2;
Button* soundButton;

void test(){
    cout << "Free function" << endl;
}

void initialize(){

    /* Initialize media */
    const char* playerPic = "C:/MediaProg3/hat.png";
    const char* btnPicFront = "C:/MediaProg3/soundOn.png";
    const char* btnPicBack = "C:/MediaProg3/soundOff.png";

    /* Initizialize immobile sprites */
    inputField1 = Label::getInstance({5, 5, 100, 40}, "Player 1", "C:/Windows/Fonts/Arial.ttf", 20, true, 10);
    points1 = Label::getInstance({5, 30, 40, 40}, "0", "C:/Windows/Fonts/Arial.ttf", 20, false, 1);
    inputField2 = Label::getInstance({5, 60, 100, 40}, "Player 2", "C:/Windows/Fonts/Arial.ttf", 20, true, 10);
    points2 = Label::getInstance({5, 85, 40, 40}, "0", "C:/Windows/Fonts/Arial.ttf", 20, false, 1);
    soundButton = SoundButton::getInstance({650, 10, 40, 40}, btnPicFront, btnPicBack, false);

    /* Initialize players */
    player1 = Player::getInstance({50, 500, 80, 60}, *points1, playerPic, 5);
    player2 = Player::getInstance({400, 500, 80, 60}, *points2, playerPic, 5,
                                  SDL_SCANCODE_D, SDL_SCANCODE_A, SDL_SCANCODE_W, SDL_SCANCODE_S);
}

Level* setUpFirstLevel(){
    vector<Sprite*> sprites;
    const char* bg = "C:/MediaProg3/bg1.jpg";
    const char* elephantPic1 = "C:/MediaProg3/elephant1.jpg";
    const char* elephantPic2 = "C:/MediaProg3/elephant2.jpg";
    const char* animated = "C:/MediaProg3/spritesheet.png";


    try {
        /* Initialize movable items level 1 */
        Item *elephant = Item::getInstance({200, 1, 100, 100}, elephantPic1, 2, false);
        Item *elephant1 = Item::getInstance({70, 10, 50, 50}, elephantPic2, 1, false);
        Item *elephant2 = Item::getInstance({10, 80, 50, 50}, elephantPic1, 1, false);
        Item *elephant3 = Item::getInstance({500, 22, 50, 50}, elephantPic2, 1, false);
        Item *elephant4 = Item::getInstance({450, 0, 50, 50}, elephantPic1, 1, false);
        Item *elephant5 = Item::getInstance({300, 0, 50, 50}, elephantPic2, 1, false);
        Item *human = Item::getAnimatedInstance({150, 0, 128, 64}, animated, 4, 200, -1, false);
        Item *human2 = Item::getAnimatedInstance({400, 10, 128, 64}, animated, 4, 200, -1, false);
        Item *human3 = Item::getAnimatedInstance({600, 0, 128, 64}, animated, 4, 200, -1, false);

        sprites.push_back((Sprite *) soundButton);
        sprites.push_back((Sprite *) player1);
        sprites.push_back((Sprite *) points1);
        sprites.push_back((Sprite *) inputField1);
        sprites.push_back((Sprite *) player2);
        sprites.push_back((Sprite *) points2);
        sprites.push_back((Sprite *) inputField2);
        sprites.push_back((Sprite *) elephant);
        sprites.push_back((Sprite *) elephant1);
        sprites.push_back((Sprite *) elephant2);
        sprites.push_back((Sprite *) elephant3);
        sprites.push_back((Sprite *) elephant4);
        sprites.push_back((Sprite *) elephant5);
        sprites.push_back((Sprite *) human);
        sprites.push_back((Sprite *) human2);
        sprites.push_back((Sprite *) human3);
    }catch(runtime_error e){
    cerr << e.what() << endl;
    }

    return Level::getInstance(bg, sprites);
}

Level* setupSecondLevel(){
    vector<Sprite*> sprites;
    const char* bg = "C:/MediaProg3/bg2.png";
    const char* fishPic1 = "C:/MediaProg3/fish1.jpg";
    const char* fishPic2 = "C:/MediaProg3/fish2.jpg";
    const char* sharkPic = "C:/MediaProg3/shark1.png";
    const char* sharkPic2 = "C:/MediaProg3/shark2.png";
    const char* animatedShark = "C:/MediaProg3/sharkSpritesheet.png";

    try {
        Item *fish1 = Item::getInstance({650, 1, 80, 80}, fishPic1, 2, true);
        Item *fish2 = Item::getInstance({0, 250, 80, 80}, fishPic2, 2, true);
        Item *fish3 = Item::getInstance({400, 400, 80, 80}, fishPic1, 2, true);
        Item *fish4 = Item::getInstance({200, 40, 80, 80}, fishPic2, 2, true);
        Item *fish5 = Item::getInstance({300, 300, 80, 80}, fishPic1, 2, true);
        Item *fish6 = Item::getInstance({300, 300, 80, 80}, fishPic2, 2, true);

        Item *shark1 = Item::getInstance({50, 30, 128, 64}, sharkPic, -3, true);
        Item *shark2 = Item::getInstance({80, 150, 128, 64}, sharkPic2, -3, true);
        Item *shark3 = Item::getInstance({500, 250, 128, 64}, sharkPic, -3, true);
        Item *shark4 = Item::getInstance({80, 350, 128, 64}, sharkPic2, -3, true);
        Item *shark5 = Item::getAnimatedInstance({20, 80, 480, 100}, animatedShark, 4, 500, -4, true);

        sprites.push_back((Sprite *) soundButton);
        sprites.push_back((Sprite*)player1);
        sprites.push_back((Sprite*)points1);
        sprites.push_back((Sprite*)inputField1);
        sprites.push_back((Sprite*)player2);
        sprites.push_back((Sprite*)points2);
        sprites.push_back((Sprite*)inputField2);
        sprites.push_back((Sprite*)fish1);
        sprites.push_back((Sprite*)fish2);
        sprites.push_back((Sprite*)fish3);
        sprites.push_back((Sprite*)fish4);
        sprites.push_back((Sprite*)fish5);
        sprites.push_back((Sprite*)fish6);
        sprites.push_back((Sprite*)shark1);
        sprites.push_back((Sprite*)shark2);
        sprites.push_back((Sprite*)shark3);
        sprites.push_back((Sprite*)shark4);
        sprites.push_back((Sprite*)shark5);
    }catch(runtime_error e){
        cerr << e.what() << endl;
    }

    return Level::getInstance(bg, sprites);

}

int main() {
    const char* music = "C:/MediaProg3/music.mp3";
    unordered_map<int, Level*> levels;
    initialize();

    /* Create levels */
    Level* first = setUpFirstLevel();
    Level* second = setupSecondLevel();

    /* Add levels to level map */
    levels.insert(make_pair(1, first));
    levels.insert(make_pair(2, second));

    /* Create function map. Added test function just to see so it works
     * to use free functions in the game*/
    unordered_map<unsigned, std::function<void()>> funcs;
    std::function<void()> testfunc = test;
    funcs.insert(make_pair(SDLK_DOWN, testfunc));

    /* Create game engine and start it*/
    GameEngine gameEngine(levels, funcs);
    std::function<void()> pause = std::bind(&GameEngine::setPaused, &gameEngine);
    gameEngine.addShortcut(SDLK_RETURN, pause);
//    gameEngine.run(60, music, true, 1);
    //TODO: Ta bort denna, musiken ska vara på!
    gameEngine.run(60, music, false, 1);

    return 0;
}