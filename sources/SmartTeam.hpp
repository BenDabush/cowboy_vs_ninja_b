#ifndef SMARTTEAM_HPP
#define SMARTTEAM_HPP

#include "Team.hpp"
 
namespace ariel{
    class SmartTeam : public Team {
    public:
        // Constructor
        SmartTeam(Character* leader);

        // // Destructor
        // ~SmartTeam();

        // Attacks the enemy group
        void attack(SmartTeam* enemyGroup);

        // Checks if the group is still alive (number of members left alive)
        int stillAlive() const;

        // Prints the details of all characters in the group
        void print() const;
    };
}
#endif // SMARTTEAM_HPP