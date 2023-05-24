#include "TrainedNinja.hpp"

using namespace ariel;

// Constructor for TrainedNinja
TrainedNinja::TrainedNinja(const std::string& name, const Point& location) : Ninja(name, location, 12)
{
    setHitPoints(120);
}
