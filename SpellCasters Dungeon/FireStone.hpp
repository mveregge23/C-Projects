// Program name: FireStone.hpp
// Date: 12/8/19
// Author: Max Veregge
// Description: FireStone.hpp contains a specification for the derived
// FireStone class. FireStone inherits all of its data members and 
// functions from the parent SpellStone class, but defines its own
// constructor to uniquely initialize the data members.

#ifndef FIRESTONE_HPP
#define FIRESTONE_HPP

#include "SpellStone.hpp"

class FireStone : public SpellStone
{
public:
	FireStone();
};

#endif