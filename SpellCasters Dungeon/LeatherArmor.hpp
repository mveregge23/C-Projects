// Program name: LeatherArmor.hpp
// Date: 12/8/19
// Author: Max Veregge
// Description: LeatherArmor.hpp contains a specification for the derived
// LeatherArmor class. LeatherArmor inherits all of its data members and
// functions from the Armor parent class, but defines its own constructor
// to uniquely initialize the data members.

#ifndef LEATHERARMOR_HPP
#define LEATHERARMOR_HPP

#include "Armor.hpp"

class LeatherArmor : public Armor
{
public:
	LeatherArmor();
};

#endif
