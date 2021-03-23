#include "GameObject.hpp"

GameObject::GameObject(char symbol) {
    this->_symbol = symbol;
}

char GameObject::getSymbol() {
    return this->_symbol;
}
