// Program name: Vampire.cpp
// Date: 11/7/19
// Author: Max Veregge
// Description: Vampire.cpp contains an implementation for the Vampire subclass of Character. Vampire
// inherits data members for attacking, defending, armor, and strength from Character and defines
// them in its constructor. Vampire implements an attack function and a defense function with the
// Charm ability.

#include "Vampire.hpp"

//constructor inherits behavior from parent class Character, then dynamically defines strength, armor, and name of the character
Vampire::Vampire(int numAttackDice, int attackDiceSides, int numDefenseDice, std::string name) : Character(numAttackDice, attackDiceSides, numDefenseDice, name) {
	this->strength = 18;
	this->maxStrength = 18;
	this->armor = 1;
	this->type = "Vampire";
}

//attack() rolls the characters attack dice, printing out the total of their roll and returning it to the caller
int Vampire::attack() {
	int attackRoll = 0;
	for (int i = 0; i < this->numAttackDice; i++) {
		attackRoll += this->attackDice[i]->roll();
	}
	return attackRoll;

}

//defend() rolls the characters defense dice, printing out the total of their roll and armor and returning it to the caller
//defend() also implements the Charm ability for Vampire, which returns a max value defense roll that negates all possible attack rolls
int Vampire::defend() {

	//calculate charmChance
	double charmChance = double(rand()) / RAND_MAX;

	int defenseRoll = 0;
	for (int i = 0; i < this->numDefenseDice; i++) {
		defenseRoll += this->defenseDice[i]->roll();
	}

	//if charmChance > 0.5, notify user and return max defense roll
	if (charmChance > 0.5) {
		return 32;
	}

	//otherwise return regular defense roll
	else {
		return defenseRoll + this->armor;
	}
}

