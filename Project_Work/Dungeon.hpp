#pragma once
#include "TreasureHuntingLib.h"
#include "Constant.hpp"
#include "GameObject.hpp"
class Dungeon {
private:
    const int _width = CONSTANT::_WIDTH; //this is the width of the dungeon
    const int _height = CONSTANT::_HEIGHT; //this is the height of the dungeon
    char *_map; //this is the dungeon
public:
    //constructors
    Dungeon();
    //behaviors
    void setLevel(int level);
    void printDungeon();
    void push(GameObject& obj, int x, int y);
    //destructor
    ~Dungeon();
};
