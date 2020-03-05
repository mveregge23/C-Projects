// Program name: PlateArmor.hpp
// Date: 12/8/19
// Author: Max Veregge
// Description: PlateArmor.hpp contains a specification for the derived
// PlateArmor class. PlateArmor inherits all of its data members and
// functions from the Armor parent class, but defines its own constructor
// to uniquely initialize the data members.

#ifndef PLATEARMOR_HPP
#define PLATEARMOR_HPP

#include "Armor.hpp"

class PlateArmor : public Armor
{
public:
	PlateArmor();
};

#endif
