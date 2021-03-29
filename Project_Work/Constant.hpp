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
    
    //default position
    static const int _POS_X = 0;
    static const int _POS_Y = 0;
    
    //player default energy
    static const int _PLAYER_ENERGY = 100;
    
    //player points for specific events
    static const int _POINTS_GEM = 5;
    static const int _POINTS_MONSTER = 100;
    static const int _POINTS_APPLE = 2;
    static const int _POINTS_PASS = 500;
    
    //energy decreases for moving in specific level
    static const int _ENERGY_LOST_1ST = 1;
    static const int _ENERGY_LOST_2ND = 2;
    static const int _ENERGY_LOST_3RD = 3;
    static const int _ENERGY_LOST_4TH = 4;
    static const int _ENERGY_LOST_5TH = 5;
    static const int _ENERGY_LOST_6TH = 6;
    static const int _ENERGY_LOST_7TH = 7;
    static const int _ENERGY_LOST_8TH = 8;
    static const int _ENERGY_LOST_9TH = 8;
    static const int _ENERGY_LOST_10TH = 8;
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
    
    static int getPositionX() {
        return _POS_X;
    }
    static int getPositionY() {
        return _POS_Y;
    }
    
    static int getPlayerEnergy() {
        return _PLAYER_ENERGY;
    }
    
    static int getPointsGem() {
        return _POINTS_GEM;
    }
    static int getPointsMonster() {
        return _POINTS_MONSTER;
    }
    static int getPointsApple() {
        return _POINTS_APPLE;
    }
    static int getPointsPass() {
        return _POINTS_PASS;
    }
    
    static int getEnergyLost1st() {
        return _ENERGY_LOST_1ST;
    }
    static int getEnergyLost2nd() {
        return _ENERGY_LOST_2ND;
    }
    static int getEnergyLost3rd() {
        return _ENERGY_LOST_3RD;
    }
    static int getEnergyLost4th() {
        return _ENERGY_LOST_4TH;
    }
    static int getEnergyLost5th() {
        return _ENERGY_LOST_5TH;
    }
    static int getEnergyLost6th() {
        return _ENERGY_LOST_6TH;
    }
    static int getEnergyLost7th() {
        return _ENERGY_LOST_7TH;
    }
    static int getEnergyLost8th() {
        return _ENERGY_LOST_8TH;
    }
    static int getEnergyLost9th() {
        return _ENERGY_LOST_9TH;
    }
    static int getEnergyLost10th() {
        return _ENERGY_LOST_10TH;
    }
};
