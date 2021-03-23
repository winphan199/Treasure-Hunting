#pragma once
#include "TreasureHuntingLib.h"

class CONSTANT {
public:
    //symbols of the game
    //(@=player, X=wall, $=gem, m=monster, a=apple, E=secret passage to next level)
    static const char _PLAYER = '@';
    static const char _WALL = 'X';
    static const char _SPOT = '.';
    static const char _GEM = '$';
    static const char _MONSTER = 'm';
    static const char _APPLE = 'a';
    static const char _SECRET_PASSAGE = 'E';
    
    //size of the dungeon
    static const int _WIDTH = 13;
    static const int _HEIGHT = 8;
};
