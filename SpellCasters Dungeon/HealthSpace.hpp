// Program name: HealthSpace.hpp
// Date: 12/9/19
// Author: Max Veregge
// Description: HealthSpace.hpp contains a specification for the derived
// HealthSpace class. HealthSpace inherits most data members and functions
// from the Space parent class, but defines its own healthBoost data member, and 
// a constructor and accessor to manage it. 

#ifndef HEALTHSPACE_HPP
#define HEALTHSPACE_HPP

#include "Space.hpp"

class HealthSpace : public Space
{
private:
	int healthBoost;
public:
	HealthSpace(int);
	virtual void interact();
	int getHealthBoost();
};

#endif