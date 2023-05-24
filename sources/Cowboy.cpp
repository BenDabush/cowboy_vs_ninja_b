#include "Cowboy.hpp"
#include <iostream>

using namespace ariel;

Cowboy::Cowboy(const std::string& name, const Point& location)
    : Character(name, location, 110), bullets(6) {}

void Cowboy::shoot(Character* enemy) {
    if(!enemy->isAlive()){
        throw std::runtime_error("runtime error: You can't shoot a dead person, it's immoral :(");
    }
    if(!this->isAlive()){
        throw std::runtime_error("runtime error: You can't shoot a person if your dead");
    }
    if(this == enemy){
        throw std::runtime_error("runtime error: It's not okay to shoot yourself");
    }
    if (bullets > 0) {
        enemy->hit(10);
        bullets--;
    }
}

bool Cowboy::hasboolets() const {
    return bullets > 0;
}

void Cowboy::reload() {
    if(!this->isAlive()){
        throw std::runtime_error("runtime error: You can't reload if your dead");
    }
    bullets = 6;
    // std::cout << getName() << " reloads." << std::endl;
}

// Prints the character's details (name, hit points, and location)
void Cowboy::print() const
{
    if(isAlive()){
        std::cout << "C " << this->getName() << ": " << this->getCharacterHP() << " HP, ";
        this->getLocation().print();
        std::cout << "\n";
    }
    else{
        std::cout  << "C " << "(" << this->getName() << "): ";
        this->getLocation().print();
        std::cout << "\n";
    }
}
