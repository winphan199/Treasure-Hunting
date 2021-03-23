#pragma once
#include "TreasureHuntingLib.h"
#include "Constant.hpp"
class GameObject {
private:
    char _symbol; // holds symbol of the GameObject
public:
    //constructors
    GameObject(char symbol);
    //getters setters
    char getSymbol();
};
