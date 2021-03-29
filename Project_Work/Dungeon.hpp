#pragma once
#include "TreasureHuntingLib.h"
#include "Wall.h"
#include "Player.hpp"
#include "Gem.hpp"
#include "Monster.hpp"
#include "Apple.hpp"
class Dungeon {
private:
    const int _width = CONSTANT::getDungeonWidth(); //this is the width of the dungeon
    const int _height = CONSTANT::getDungeonHeight(); //this is the height of the dungeon
    char *_map; //this is the dungeon
public:
    //constructors
    Dungeon();
    //behaviors
    void setLevel(int level, vector<Gem>& g_arr, vector<Monster>& m_arr, vector<Apple>& a_arr);
    void printDungeon();
    void push(GameObject& obj);
    char at(int x, int y);
    void remove(int x, int y);
    //destructor
    ~Dungeon();
};
