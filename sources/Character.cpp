#include "Character.hpp"
#include <cmath>
#include <iostream>

using namespace ariel;
// Constructor
Character::Character(const std::string& name, const Point& location, int characterHP)
    : characterName(name), characterLocation(location), characterHP(characterHP)
{}

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
    characterHP -= amount;
}

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

// Prints the character's details (name, hit points, and location)
char Character::print() const
{
    // std::cout << (isAlive() ? "" : "(") << (m_name[0] == 'N' ? "Ninja " : "Morning ") << m_name << ": " << m_hitPoints << " HP, ";
    // m_location.print();
    // std::cout << (isAlive() ? "" : ")");
    return 'a';
}


