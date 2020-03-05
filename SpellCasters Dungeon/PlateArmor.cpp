// Program name: PlateArmor.cpp
// Date: 12/8/19
// Author: Max Veregge
// Description: PlateArmor.cpp contains an implementation of the derived
// PlateArmor class. PlateArmor inherits all of its data members and
// functions from the Armor parent class, but defines its own constructor
// to uniquely initialize the data members.

#include "PlateArmor.hpp"

PlateArmor::PlateArmor()
{
	this->damageRatio = 2;
	this->integrity = 30;
	this->name = "plate armor";
}
