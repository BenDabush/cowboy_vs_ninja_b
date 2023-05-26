#ifndef SMARTTEAM_HPP
#define SMARTTEAM_HPP

#include "Team.hpp"
 
namespace ariel{
    class SmartTeam : public Team {
    private:
         std::vector<double> enemyDistance;
    public:
        // Constructor
        SmartTeam(Character* leader);

        // Attacks the enemy group
        void attack(Team* enemyGroup) override;

    };
}
#endif // SMARTTEAM_HPP