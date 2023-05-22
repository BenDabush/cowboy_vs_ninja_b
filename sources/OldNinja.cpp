#include "OldNinja.hpp"
#include <cmath>

using namespace ariel;
    // Constructor for OldNinja
    OldNinja::OldNinja(const std::string& name, const Point& location) : Ninja(name, location, 8)
    {
        setHitPoints(150);
    }