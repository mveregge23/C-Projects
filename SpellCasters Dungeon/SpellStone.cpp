// Program name: SpellStone.cpp
// Date: 12/8/19
// Author: Max Veregge
// Description: SpellStone.cpp contains an implementation of the parent
// SpellStone class. SpellStone contains data members for the damage, type
// uses, and name. It has accessors for all data members, and a function
// to use the stone, decrement its uses, and return the remaining number of
// uses.

#include "SpellStone.hpp"

//getDamage is an accessor for the damage data member
int SpellStone::getDamage() const
{
	return this->damage;
}

//getUses is an accessor for the uses data member
int SpellStone::getUses() const
{
	return this->uses;
}

//getType is an accessor for the type data member
element SpellStone::getType() const
{
	return this->type;
}

//getName is an accessor for the name data member
std::string SpellStone::getName() const
{
	return this->name;
}

//useStone is a function to decrement the number of uses and return
//the remaining uses of the stone
int SpellStone::useStone()
{
	this->uses--;
	return this->uses;
}

//override for ostream operator
std::ostream& operator<<(std::ostream& os, const SpellStone& ss)
{
	//pass spellstone to os and return it
	os << ss.getName();
	return os;
}