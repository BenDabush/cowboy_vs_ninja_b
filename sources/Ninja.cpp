#include "Ninja.hpp"
#include <iostream>

using namespace ariel;

Ninja::Ninja(const std::string& name, const Point& location, int speed) : Character(name, location, 100), speed(speed)
{
    // Ninja starts with 100 hit points
}

void Ninja::move(Character* enemy)
{
    if (isAlive() && enemy != nullptr) {
        Point destination = enemy->getLocation();
        Point source = this->getLocation();
        Point newLocation = source.moveTowards(source, destination, speed);
        this->setLocation(newLocation);
    }
}

void Ninja::slash(Character* enemy){
    if(!enemy->isAlive()){
        throw std::runtime_error("runtime error: You can't slash a dead person, it's immoral :(");
    }
    if(!this->isAlive()){
        throw std::runtime_error("runtime error: You can't slash a person if your dead");
    }
    if(this == enemy){
        throw std::runtime_error("runtime error: It's not okay to slash yourself");
    }
    if (enemy != nullptr && distance(enemy) < 1.0) {
        enemy->hit(40);
    }
}

// Prints the character's details (name, hit points, and location)
void Ninja::print() const
{
    if(isAlive()){
        std::cout << "N " << this->getName() << ": " << this->getCharacterHP() << " HP, ";
        this->getLocation().print();
        std::cout << "\n";
    }
    else{
        std::cout  << "N " << "(" << this->getName() << "): ";
        this->getLocation().print();
        std::cout << "\n";
    }
}