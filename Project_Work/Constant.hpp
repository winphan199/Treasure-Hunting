#pragma once

class CONSTANT {
private:
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
    
    //max level of the dungeon
    static const int _MAXLEVEL = 10;
    
public:
    //getters
    static char getPlayer() {
        return _PLAYER;
    }
    static char getWall() {
        return _WALL;
    }
    static char getSpot() {
        return _SPOT;
    }
    static char getMonster() {
        return _MONSTER;
    }
    static char getGem() {
        return _GEM;
    }
    static char getApple() {
        return _APPLE;
    }
    static char getSecretPassage() {
        return _SECRET_PASSAGE;
    }
    
    static int getDungeonWidth() {
        return _WIDTH;
    }
    static int getDungeonHeight() {
        return _HEIGHT;
    }
    
    static int getMaxLevel() {
        return _MAXLEVEL;
    }
};
