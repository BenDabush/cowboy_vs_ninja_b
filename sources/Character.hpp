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

            // Getters
            std::string getName() const;
            Point getLocation() const;
            int getCharacterHP() const;

            //Setters 
            void setLocation(Point newLocation);
            void setHitPoints(int hitPoint);

            // Checks if the character is alive (has more than zero hit points)
            bool isAlive() const;

            // Calculates the distance between this character and another character
            double distance(const Character* other) const;

            // Subtracts the specified amount of hit points from the character
            void hit(int amount);

            // Prints the character's details (name, hit points, and location)
            virtual void print() const;
    };
};
#endif // CHARACTER_HPP
