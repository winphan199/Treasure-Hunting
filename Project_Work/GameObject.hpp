#pragma once
#include "TreasureHuntingLib.h"
class GameObject {
private:
    char _symbol; // holds symbol of the GameObject
public:
    //constructors
    GameObject(char symbol);
    //getters setters
    char getSymbol();
};
