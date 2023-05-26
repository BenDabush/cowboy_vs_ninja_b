#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Point.hpp"
#include <string>

namespace ariel {
    class Character {
    private:
        std::string characterName;
        Point characterLocation;
        int characterHP;
        bool inTeam;
    public:
        // Constructor
        Character(const std::string& characterName, const Point& characterLocation, int characterHP);

        // Destructor
        virtual ~Character();

        // Getters
        std::string getName() const;
        Point getLocation() const;
        int getCharacterHP() const;
        bool getInTeam() const;

        // Setters
        void setLocation(Point newLocation);
        void setHitPoints(int hitPoint);
        void setInTeam(bool inTeam);

        // Checks if the character is alive (has more than zero hit points)
        bool isAlive() const;

        // Calculates the distance between this character and another character
        double distance(const Character* other) const;

        // Subtracts the specified amount of hit points from the character
        void hit(int amount);

        // Prints the character's details (name, hit points, and location)
        // virtual void print() const;

        virtual char* print();

        Character(const Character &);
        Character &operator=(const Character &); 
        Character(Character &&) = delete;
        Character &operator=(Character &&) = delete; 
    };
} // namespace ariel

#endif // CHARACTER_HPP
