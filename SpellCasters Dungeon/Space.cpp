// Program name: Space.cpp
// Date: 12/9/19
// Author: Max Veregge
// Description: Space.cpp contains an implementation for the Space parent
// class. Space contains data members for pointers to connect it to the
// other spaces on the board, and an enumerated SpaceType. 

#include "Space.hpp"

//default constructor initializes pointers to adjacent spaces to nullptr
Space::Space()
{
	this->north = nullptr;
	this->east = nullptr;
	this->south = nullptr;
	this->west = nullptr;
}

//getType is an accessor for the st data member
SpaceType Space::getType()
{
	return this->st;
}

//getNeighbor returns a pointer to the space next to this space in the
//direction provided
Space* Space::getNeighbor(Direction d)
{
	switch (d)
	{
	case NORTH:
	{
		return this->north;
	}
	case EAST:
	{
		return this->east;
	}
	case SOUTH:
	{
		return this->south;
	}
	case WEST:
	{
		return this->west;
	}
	}
}

//getNeighbor returns a pointer to the space next to this space in the
//direction provided
void Space::setNeighbor(Direction d, Space* s)
{
	switch (d)
	{
	case NORTH:
	{
		this->north = s;
		break;
	}
	case EAST:
	{
		this->east = s;
		break;
	}
	case SOUTH:
	{
		this->south = s;
		break;
	}
	case WEST:
	{
		this->west = s;
		break;
	}
	}
}

//destructor has no default behavior
Space::~Space()
{
	;
}