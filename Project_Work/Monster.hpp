#pragma once
#include "GameObject.hpp"

class Monster : public GameObject
{
private:
    int _strength; //holds strength of a monster that is used to subtract player energy
public:
    //constructors
    Monster(int x, int y, int strength);
    
    //behaviors
    int interact() override;
};
