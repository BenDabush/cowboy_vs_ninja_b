#include "Character.hpp"
#include <cmath>
#include <iostream>

using namespace ariel;
// Constructor
Character::Character(const std::string& name, const Point& location, int characterHP)
    : characterName(name), characterLocation(location), characterHP(characterHP)
{}

// Returns the name of the character
std::string Character::getName() const {
    return characterName;
}

// Returns the location of the character
int Character::getCharacterHP() const {
    return characterHP;
}

// Returns the location of the character
Point Character::getLocation() const {
    return characterLocation;
}

void Character::setLocation(Point newLocation){
    this->characterLocation = newLocation;
}

void Character::setHitPoints(int hitPoint){
    this->characterHP = hitPoint;
}

// Checks if the character is alive (has more than zero hit points)
bool Character::isAlive() const
{
    return characterHP > 0;
}

// Calculates the distance between this character and another character
double Character::distance(const Character* other) const
{
    return characterLocation.distance(other->characterLocation);
}

// Subtracts the specified amount of hit points from the character
void Character::hit(int amount) {
    if(characterHP == 0){
        throw std::runtime_error("runtime error: You can't hurt a character that's already dead");
    }
    characterHP = (characterHP - amount > 0) ? characterHP - amount : 0;
}

// Prints the character's details (name, hit points, and location)
void Character::print() const
{
    if(isAlive()){
        std::cout << characterName << ": " << characterHP << " HP, ";
        characterLocation.print();
    }
    else{
        std::cout << "(" << characterName << "): ";
        characterLocation.print();
    }
}


