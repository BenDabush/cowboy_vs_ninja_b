#ifndef COWBOY_HPP
#define COWBOY_HPP

#include "Character.hpp"
#include "Point.hpp"
#include <string>
namespace ariel{

    class Cowboy : public Character {
    private:
        int m_bullets;

    public:
        // Constructor for Cowboy
        Cowboy(const std::string& name, const Point& location);

        // Shoots the enemy if the cowboy has bullets left
        void shoot(Character* enemy);

        // Checks if the cowboy has bullets left
        bool hasBullets() const;

        // Reloads the gun with six new bullets
        void reload();
    };
};
#endif // COWBOY_HPP