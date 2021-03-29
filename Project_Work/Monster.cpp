#include "Monster.hpp"

Monster::Monster(int x, int y, int strength) : GameObject(CONSTANT::getMonster(), x, y) {
    _strength = strength;
}
int Monster::interact() {
    return -_strength;
}
