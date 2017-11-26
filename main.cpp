#include <iostream>
#include "engine/GameEngine.h"
#include "components/Player.h"
#include "components/Item.h"

using namespace std;
using namespace game;

int main() {
    GameEngine gameEngine;
    Player* player = Player::getInstance({200, 250, 100, 100});
    Item* item = Item::getInstance({200, 1, 50, 50});
    gameEngine.add(player);
    gameEngine.add(item);
    gameEngine.run();
    return 0;
}