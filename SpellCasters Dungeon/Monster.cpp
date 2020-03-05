// Program name: Monster.cpp
// Date: 12/8/19
// Author: Max Veregge
// Description: Monster.cpp contains an implementation of the Monster class.
// Monster has data members for its health points (hp), attack damage (damage), weakness,
// resistance, and name. It has accessor functions for all data members, and a mutator
// function for the hp data member.

#include "Monster.hpp"

//getDamage is an accessor for the damage data member
int Monster::getDamage() const 
{
	return this->damage;
}

//getName is an accessor for the name data member
std::string Monster::getName() const 
{
	return this->name;
}

//getResistance is an accessor for the resistance data member
element Monster::getResistance() const 
{
	return this->resistance;
}

//getWeakness is an accessor for the resistance data member
element Monster::getWeakness() const 
{
	return this->weakness;
}

//getHp is an accessor for the hp data member
int Monster::getHp() const 
{
	return this->hp;
}

//setHp is a mutator for hp that takes an integer damage as a parameter, then
//decrements hp by damage
bool Monster::setHp(int damage)
{
	
	//check if damage is greater than remaining hp
	if (damage > this->hp) 
	{
		//yes: set hp to 0
		this->hp = 0;
		std::cout << *this << " has " << this->hp << " health remaining.\n";
	}
	else
	{
		//no: decrement hp by damage
		this->hp -= damage;
		std::cout << *this << " has " << this->hp << " health remaining.\n";
	}

	//check if hp is less than one
	if (this->hp < 1) 
	{
		//yes: return false symbolizing monster death
		return false;
	}
	else 
	{
		//no: return true symbolizing monster still alive
		return true;
	}
}


//getType is an accessor for the type data member
element Monster::getType() const
{
	return this->type;
}


//takeDamage is a mutator for the hp data member that takes an
//amount of damage and a type of damage to apply to the monster
bool Monster::takeDamage(int damage, element el)
{

	if (this->resistance == el)
	{
		std::cout << "The " << *this << " is resistant to " << convertElement(el)
			<< " damage!\n";
		int resDamage = damage / 2;
		std::cout << "The " << *this << " took " << resDamage << " damage.\n";
		return this->setHp(resDamage);
	}

	else if (this->weakness == el)
	{
		std::cout << "The " << *this << " is weak against " << convertElement(el)
			<< " damage!\n";
		int weakDamage = damage * 1.5;
		std::cout << "The " << *this << " took " << weakDamage << " damage.\n";
		return this->setHp(weakDamage);
	}

	else {
		std::cout << "The " << *this << " took " << damage << " damage.\n";
		return this->setHp(damage);
	}

}


//override for ostream operator
std::ostream& operator<<(std::ostream& os, const Monster& m)
{
	//pass monster name to os and return it
	os << m.getName();
	return os;
}