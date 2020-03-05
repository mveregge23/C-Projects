// Program name: PaceSpace.hpp
// Date: 12/9/19
// Author: Max Veregge
// Description: PaceSpace.hpp contains a specification for the derived
// PaceSpace class. PaceSpace inherits most data members and functions
// from the Space parent class, but defines its own stepBoost data member, and 
// a constructor and accessor to manage it. 

#ifndef PACESPACE_HPP
#define PACESPACE_HPP

#include "Space.hpp"

class PaceSpace : public Space
{
private:
	int paceBoost;
public:
	PaceSpace(int);
	virtual void interact();
	int getPaceBoost();
};

#endif