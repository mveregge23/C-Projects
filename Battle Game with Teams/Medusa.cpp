// Program name: Medusa.cpp
// Date: 11/7/19
// Author: Max Veregge
// Description: Medusa.cpp contains an implementation for the Medusa subclass of Character. Medusa
// inherits data members for attacking, defending, armor, and strength from Character and defines
// them in its constructor. Medusa implements an attack function that includes the Glare ability,
// and a basic defense function.

#include "Medusa.hpp"

//constructor inherits behavior from parent class Character, then dynamically defines strength, armor, and name of the character
Medusa::Medusa(int numAttackDice, int attackDiceSides, int numDefenseDice, std::string name) : Character (numAttackDice, attackDiceSides, numDefenseDice, name) {
	this->strength = 8;
	this->maxStrength = 8;
	this->armor = 3;
	this->type = "Medusa";
}

//attack() rolls the characters attack dice, printing out the total of their roll and returning it to the caller
//attack() also implements Medusa's Glare ability, returning a max value attack rolls that beats all defense rolls
int Medusa::attack() {
	int attackRoll = 0;
	for (int i = 0; i < this->numAttackDice; i++) {
		attackRoll += this->attackDice[i]->roll();
	}

	//if attackRoll == 12, implement Glare ability and return max attack roll
	if (attackRoll == 12) {
		return 32;		
	}
	else {
		return attackRoll;
	}
}

//defend() rolls the characters defense dice, printing out the total of their roll and armor and returning it to the caller
int Medusa::defend() {
	int defenseRoll = 0;
	for (int i = 0; i < this->numDefenseDice; i++) {
		defenseRoll += this->defenseDice[i]->roll();
	}
	return defenseRoll + this->armor;
}
