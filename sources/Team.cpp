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

Character* Team::findNearestAliveCharacter(const Point& location) {
    Character* nearest = nullptr;
    double minDistance = std::numeric_limits<double>::max();
    for (Character* fighter : fightersArray) {
        if (fighter->isAlive()) {
            double distance = location.distance(fighter->getLocation());
            if (distance < minDistance) {
                minDistance = distance;
                nearest = fighter;
            }
        }
    }
    return nearest;
}

void Team::chooseNewLeader() {
    Character* nearest = findNearestAliveCharacter(leader->getLocation());
    if (nearest != nullptr) {
        this->leader = nearest;
    }
}

void Team::attack(Team* enemyTeam){
    if(enemyTeam == nullptr){
        throw std::invalid_argument("invalid argument: enemyTeam is null pointer");
    }
    if(!enemyTeam->stillAlive()){
        throw std::runtime_error("runtime error: All the member in enemyTeam is dead");
    }

    Character* closestEnemy = nullptr;
    double closestDistance = std::numeric_limits<double>::max();
    double distance;

    if (this->leader == nullptr || !leader->isAlive()) {
        // Find the living character closest to the dead leader and set it as the new leader
        chooseNewLeader();
        if (leader == nullptr) {
            return;
        }
    }
    
    for (Character* fighter : fightersArray) {
        if (closestEnemy == nullptr || !closestEnemy->isAlive()) {
            closestEnemy = enemyTeam->findNearestAliveCharacter(this->leader->getLocation());

            if (closestEnemy == nullptr || !closestEnemy->isAlive()) {
                break;
            }
        }
        
        if (fighter->isAlive()) {
            Cowboy* cowboy = dynamic_cast<Cowboy*>(fighter);
            if (cowboy != nullptr){
                if(cowboy->hasboolets()) {
                    cowboy->shoot(closestEnemy);
                }
                else{
                    cowboy->reload();
                }
            } else {
                Ninja* ninja = dynamic_cast<Ninja*>(fighter);
                if (ninja != nullptr){
                    if(ninja->distance(closestEnemy) < 1.0) {
                        ninja->slash(closestEnemy);
                    }
                    else {
                        ninja->move(closestEnemy);
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
