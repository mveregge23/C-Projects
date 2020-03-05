// Program name: Armor.cpp
// Date: 12/8/19
// Author: Max Veregge
// Description: Armor.cpp contains a specification for the Armor class.
// Armor has data members for the damage ratio applied to all attacks
// (damageRatio), the integrity of the armor, and the name of the armor.
// It has accessor functions for the damageRatio and name of the armor,
// a function to use the armor in battle, and an override function for
// the << ostream operator.

#include "Armor.hpp"

//getDamageRatio is an accessor for the damage ratio data member
int Armor::getDamageRatio() const
{
	return this->damageRatio;
}

//getName is an accessor for the name data member
std::string Armor::getName() const
{
	return this->name;
}

//getIntegrity is an accessor for the integrity data member
int Armor::getIntegrity() const
{
	return this->integrity;
}

//useArmor calculates and returns the amount of damage to be done
//to the hero, and decrements the armors integrity by the amount
//of damage it absorbed
int Armor::useArmor(int damage)
{
	
	int armorDamage = damage / this->damageRatio;
	std::cout << "Your armor absorbed " << armorDamage << " damage!\n";
	int heroDamage = damage - armorDamage;
	
	if (armorDamage > this->integrity) 
	{
		this->integrity = 0;
	}
	else
	{
		this->integrity -= armorDamage;
	}

	return heroDamage;
}

//override for ostream operator
std::ostream& operator<<(std::ostream& os, const Armor& a)
{
	//pass monster name to os and return it
	os << a.getName();
	return os;
}