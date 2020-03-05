// Program name: Barbarian.cpp
// Date: 11/7/19
// Author: Max Veregge
// Description: Barbarian.cpp contains an implementation for the Barbarian subclass of Character. Barbarian
// inherits data members for attacking, defending, armor, and strength from Character and defines
// them in its constructor. Barbarian implements a basic attack function and defense function.

#include "Barbarian.hpp"

//constructor inherits behavior from parent class Character, then dynamically defines strength, armor, and name of the character
Barbarian::Barbarian(int numAttackDice, int attackDiceSides, int numDefenseDice, std::string name) : Character(numAttackDice, attackDiceSides, numDefenseDice, name) {
	this->strength = 12;
	this->maxStrength = 12;
	this->armor = 0;
	this->type = "Barbarian";
}

//defend() rolls the characters defense dice, printing out the total of their roll and armor and returning it to the caller
int Barbarian::defend() {
	int defenseRoll = 0;
	for (int i = 0; i < this->numDefenseDice; i++) {
		defenseRoll += this->defenseDice[i]->roll();
	}
	return defenseRoll + this->armor;
}

//attack() rolls the characters attack dice, printing out the total of their roll and returning it to the caller
int Barbarian::attack() {
	int attackRoll = 0;
	for (int i = 0; i < this->numAttackDice; i++) {
		attackRoll += this->attackDice[i]->roll();
	}
	return attackRoll;

}