#include "Apple.hpp"

Apple::Apple(int x, int y, int energy) : GameObject(CONSTANT::getApple(), x, y) {
    _energy = energy;
}

int Apple::interact() {
    return _energy;
}
