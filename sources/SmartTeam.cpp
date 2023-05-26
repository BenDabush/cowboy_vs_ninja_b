#include "SmartTeam.hpp"

using namespace ariel;

SmartTeam::SmartTeam(Character* leader) : Team(leader) {}

// Adds a fighter (cowboy or ninja) to the group


void SmartTeam::attack(Team* enemyTeam) {
    if(enemyTeam == nullptr){
        throw std::invalid_argument("invalid argument: enemyTeam is null pointer");
    }
    if(!enemyTeam->stillAlive()){
        throw std::runtime_error("runtime error: All the member in enemyTeam is dead");
    }

    if (!getLeader()->isAlive()) {
        chooseNewLeader();
        if (getLeader() == nullptr) {
            return;
        }
    }

    std::vector<Character*> fightersArray = getFightersArray();
    Character* closestEnemy;

    for (Character* fighter : fightersArray) {
        if (Ninja* ninja = dynamic_cast<Ninja*>(fighter)) {
            closestEnemy = enemyTeam->findNearestAliveCharacter(ninja->getLocation());
            if(closestEnemy == nullptr){
                return;
            }
            else if (ninja->distance(closestEnemy) < 1) {
                ninja->slash(closestEnemy);
            }
        }
    }
    
    std::vector<Character*> enemyTeamFightersArray = enemyTeam->getFightersArray();
    Character* weakestEnemy = nullptr;
    int minHitPoints = std::numeric_limits<int>::max();
    for (Character* enemy : enemyTeamFightersArray) {
        if (enemy->isAlive() && enemy->getCharacterHP() < minHitPoints) {
            weakestEnemy = enemy;
            minHitPoints = enemy->getCharacterHP();
        }
    }
    if (weakestEnemy == nullptr){
        return;
    }
    else {
        for (Character* fighter : fightersArray) {
            if(!weakestEnemy->isAlive()){
                weakestEnemy = nullptr;
                minHitPoints = std::numeric_limits<int>::max();
                for (Character* enemy : enemyTeamFightersArray) {
                    if (enemy->isAlive() && enemy->getCharacterHP() < minHitPoints) {
                        weakestEnemy = enemy;
                        minHitPoints = enemy->getCharacterHP();
                    }
                }
                if(weakestEnemy == nullptr){
                    return;
                }
            }
            if (Cowboy* cowboy = dynamic_cast<Cowboy*>(fighter)) {
                if (cowboy->hasboolets()) {
                    cowboy->shoot(weakestEnemy);
                }
                else{
                    cowboy->reload();
                }
            }
        }
    }
    closestEnemy = nullptr;
    for (Character* fighter : fightersArray) {
        if (Ninja* ninja = dynamic_cast<Ninja*>(fighter)) {
            if (ninja->isAlive()) {
                closestEnemy = enemyTeam->findNearestAliveCharacter(ninja->getLocation());
                if(closestEnemy == nullptr) {
                    return;
                }
                if(ninja->distance(closestEnemy) >= 1) {
                    ninja->move(closestEnemy);
                }
            }
        }
    }
}
