// Program name: HarryPotter.cpp
// Date: 11/7/19
// Author: Max Veregge
// Description: HarryPotter.cpp contains an implementation of the HarryPotter subclass of Character. HarryPotter
// inherits data members for attacking, defending, armor, and strength from Character and defines
// them in its constructor. HarryPotter implements a basic attack function and a setStrength function that
// captures the Hogwarts ability.

#include "HarryPotter.hpp"

//constructor inherits behavior from parent class Character, then dynamically defines strength, armor, and name of the character
HarryPotter::HarryPotter(int numAttackDice, int attackDiceSides, int numDefenseDice, std::string name) : Character(numAttackDice, attackDiceSides, numDefenseDice, name) {
	this->strength = 10;
	this->maxStrength = 10;
	this->armor = 0;
	this->type = "Harry Potter";
}

//defend() rolls the characters defense dice, printing out the total of their roll and armor and returning it to the caller
int HarryPotter::defend() {
	int defenseRoll = 0;
	for (int i = 0; i < this->numDefenseDice; i++) {
		defenseRoll += this->defenseDice[i]->roll();
	}
	return defenseRoll + this->armor;
}

//attack() rolls the characters attack dice, printing out the total of their roll and returning it to the caller
int HarryPotter::attack() {
	int attackRoll = 0;
	for (int i = 0; i < this->numAttackDice; i++) {
		attackRoll += this->attackDice[i]->roll();
	}
	return attackRoll;

}

//setStrength takes an integer for the amount of damage to be done, then reduces the character's strength points by that number of damage
//setStrength also implements Harry Potter's Hogwarts ability, which resets strength points to 20 the first time Harry Potter's strength points reach zero
void HarryPotter::setStrength(int damage) {
	this->strength -= damage;

	//if strength points == 0 and Hogwarts has not yet been used, revive Harry Potter and reset Strength points to 20
	if (this->strength <= 0 && hogwarts > 0) {
		this->strength = 20;
		this->hogwarts = 0;
	}
}