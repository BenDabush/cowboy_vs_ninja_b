#include "Cowboy.hpp"
#include <iostream>

using namespace ariel;

Cowboy::Cowboy(const std::string& name, const Point& location)
    : Character(name, location, 110), bullets(6) {}

void Cowboy::shoot(Character* enemy) {
    if (bullets > 0 && enemy->isAlive()) {
        std::cout << getName() << " shoots " << enemy->getName() << "!" << std::endl;
        enemy->hit(10);
        bullets--;
    } else {
        std::cout << getName() << " can't shoot." << std::endl;
    }
}

bool Cowboy::hasBullets() const {
    return bullets > 0;
}

void Cowboy::reload() {
    bullets = 6;
    std::cout << getName() << " reloads." << std::endl;
}

// Prints the character's details (name, hit points, and location)
void Cowboy::print() const
{
    if(isAlive()){
        std::cout << "C " << this->getName() << ": " << this->getCharacterHP() << " HP, ";
        this->getLocation().print();
    }
    else{
        std::cout  << "C " << "(" << this->getName() << "): ";
        this->getLocation().print();
    }
}
