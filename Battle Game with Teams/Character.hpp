// Program name: Character.hpp
// Date: 11/7/19
// Author: Max Veregge
// Description: Character.hpp contains a specification for the Character parent class. Character
// has data members for attacking, defending, armor, and strength that are inherited and dynamically 
// defined by the constructors of its children. Character has some getter and setter functions for 
// armor and strength that are inherited by its children, and some attack and defend functions that
// are defined by its children.

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Die.hpp"
#include <iostream>
#include <string>

class Character {
protected:
	int numAttackDice;
	int attackDiceSides;
	int numDefenseDice;
	Die** attackDice;
	Die** defenseDice;
	int armor;
	int strength;
	int maxStrength;
	std::string name;
	std::string type;

public:
	Character(int, int, int, std::string);
	~Character();
	virtual int attack() = 0, defend() = 0;
	int getArmor() const, getStrength() const;
	std::string getName() const;
	std::string getType() const;
	void recover();
	virtual void setStrength(int);
	friend std::ostream& operator<<(std::ostream&, const Character&);
};

#endif