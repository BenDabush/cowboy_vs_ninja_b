#include "Team.hpp"
#include <iostream>
#include <algorithm>

using namespace ariel;

Team::Team(Character* leader)
    : m_leader(leader) {
    m_fighters.push_back(leader);
}

void Team::add(Character* fighter) {
    m_fighters.push_back(fighter);
}

void Team::attack(Team* enemyGroup) {
}

int Team::stillAlive() const {
    return 0;
}

void Team::print() const {
    for (Character* fighter : m_fighters) {
        fighter->print();
    }
}
