// Program name: Elements.hpp
// Date: 12/8/19
// Author: Max Veregge
// Description: Elements.hpp contains a definition for the Elements
// enum data type that represents the different types of monsters and
// spell stones in the game.

#ifndef ELEMENTS_HPP
#define ELEMENTS_HPP

#include <string>

enum element {NEUTRAL, FIRE, WATER, EARTH, WIND};

std::string convertElement(element);

#endif
