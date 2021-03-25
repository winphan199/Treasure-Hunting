#pragma once
#include "GameObject.hpp"

class Wall : public GameObject 
{
public:
	//constructor
	Wall() : GameObject(CONSTANT::getWall()) {}
};
