// Program name: Monster.hpp
// Date: 12/8/19
// Author: Max Veregge
// Description: Monster.hpp contains a specification for the abstract Monster class.
// Monster has data members for its health points (hp), attack damage (damage), weakness,
// resistance, and name. It has accessor functions for all data members, and a mutator
// function for the hp data member. Monster also has an override function for the 
// << ostream operator.

#ifndef MONSTER_HPP
#define MONSTER_HPP

#include <iostream>
#include <string>
#include "Elements.hpp"

class Monster 
{
protected:
	int hp,
		damage;
	element type,
		weakness, 
		resistance;
	std::string name;
public:
	int getDamage() const,
		getHp() const;
	element getWeakness() const,
		getResistance() const,
		getType() const;
	std::string	getName() const;
	bool takeDamage(int, element);
	bool setHp(int);
	friend std::ostream& operator<<(std::ostream&, const Monster&);
};


#endif

