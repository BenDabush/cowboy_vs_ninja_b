#ifndef TEAM2_HPP
#define TEAM2_HPP

#include "Team.hpp"

namespace ariel{
    class Team2 : public Team{
    public:
        // Constructor
        Team2(Character* leader);

        // Adds a fighter (cowboy or ninja) to the group
        void add(Character* fighter) override;

    };
};
#endif // TEAM2_HPP