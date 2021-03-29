#include "GameObject.hpp"

GameObject::GameObject(char symbol, int x, int y) {
    this->_symbol = symbol;
    this->_position.setX(x);
    this->_position.setY(y);
}

char GameObject::getSymbol() {
    return this->_symbol;
}

Position GameObject::getPosition() const {
    return _position;
}
