// Program name: HarryPotter.cpp
// Date: 11/7/19
// Author: Max Veregge
// Description: HarryPotter.cpp contains an implementation of the HarryPotter subclass of Character. HarryPotter
// inherits data members for attacking, defending, armor, and strength from Character and defines
// them in its constructor. HarryPotter implements a basic attack function and a setStrength function that
// captures the Hogwarts ability.

#include "HarryPotter.hpp"

//constructor inherits behavior from parent class Character, then dynamically defines strength, armor, and name of the character
HarryPotter::HarryPotter(int numAttackDice, int attackDiceSides, int numDefenseDice) : Character(numAttackDice, attackDiceSides, numDefenseDice) {
	this->strength = 10;
	this->armor = 0;
	this->name = "Harry Potter";
}

//defend() rolls the characters defense dice, printing out the total of their roll and armor and returning it to the caller
int HarryPotter::defend() {
	int defenseRoll = 0;
	for (int i = 0; i < this->numDefenseDice; i++) {
		defenseRoll += this->defenseDice[i]->roll();
	}
	std::cout << *this << " rolled a " << defenseRoll << ", plus their armor of " << this->armor << "!\n";
	return defenseRoll + this->armor;
}

//attack() rolls the characters attack dice, printing out the total of their roll and returning it to the caller
int HarryPotter::attack() {
	int attackRoll = 0;
	for (int i = 0; i < this->numAttackDice; i++) {
		attackRoll += this->attackDice[i]->roll();
	}
	std::cout << *this << " rolled a " << attackRoll << "!\n";
	return attackRoll;

}

//setStrength takes an integer for the amount of damage to be done, then reduces the character's strength points by that number of damage
//setStrength also implements Harry Potter's Hogwarts ability, which resets strength points to 20 the first time Harry Potter's strength points reach zero
void HarryPotter::setStrength(int damage) {
	this->strength -= damage;
	std::cout << *this << " now has " << this->strength << " strength points.\n";

	//if strength points == 0 and Hogwarts has not yet been used, revive Harry Potter and reset Strength points to 20
	if (this->strength <= 0 && hogwarts > 0) {
		std::cout << "Harry Potter is out of strength points! What...? He's coming back to life even stronger than he was before!\n";
		this->strength = 20;
		this->hogwarts = 0;
		std::cout << "Harry Potter now has 20 strength points!\n";
	}
}