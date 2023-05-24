#include "Team.hpp"
#include <iostream>
#include <algorithm>

using namespace ariel;

Team::Team(Character* leader) : leader(leader), livingTeamMembers(1){
    if(leader->getInTeam()){
        throw std::runtime_error("runtime error: You cannot add the same player to both teams");
    }
    leader->setInTeam(true);
    fightersArray.push_back(leader);
}

Team::~Team() {
    for (Character* fighter : fightersArray) {
        delete fighter;
    }
}

std::vector<Character*> Team::getFihtersArray() const{
    return this->fightersArray;
}

void Team::add(Character* fighter) {
    if(fightersArray.size() == 10){
        throw std::runtime_error("runtime error: You can't add more than 10 fighter to one team");
    }
    if(fighter->getInTeam()){
        throw std::runtime_error("runtime error: You cannot add the same player to both teams");
    }
    this->livingTeamMembers += 1;
    fighter->setInTeam(true);
    fightersArray.push_back(fighter);
}

void Team::attack(Team* enemyGroup) {
    if(enemyGroup == nullptr){
        throw std::invalid_argument("invalid argument: enemyGroup is null pointer");
    }
    if(enemyGroup->livingTeamMembers == 0){
        throw std::runtime_error("runtime error: All the member in enemyGroup is dead");
    }
    if (leader == nullptr || !leader->isAlive()) {
        // Find the living character closest to the dead leader and set it as the new leader
        double closestDistance = std::numeric_limits<double>::max();
        Character* newLeader = nullptr;
        for (Character* fighter : fightersArray) {
            if (fighter->isAlive()) {
                double distance = leader->distance(fighter);
                if (distance < closestDistance) {
                    closestDistance = distance;
                    newLeader = fighter;
                }
            }
        }
        leader = newLeader;
    }

    Character* victim = nullptr;
    double closestDistance = std::numeric_limits<double>::max();
    for (Character* enemy : enemyGroup->fightersArray) {
        if (enemy->isAlive()) {
            double distance = leader->distance(enemy);
            if (distance < closestDistance) {
                closestDistance = distance;
                victim = enemy;
            }
        }
    }

    if (victim != nullptr) {
        for (Character* fighter : fightersArray) {
            if (!victim->isAlive()) {
                // Find the living enemy character closest to the attacking group's leader as the new victim
                closestDistance = std::numeric_limits<double>::max();
                for (Character* enemy : enemyGroup->fightersArray) {
                    if (enemy->isAlive()) {
                        double distance = leader->distance(enemy);
                        if (distance < closestDistance) {
                            closestDistance = distance;
                            victim = enemy;
                        }
                    }
                }
            }
            if (fighter->isAlive()) {
                Cowboy* cowboy = dynamic_cast<Cowboy*>(fighter);
                if (cowboy != nullptr){
                    if(cowboy->hasboolets()) {
                        cowboy->shoot(victim);
                    }
                    else{
                        cowboy->reload();
                    }
                } else {
                    Ninja* ninja = dynamic_cast<Ninja*>(fighter);
                    if (ninja != nullptr){
                        if(ninja->distance(victim) < 1.0) {
                            ninja->slash(victim);
                        }
                        else {
                            ninja->move(victim);
                        }
                    }
                }
            }
        }
    }
}

int Team::stillAlive() const {
    int aliveCount = 0;
    for (Character* fighter : fightersArray) {
        if (fighter->isAlive()) {
            aliveCount++;
        }
    }
    return aliveCount;
}

void Team::print() const {
    for (Character* fighter : fightersArray) {
        fighter->print();
    }
}
