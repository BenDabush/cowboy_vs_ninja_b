#include "Cowboy.hpp"
#include <iostream>

using namespace ariel;

Cowboy::Cowboy(const std::string& name, const Point& location)
    : Character(name, location, 11), m_bullets(6) {}

void Cowboy::shoot(Character* enemy) {
    if (m_bullets > 0 && enemy->isAlive()) {
        std::cout << getName() << " shoots " << enemy->getName() << "!" << std::endl;
        enemy->hit(1);
        m_bullets--;
    } else {
        std::cout << getName() << " can't shoot." << std::endl;
    }
}

bool Cowboy::hasBullets() const {
    return m_bullets > 0;
}

void Cowboy::reload() {
    m_bullets = 6;
    std::cout << getName() << " reloads." << std::endl;
}
