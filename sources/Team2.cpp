#include "Team2.hpp"

using namespace ariel;

Team2::Team2(Character* leader) : Team(leader) {}

// Adds a fighter (cowboy or ninja) to the group
void Team2::add(Character* fighter) {
    std::vector<Character*>& fightersArray = getFightersArray();
    if(fightersArray.size() == 10){
        throw std::runtime_error("runtime error: You can't add more than 10 fighter to one team");
    }
    if(fighter->getInTeam()){
        throw std::runtime_error("runtime error: You cannot add the same player to both teams");
    }
    fighter->setInTeam(true);
    fightersArray.push_back(fighter);
}



