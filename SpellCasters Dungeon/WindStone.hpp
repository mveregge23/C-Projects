// Program name: WindStone.hpp
// Date: 12/8/19
// Author: Max Veregge
// Description: WindStone.hpp contains a specification for the derived
// WindStone class. WindStone inherits all of its data members and 
// functions from the parent SpellStone class, but defines its own
// constructor to uniquely initialize the data members.

#ifndef WINDSTONE_HPP
#define WINDSTONE_HPP

#include "SpellStone.hpp"

class WindStone : public SpellStone
{
public:
	WindStone();
};

#endif