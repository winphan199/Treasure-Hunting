#include "Position.hpp"

Position::Position() {
    this->_x = CONSTANT::getPositionX();
    this->_y = CONSTANT::getPositionY();
}
Position::Position(int x, int y) {
    this->_x = x;
    this->_y = y;
}

int Position::getX() const {
    return this->_x;
}
int Position::getY() const {
    return this->_y;
}

void Position::setX(int x) {
    this->_x = x;
}
void Position::setY(int y) {
    this->_y = y;
}

bool Position::operator == (Position& obj) {
    if (this->_x == obj._x && this->_y == obj._y) {
        return true;
    }
    else
        return false;
}
