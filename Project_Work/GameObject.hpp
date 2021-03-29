#pragma once
#include "TreasureHuntingLib.h"
#include "Position.hpp"
class GameObject {
private:
    char _symbol; // holds symbol of the GameObject
protected:
    //incase the derived classes want to change position
    Position _position;
public:
    //constructors
    GameObject(char symbol, int x, int y);
    //getters setters
    char getSymbol();
    Position getPosition() const;
    
    //behaviors
    virtual int interact() = 0;
};
