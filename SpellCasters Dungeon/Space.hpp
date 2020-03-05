// Program name: Space.hpp
// Date: 12/9/19
// Author: Max Veregge
// Description: Space.hpp contains a specification for the Space parent
// class. Space contains data members for pointers to connect it to the
// other spaces on the board, and an enumerated SpaceType. It also contains
// member functions to get the type of the space, get its neighbor in a
// specific direction, set its neighbor in a specific direction, and interact
// with the space.

#ifndef SPACE_HPP
#define SPACE_HPP

#include <iostream>
#include "SpaceTypes.hpp"

class Space 
{
protected:
	Space* north;
	Space* east;
	Space* south;
	Space* west;
	SpaceType st;
public:
	SpaceType getType();
	Space* getNeighbor(Direction);
	void setNeighbor(Direction, Space*);
	virtual void interact() = 0;
	Space();
	virtual ~Space();
};

#endif
