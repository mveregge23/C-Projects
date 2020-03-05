// Program name: EarthMonster.hpp
// Date: 12/8/19
// Author: Max Veregge
// Description: EarthMonster.hpp contains a specification for the derived EarthMonster class.
// EarthMonster inherits all of its data members and functions from the parent Monster class,
// but defines its own constructor to initialize the data members.

#ifndef EARTHMONSTER_HPP
#define EARTHMONSTER_HPP

#include "Monster.hpp"

class EarthMonster : public Monster
{
public:
	EarthMonster();
};

#endif
