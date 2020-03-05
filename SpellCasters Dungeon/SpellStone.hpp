// Program name: SpellStone.hpp
// Date: 12/8/19
// Author: Max Veregge
// Description: SpellStone.hpp contains a specification for the parent
// SpellStone class. SpellStone contains data members for the damage, type
// uses, and name. It has accessors for all data members, and a function
// to use the stone, decrement its uses, and return the remaining number of
// uses.

#ifndef SPELLSTONE_HPP
#define SPELLSTONE_HPP

#include "Elements.hpp"
#include <iostream>
#include <string>

class SpellStone
{
protected:
	int damage,
		uses;
	element type;
	std::string name;
public:
	int getDamage() const,
		getUses() const;
	element getType() const;
	std::string getName() const;
	int useStone();
	friend std::ostream& operator<<(std::ostream&, const SpellStone&);
};

#endif
