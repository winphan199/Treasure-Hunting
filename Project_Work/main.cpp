#include "Dungeon.hpp"
#include "GamePlay.h"
vector<string> Logger::_records;
int Gem::_gemCount = 0;
int main() {
    GamePlay::gameLoop();
    return 0;
}
