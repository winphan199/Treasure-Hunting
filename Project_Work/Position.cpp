#include "Position.hpp"

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
void Position::setPosition(int x, int y) {
    this->_x = x;
    this->_y = y;
}
