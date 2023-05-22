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
    public:
        // Constructor
        Team(Character* leader);

        // // Destructor
        // ~Team();

        // Adds a fighter (cowboy or ninja) to the group
        void add(Character* fighter);

        // Attacks the enemy group
        void attack(Team* enemyGroup);

        // Checks if the group is still alive (number of members left alive)
        int stillAlive() const;

        // Prints the details of all characters in the group
        void print() const;

    private:
        Character* m_leader;
        std::vector<Character*> m_fighters;
    };

    class Team2 {
    public:
        // Constructor
        Team2(Character* leader);

        // // Destructor
        // ~Team2();

        // Adds a fighter (cowboy or ninja) to the group
        void add(Character* fighter);

        // Attacks the enemy group
        void attack(Team2* enemyGroup);

        // Checks if the group is still alive (number of members left alive)
        int stillAlive() const;

        // Prints the details of all characters in the group
        void print() const;

    private:
        Character* m_leader;
        std::vector<Character*> m_fighters;
    };

    class SmartTeam {
    public:
        // Constructor
        SmartTeam(Character* leader);

        // // Destructor
        // ~SmartTeam();

        // Adds a fighter (cowboy or ninja) to the group
        void add(Character* fighter);

        // Attacks the enemy group
        void attack(SmartTeam* enemyGroup);

        // Checks if the group is still alive (number of members left alive)
        int stillAlive() const;

        // Prints the details of all characters in the group
        void print() const;

    private:
        Character* m_leader;
        std::vector<Character*> m_fighters;
    };
};
#endif // TEAM_HPP
