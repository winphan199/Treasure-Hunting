#include "GamePlay.h"
vector<string> Logger::_records;
int Gem::_gemCount = 0;
int main() {
    GamePlay::gameLoop();
    getchar();
    getchar();
    return 0;
}
