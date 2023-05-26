#ifndef TEAM_HPP
#define TEAM_HPP

#include "Character.hpp"
#include "Ninja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"
#include "Cowboy.hpp"
#include <vector>
#include <iostream>

namespace ariel {
    class Team {
    private:
        Character* leader;
        std::vector<Character*> fightersArray;
    
    public:
        // Constructor
        Team(Character* leader);

        // Destructor
        virtual ~Team();

        Team(const Team &) = delete;
        Team &operator=(const Team &) = delete;
        Team(Team &&) = delete;
        Team &operator=(Team &&) = delete;

        std::vector<Character*>& getFightersArray();
        Character* getLeader();

        void setLeader(Character* newLeader);

        // Adds a fighter (cowboy or ninja) to the group
        virtual void add(Character* fighter);

        // Attacks the enemy group
        virtual void attack(Team* enemyGroup);

        // Checks if the group is still alive (number of members left alive)
        int stillAlive() const;

        // Prints the details of all characters in the group
        void print() const;
    };
}

#endif // TEAM_HPP
