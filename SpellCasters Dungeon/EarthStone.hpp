// Program name: EarthStone.hpp
// Date: 12/8/19
// Author: Max Veregge
// Description: EarthStone.hpp contains a specification for the derived
// EarthStone class. EarthStone inherits all of its data members and 
// functions from the parent SpellStone class, but defines its own
// constructor to uniquely initialize the data members.

#ifndef EARTHSTONE_HPP
#define EARTHSTONE_HPP

#include "SpellStone.hpp"

class EarthStone : public SpellStone
{
public:
	EarthStone();
};

#endif