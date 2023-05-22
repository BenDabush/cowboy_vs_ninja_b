#ifndef TRAINEDNINJA_HPP
#define TRAINEDNINJA_HPP

#include "Ninja.hpp"
#include <string>

namespace ariel{
    class TrainedNinja : public Ninja {
    public:
        // Constructor for TrainedNinja
        TrainedNinja(const std::string& name, const Point& location);
    };
};

#endif // TRAINEDNINJA_HPP