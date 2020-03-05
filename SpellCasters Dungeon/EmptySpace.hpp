// Program name: EmptySpace.hpp
// Date: 12/9/19
// Author: Max Veregge
// Description: EmptySpace.hpp contains a specification for the derived
// EmptySpace class. EmptySpace inherits all of its data members and 
// functions from the Space parent class, but defines its own constructor
// to initialize the type appropriately and defines the virtual interact
// function.

#ifndef EMPTYSPACE_HPP
#define EMPTYSPACE_HPP

#include "Space.hpp"

class EmptySpace : public Space 
{
public:
	EmptySpace();
	virtual void interact();
};

#endif
