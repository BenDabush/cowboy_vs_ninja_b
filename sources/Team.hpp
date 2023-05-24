#ifndef TEAM_HPP
#define TEAM_HPP

#include "Character.hpp"
#include "Ninja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"
#include "Cowboy.hpp"
#include <vector>
namespace ariel{
    class Team {
    private:
        Character* leader;
        std::vector<Character*> fightersArray;
        int livingTeamMembers;
    
    public:
        // Constructor
        Team(Character* leader);

        // Destructor
        ~Team();

        std::vector<Character*> getFihtersArray() const;

        // Adds a fighter (cowboy or ninja) to the group
        void add(Character* fighter);

        // Attacks the enemy group
        void attack(Team* enemyGroup);

        // Checks if the group is still alive (number of members left alive)
        int stillAlive() const;

        // Prints the details of all characters in the group
        void print() const;
    };
};

#endif // TEAM_HPP