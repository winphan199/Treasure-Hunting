#include "Player.hpp"

Player::Player(int x, int y): GameObject(CONSTANT::getPlayer(), x, y) {
    _energy = CONSTANT::getPlayerEnergy();
}

int Player::getEnergy() const {
    return _energy;
}
void Player::setEnergy(int energy) {
    _energy = energy;
}

void Player::setPosition(int x, int y) {
    this->_position.setX(x);
    this->_position.setY(y);
}

void Player::move(string direction) {
    int vir_x = _position.getX();
    int vir_y = _position.getY();
    
    //player moves
    if (direction.compare("up") == 0) {
        vir_y--;
        this->_position.setY(vir_y);
    }
    else if (direction.compare("down") == 0) {
        vir_y++;
        this->_position.setY(vir_y);
    }
    else if (direction.compare("left") == 0) {
        vir_x--;
        this->_position.setX(vir_x);
    }
    else if (direction.compare("right") == 0) {
        vir_x++;
        this->_position.setX(vir_x);
    }
    else {
        
    }
}

int Player::interact() {
    return _energy;
}

int Player::meet(GameObject& obj) {
    _energy += obj.interact();
    return _energy;
}

bool Player::isKilled(GameObject& obj) {
    int energy_left = meet(obj);
    if (energy_left <= 0) {
        //run out of energy, then die
        return true;
    }
    return false;
}
