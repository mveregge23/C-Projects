// Program name: ArmorSpace.hpp
// Date: 12/9/19
// Author: Max Veregge
// Description: ArmorSpace.hpp contains a specification for the derived
// ArmorSpace class. ArmorSpace inherits most data members and functions
// from the Space parent class, but defines its own armor data member, and 
// a constructor and accessor to manage it. 

#ifndef ARMORSPACE_HPP
#define ARMORSPACE_HPP

#include "Space.hpp"
#include "Armor.hpp"

class ArmorSpace : public Space
{
private:
	Armor* armor;
public:
	ArmorSpace(Armor*);
	~ArmorSpace();
	virtual void interact();
	void addArmor(Armor*);
	Armor* getArmor();
};

#endif