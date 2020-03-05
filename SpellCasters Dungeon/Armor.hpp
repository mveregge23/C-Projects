// Program name: Armor.hpp
// Date: 12/8/19
// Author: Max Veregge
// Description: Armor.hpp contains a specification for the Armor class.
// Armor has data members for the damage ratio applied to all attacks
// (damageRatio), the integrity of the armor, and the name of the armor.
// It has accessor functions for the damageRatio and name of the armor,
// a function to use the armor in battle, and an override function for
// the << ostream operator.

#ifndef ARMOR_HPP
#define ARMOR_HPP

#include <iostream>
#include <string>

class Armor
{
protected:
	int damageRatio,
		integrity;
	std::string name;
public:
	int getDamageRatio() const;
	int useArmor(int);
	int getIntegrity() const;
	std::string getName() const;
	friend std::ostream& operator<<(std::ostream&, const Armor&);
};

#endif
