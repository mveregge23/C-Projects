// Program name: SpaceTypes.hpp
// Date: 12/9/19
// Author: Max Veregge
// Description: SpaceTypes.hpp contains an enumerated data type SpaceTypes,
// and a specification for a function convertSpaceTypes that takes an 
// enumerated SpaceType and converts it to a string. It also contains an
// enumerated data type for the directions of the pointers connecting each
// space.

#ifndef SPACETYPES_HPP
#define SPACETYPES_HPP

#include <string>

enum Direction { NORTH, EAST, SOUTH, WEST };
enum SpaceType { EMPTY, MONSTER, SPELLSTONE, HEALTH, PACES, ARMOR };

std::string convertSpaceType(SpaceType);

#endif
