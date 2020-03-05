// Program name: WaterMonster.hpp
// Date: 12/8/19
// Author: Max Veregge
// Description: WaterMonster.hpp contains a specification for the derived WaterMonster class.
// WaterMonster inherits all of its data members and functions from the parent Monster class,
// but defines its own constructor to initialize the data members.

#ifndef WATERMONSTER_HPP
#define WATERMONSTER_HPP

#include "Monster.hpp"

class WaterMonster : public Monster
{
public:
	WaterMonster();
};

#endif