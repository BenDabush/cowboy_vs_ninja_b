#include "Team.hpp"

using namespace ariel;

Team::Team(Character* leader) : leader(leader){
    this->add(leader);
}

Team::~Team() {
    for (Character* fighter : fightersArray) {
        delete fighter;
    }
}

std::vector<Character*>& Team::getFightersArray(){
    return this->fightersArray;
}

Character* Team::getLeader(){
    return this->leader;
}

void Team::setLeader(Character* newLeader){
    this->leader = newLeader;
}

void Team::add(Character* fighter) {
    if (fightersArray.size() == 10) {
        throw std::runtime_error("runtime error: You can't add more than 10 fighters to one team");
    }
    if (fighter->getInTeam()) {
        throw std::runtime_error("runtime error: You cannot add the same player to both teams");
    }
    fighter->setInTeam(true);

    Ninja* ninja = dynamic_cast<Ninja*>(fighter);

    if (ninja != nullptr) {
        fightersArray.push_back(fighter);
    } else {
        std::vector<Character*>::size_type index = 0;
        while (index < fightersArray.size()) {
            if (dynamic_cast<Ninja*>(fightersArray[index]) != nullptr) {
                fightersArray.insert(std::next(fightersArray.begin(), static_cast<std::vector<Character*>::difference_type>(index)), fighter);
                break;
            }
            index++;
        }
        if(fightersArray.size() == index){
            fightersArray.push_back(fighter);
        }
    }
}

void Team::attack(Team* enemyGroup){
    if(enemyGroup == nullptr){
        throw std::invalid_argument("invalid argument: enemyGroup is null pointer");
    }
    if(!enemyGroup->stillAlive()){
        throw std::runtime_error("runtime error: All the member in enemyGroup is dead");
    }

    Character* victim = nullptr;
    double closestDistance = std::numeric_limits<double>::max();
    double distance;

    if (this->leader == nullptr || !leader->isAlive()) {
        // Find the living character closest to the dead leader and set it as the new leader
        Character* newLeader = nullptr;
        for (Character* fighter : fightersArray) {
            if (fighter->isAlive()) {
                distance = leader->distance(fighter);
                if (distance < closestDistance) {
                    closestDistance = distance;
                    newLeader = fighter;
                }
            }
        }
        this->leader = newLeader;
    }

    for (Character* fighter : fightersArray) {
        if (victim == nullptr || !victim->isAlive()) {
            // Find the living enemy character closest to the attacking group's leader as the new victim
            closestDistance = std::numeric_limits<double>::max();
            for (Character* enemy : enemyGroup->fightersArray) {
                if (enemy->isAlive()) {
                    distance = leader->distance(enemy);
                    if (distance < closestDistance) {
                        closestDistance = distance;
                        victim = enemy;
                    }
                }
            }
            if (victim == nullptr || !victim->isAlive()) {
                break;
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
    std::cout << "Leader:\n\t" << leader->print();
    std::cout << "Team member:\n";
    for (Character* fighter : fightersArray) {
        if(&fighter != &leader){
            std::cout << "\t" << fighter->print();
        }
        
    }
    std::cout <<"\n";
}
