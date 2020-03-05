// Program name: FireMonster.hpp
// Date: 12/8/19
// Author: Max Veregge
// Description: FireMonster.hpp contains a specification for the derived FireMonster class.
// FireMonster inherits all of its data members and functions from the parent Monster class,
// but defines its own constructor to initialize the data members.

#ifndef FIREMONSTER_HPP
#define FIREMONSTER_HPP

#include "Monster.hpp"

class FireMonster : public Monster
{
public:
	FireMonster();
};

#endif
