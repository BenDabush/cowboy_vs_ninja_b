#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Point.hpp"
#include <string>
namespace ariel{
    class Character {
        private:
            std::string characterName;
            Point characterLocation;
            int characterHP;
        public:
            // Constructor
            Character(const std::string& characterName, const Point& characterLocation, int characterHP);

            // Checks if the character is alive (has more than zero hit points)
            bool isAlive() const;

            // Calculates the distance between this character and another character
            double distance(const Character* other) const;

            // Subtracts the specified amount of hit points from the character
            void hit(int amount);

            // Returns the name of the character
            std::string getName() const;

            // Returns the location of the character
            Point getLocation() const;

            // Returns the location of the character
            void setLocation(Point newLocation);

            // Returns the location of the character
            int getCharacterHP() const;

            void setHitPoints(int hitPoint);

            // Prints the character's details (name, hit points, and location)
            char print() const;
    };
};
#endif // CHARACTER_HPP
