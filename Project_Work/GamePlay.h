#pragma once
#include "TreasureHuntingLib.h"
#include "Logger.hpp"
#include "Dungeon.hpp"
#include "Player.hpp"
#include "Gem.hpp"

class GamePlay: protected Logger
{
private:
    static bool handleInteraction(Dungeon &dungeon, Player &player, vector<Gem>& g_arr, vector<Monster>& m_arr, vector<Apple>& a_arr, string direction, int &points, int level, int &gems, bool &iskilled);
    static int setEnergyLost(int level);
public:
	//constructors
    
	//behaviors
    static void gameLoop();
};
