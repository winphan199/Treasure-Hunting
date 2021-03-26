#include "Dungeon.hpp"
#include "GameObject.hpp"
#include "GamePlay.h"
vector<string> Logger::_records;
int main() {
    GamePlay::gameLoop();
    return 0;
}
