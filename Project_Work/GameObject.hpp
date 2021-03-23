#pragma once
#include "TreasureHuntingLib.h"

class GameObject {
private:
    char _symbol; // holds symbols of the GameObject
public:
    //constructors
    GameObject(char symbol);
    //getters setters
    char getSymbol();
};
