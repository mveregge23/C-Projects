// Program name: Character.cpp
// Date: 11/7/19
// Author: Max Veregge
// Description: Character.cpp contains a partial implementation of the Character class. Character
// has data members for attacking, defending, armor, and strength that are inherited and dynamically 
// defined by the constructors of its children. Character has some getter and setter functions for 
// armor and strength that are inherited by its children, and some attack and defend functions that
// are defined by its children.

#include "Character.hpp"

//constructor defines attackDice and defenseDice using input parameters
Character::Character(int numAttackDice, int attackDiceSides, int numDefenseDice, std::string name) {
	this->numAttackDice = numAttackDice;
	this->attackDiceSides = attackDiceSides;
	this->numDefenseDice = numDefenseDice;

	//dynamically define attackDice
	this->attackDice = new Die * [numAttackDice];
	for (int i = 0; i < numAttackDice; i++) {
		attackDice[i] = new Die(attackDiceSides);
	}

	//dynamically define defenseDice
	this->defenseDice = new Die * [numDefenseDice];
	for (int i = 0; i < numDefenseDice; i++) {
		defenseDice[i] = new Die(6);
	}

	this->name = name;
}

//setStrength takes an integer for the amount of damage to be done, then reduces the character's strength points by that number of damage
void Character::setStrength(int damage) {
	this->strength -= damage;
}

//getArmor returns the character's armor value
int Character::getArmor() const {
	return this->armor;
}

//getStrength returns the character's strength value
int Character::getStrength() const {
	return this->strength;
}

//getName returns the character's name
std::string Character::getName() const {
	return this->name;
}

void Character::recover() {
	int diff = maxStrength - strength;
	int recovery = diff / 2;
	strength += recovery;
}

std::string Character::getType() const {
	return this->type;
}

//operator<< overload prints out name of character when used with << operator
std::ostream& operator<<(std::ostream& os, const Character& ch) {
	os << ch.getType() << " - " << ch.getName();
	return os;
}

//destructor deletes dice dynamically
Character::~Character() {

	for (int i = 0; i < numAttackDice; i++) {
		delete attackDice[i];
	}
	delete[] attackDice;

	for (int i = 0; i < numDefenseDice; i++) {
		delete defenseDice[i];
	}
	delete[] defenseDice;
}