// Program name: LeatherArmor.cpp
// Date: 12/8/19
// Author: Max Veregge
// Description: LeatherArmor.cpp contains an implementation of the derived
// LeatherArmor class. LeatherArmor inherits all of its data members and
// functions from the Armor parent class, but defines its own constructor
// to uniquely initialize the data members.

#include "LeatherArmor.hpp"

LeatherArmor::LeatherArmor()
{
	this->damageRatio = 4;
	this->integrity = 15;
	this->name = "leather armor";
}
