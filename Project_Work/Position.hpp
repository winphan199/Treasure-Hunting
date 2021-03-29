#pragma once
#include "TreasureHuntingLib.h"

class Position {
private:
    int _x; // holds x coordinate
    int _y; // holds y coordinate
public:
    //constructors
    Position();
    Position(int x, int y);
    
    //getters, setters
    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);
    
    //overload operator
    bool operator == (Position& obj);
};
