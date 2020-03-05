// Program name: WindMonster.hpp
// Date: 12/8/19
// Author: Max Veregge
// Description: WindMonster.hpp contains a specification for the derived WindMonster class.
// WindMonster inherits all of its data members and functions from the parent Monster class,
// but defines its own constructor to initialize the data members.

#ifndef WINDMONSTER_HPP
#define WINDMONSTER_HPP

#include "Monster.hpp"

class WindMonster : public Monster
{
public:
	WindMonster();
};

#endif
