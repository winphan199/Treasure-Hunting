#include "Gem.hpp"

Gem::Gem(int x, int y) : GameObject(CONSTANT::getGem(), x, y) {
    _gemCount++;
}

int Gem::interact() {
    return 0;
}

int Gem::getGemNum() {
    return _gemCount;
}
