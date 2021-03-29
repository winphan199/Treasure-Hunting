#pragma once
#include "Player.hpp"
class Apple : public GameObject
{
private:
    int _energy; //this is positive energy that is added to player
public:
    //constructor
    Apple(int x, int y, int energy);
    
    //behaviors
    int interact() override;
};
