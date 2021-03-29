#pragma once
#include "GameObject.hpp"
#include "MovableInterface.h"

//Wall is a special class that we can create one just to push to dungeon, it can have multiple copies of itself.
//So setPosition is visible for wall.
class Wall : public GameObject, public MovableInterface
{
public:
	//constructor
	Wall(int x, int y) : GameObject(CONSTANT::getWall(), x, y) {}
    
    //behavior
    void setPosition(int x, int y) override {
        _position.setX(x);
        _position.setY(y);
    }
    int interact() override {
        return 0;
    }
};
