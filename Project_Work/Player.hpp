#pragma once
#include "GameObject.hpp"
#include "MovableInterface.h"
#include "Entrance.hpp"
class Player : public GameObject, public MovableInterface
{
private:
    int _energy;
public:
    //constructors
    Player(int x, int y);
    //getters setters
    int getEnergy() const;
    void setEnergy(int energy);
    
    //behaviors
    void setPosition(int x, int y) override;
    void move(string direction);
    int interact() override;
    int meet(GameObject &obj);
    bool isKilled(GameObject &obj);
  //  void meet(Entrance &e);
};
