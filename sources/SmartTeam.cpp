// #include "SmartTeam.hpp"

// using namespace ariel;

// SmartTeam::SmartTeam(Character* leader) : Team(leader) {}

// // Adds a fighter (cowboy or ninja) to the group
// void SmartTeam::attack(SmartTeam* enemyGroup){
//     if(enemyGroup == nullptr){
//         throw std::invalid_argument("invalid argument: enemyGroup is null pointer");
//     }
//     if(!enemyGroup->stillAlive()){
//         throw std::runtime_error("runtime error: All the member in enemyGroup is dead");
//     }

//     Character* victim = nullptr;
//     double closestDistance = std::numeric_limits<double>::max();
//     double distance;
//     Character* leader = getLeader();
//     std::vector<Character*>& fightersArray = getFightersArray();
//     std::vector<Character*>& enemyGroupArray = getFightersArray();
//     std::vector<double> enemyDistance (fightersArray.size(), -1);

//     if (leader == nullptr || !leader->isAlive()) {
//         // Find the living character closest to the dead leader and set it as the new leader
//         Character* newLeader = nullptr;
//         for (Character* fighter : fightersArray) {
//             if (fighter->isAlive()) {
//                 distance = leader->distance(fighter);
//                 if (distance < closestDistance) {
//                     closestDistance = distance;
//                     newLeader = fighter;
//                 }
//             }
//         }
//         leader = newLeader;
//     }

//     for (Character* fighter : fightersArray) {
//         // if (victim == nullptr || !victim->isAlive()) {
//             // Find the living enemy character closest to the attacking group's leader as the new victim
//         closestDistance = std::numeric_limits<double>::max();
//         for (Character* enemy : enemyGroupArray) {
//             if (enemy->isAlive()) {
//                 distance = fighter->distance(enemy);
//                 if (distance < closestDistance) {
//                     closestDistance = distance;
//                     victim = enemy;
//                 }
//             }
//         }
//         if (victim != nullptr){
//             enemyDistance[closestDistance];
//         }

//         for (int i = 0; i < enemyDistance.size(); i++) {
//             if (enemyDistance[i] != -1) {
//                 return;
//             }
//         }
//         // }
        
//         if (fighter->isAlive()) {
//             Cowboy* cowboy = dynamic_cast<Cowboy*>(fighter);
//             if (cowboy != nullptr){
//                 if(cowboy->hasboolets()) {
//                     cowboy->shoot(victim);
//                 }
//                 else{
//                     cowboy->reload();
//                 }
//             } else {
//                 Ninja* ninja = dynamic_cast<Ninja*>(fighter);
//                 if (ninja != nullptr){
//                     if(ninja->distance(victim) < 1.0) {
//                         ninja->slash(victim);
//                     }
//                     else {
//                         ninja->move(victim);
//                     }
//                 }
//             }
//         }
//     }
// }



//     Character* findNearestAliveCharacter(const Point& location) {
//         Character* nearest = nullptr;
//         double minDistance = std::numeric_limits<double>::max();
//         for (Character* fighter : fighters) {
//             if (fighter->isAlive()) {
//                 double distance = location.distance(fighter->getLocation());
//                 if (distance < minDistance) {
//                     minDistance = distance;
//                     nearest = fighter;
//                 }
//             }
//         }
//         return nearest;
//     }

//     void chooseNewLeader() {
//         Character* nearest = findNearestAliveCharacter(leader->getLocation());
//         if (nearest != nullptr) {
//             leader = dynamic_cast<Cowboy*>(nearest);
//         }
//     }

//     void attack(SmartTeam* enemyTeam) {
//         if (!leader->isAlive()) {
//             chooseNewLeader();
//             if (leader == nullptr) {
//                 return;
//             }
//         }

//         for (Character* fighter : fighters) {
//             if (Ninja* ninja = dynamic_cast<Ninja*>(fighter)) {
//                 Character* closestEnemy = enemyTeam->findNearestAliveCharacter(ninja->getLocation());
//                 if (closestEnemy != nullptr && ninja->distance(*closestEnemy) < 1) {
//                     ninja->slash(closestEnemy);
//                 }
//             }
//         }

//         Character* weakestEnemy = nullptr;
//         int minHitPoints = std::numeric_limits<int>::max();
//         for (Character* enemy : enemyTeam->fighters) {
//             if (enemy->isAlive() && enemy->hitPoints < minHitPoints) {
//                 weakestEnemy = enemy;
//                 minHitPoints = enemy->hitPoints;
//             }
//         }

//         if (weakestEnemy != nullptr) {
//             for (Character* fighter : fighters) {
//                 if (Cowboy* cowboy = dynamic_cast<Cowboy*>(fighter)) {
//                     if (cowboy->hasBullets()) {
//                         cowboy->shoot(weakestEnemy);
//                     }
//                 }
//             }
//         }

//         for (Character* fighter : fighters) {
//             if (Ninja* ninja = dynamic_cast<Ninja*>(fighter)) {
//                 if (!ninja->isAlive()) {
//                     continue;
//                 }

//                 Character* closestEnemy = enemyTeam->findNearestAliveCharacter(ninja->getLocation());
//                 if (closestEnemy != nullptr) {
//                     ninja->move(closestEnemy);
//                 }
//             }
//         }
//     }




























//         Character* findNearestAliveCharacter(const Point& location);
//         void chooseNewLeader();




//     Character* Team::findNearestAliveCharacter(const Point& location) {
//     Character* nearest = nullptr;
//     double minDistance = std::numeric_limits<double>::max();
//     for (Character* fighter : fightersArray) {
//         if (fighter->isAlive()) {
//             double distance = location.distance(fighter->getLocation());
//             if (distance < minDistance) {
//                 minDistance = distance;
//                 nearest = fighter;
//             }
//         }
//     }
//     return nearest;
// }

// void Team::chooseNewLeader() {
//     Character* nearest = findNearestAliveCharacter(leader->getLocation());
//     if (nearest != nullptr) {
//         leader = dynamic_cast<Cowboy*>(nearest);
//     }
// }