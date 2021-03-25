#pragma once
#include "TreasureHuntingLib.h"
#include "Wall.h"
class Dungeon {
private:
    const int _width = CONSTANT::getDungeonWidth(); //this is the width of the dungeon
    const int _height = CONSTANT::getDungeonHeight(); //this is the height of the dungeon
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
