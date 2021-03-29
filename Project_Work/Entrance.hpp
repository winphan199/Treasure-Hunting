#pragma once
#include "GameObject.hpp"

class Entrance : public GameObject
{
public:
    //constructor
    Entrance(int x, int y) : GameObject(CONSTANT::getSecretPassage(), x, y) {}

    //behavior
    int interact() override { 
        return 0;
    }
};
