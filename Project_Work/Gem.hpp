#pragma once
#include "GameObject.hpp"

class Gem : public GameObject
{
private:
    static int _gemCount;
    //Gem is like the key, it is needed to pass a level, but won't give player anything
public:
    //constructors
    Gem(int x, int y);
    
    //behaviors
    int interact() override;
    static int getGemNum();
};
