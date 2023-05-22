#ifndef YOUNGNINJA_HPP
#define YOUNGNINJA_HPP

#include "Ninja.hpp"
#include <string>

namespace ariel{
    class YoungNinja : public Ninja {
    public:
        // Constructor for YoungNinja
        YoungNinja(const std::string& name, const Point& location);
    };
};

#endif // YOUNGNINJA_HPP