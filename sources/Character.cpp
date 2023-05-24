#include "Character.hpp"
#include <cmath>
#include <iostream>

using namespace ariel;
// Constructor
Character::Character(const std::string& name, const Point& location, int characterHP)
    : characterName(name), characterLocation(location), characterHP(characterHP), inTeam(false)
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

bool Character::getInTeam() const{
    return inTeam;
}

void Character::setLocation(Point newLocation){
    this->characterLocation = newLocation;
}

void Character::setHitPoints(int hitPoint){
    this->characterHP = hitPoint;
}

void Character::setInTeam(bool inTeam){
    this->inTeam = inTeam;
}

// Checks if the character is alive (has more than zero hit points)
bool Character::isAlive() const
{
    // std::cout << "in isAlive" << "\n";
    // std::cout << "characterHP = " << characterHP << "\n";
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
    if(amount < 0){
        throw std::invalid_argument("invalid argument: You can't hurt a character with negative point drop lol");
    }
    characterHP = (characterHP - amount > 0) ? characterHP - amount : 0;
}

// Prints the character's details (name, hit points, and location)
void Character::print() const
{
    if(isAlive()){
        std::cout << characterName << ": " << characterHP << " HP, ";
        characterLocation.print();
        std::cout << "\n";
    }
    else{
        std::cout << "(" << characterName << "): ";
        characterLocation.print();
        std::cout << "\n";
    }
}


