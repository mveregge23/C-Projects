// Program name: BlueMen.cpp
// Date: 11/7/19
// Author: Max Veregge
// Description: BlueMen.cpp contains an implementation for the BlueMen subclass of Character. BlueMen
// inherits data members for attacking, defending, armor, and strength from Character and defines
// them in its constructor. BlueMen implements a basic attack function and defense function.

#include "BlueMen.hpp"

//constructor inherits behavior from parent class Character, then dynamically defines strength, armor, and name of the character
BlueMen::BlueMen(int numAttackDice, int attackDiceSides, int numDefenseDice, std::string name) : Character(numAttackDice, attackDiceSides, numDefenseDice, name) {
	this->strength = 12;
	this->maxStrength = 12;
	this->armor = 3;
	this->type = "Blue Men";
}

//defend() rolls the characters defense dice, printing out the total of their roll and armor and returning it to the caller
int BlueMen::defend() {
	int defenseRoll = 0;
	for (int i = 0; i < this->numDefenseDice; i++) {
		defenseRoll += this->defenseDice[i]->roll();
	}
	return defenseRoll + this->armor;
}

//attack() rolls the characters attack dice, printing out the total of their roll and returning it to the caller
int BlueMen::attack() {
	int attackRoll = 0;
	for (int i = 0; i < this->numAttackDice; i++) {
		attackRoll += this->attackDice[i]->roll();
	}
	return attackRoll;

}

//updateDefense() implements Blue Men's Mob ability by checking to see if their strength points are below the threshold for reducing the
//number of defense dice
void BlueMen::updateDefense() {
	if (this->strength <= 4) {
		this->numDefenseDice = 1;
	}
	else if (this->strength <= 8) {
		this->numDefenseDice = 2;
	}
}

//setStrength takes an integer for the amount of damage to be done, then reduces the character's strength points by that number of damage
//setStrength also implements Blue Men's Mob ability by using the updateDefense function
void BlueMen::setStrength(int damage) {
	this->strength -= damage;
	this->updateDefense();
}

