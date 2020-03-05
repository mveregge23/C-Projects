// Program name: WaterStone.hpp
// Date: 12/8/19
// Author: Max Veregge
// Description: WaterStone.hpp contains a specification for the derived
// WaterStone class. WaterStone inherits all of its data members and 
// functions from the parent SpellStone class, but defines its own
// constructor to uniquely initialize the data members.

#ifndef WATERSTONE_HPP
#define WATERSTONE_HPP

#include "SpellStone.hpp"

class WaterStone : public SpellStone
{
public:
	WaterStone();
};

#endif