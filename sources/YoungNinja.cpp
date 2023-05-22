#include "YoungNinja.hpp"
#include <cmath>

namespace ariel {
    // Constructor for YoungNinja
    YoungNinja::YoungNinja(const std::string& name, const Point& location) : Ninja(name, location, 14)
    {
        setHitPoints(100);
    }
}