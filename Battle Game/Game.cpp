// Program name: Game.cpp
// Date: 11/8/19
// Author: Max Veregge
// Description: Game.cpp contains an implementation of Game class. Game contains a menu from which
// a user will pick two characters. Then Game will take those characters and use the playGame
// and playRound functions to have them battle. Once a round is over, the game is terminated and
// the user should be asked if they want to play again.

#include "Game.hpp"

Game::Game() {

	//initialize menu greetings and options
	mainMenu.addGreeting("Welcome to Street Fighter: CS162 Edition!");
	mainMenu.addOption(1, "Play the game");
	mainMenu.addOption(2, "Exit");
	charMenu.addOption(1, "Harry Potter");
	charMenu.addOption(2, "Blue Men");
	charMenu.addOption(3, "Barbarian");
	charMenu.addOption(4, "Vampire");
	charMenu.addOption(5, "Medusa");
}

//setFighter1 creates a fighter according to the type provided by the user
void Game::setFighter1(int fighter) {
	switch (fighter) {
	//set fighter1 to Harry Potter
	case HARRY: {
		fighter1 = new HarryPotter(2, 6, 2);
		break;
	}
	//set fighter1 to Blue Men
	case BLUEMEN: {
		fighter1 = new BlueMen(2, 10, 3);
		break;
	}
	//set fighter1 to Barbarian
	case BARBARIAN: {
		fighter1 = new Barbarian(2, 6, 2);
		break;
	}
	//set fighter1 to Vampire
	case VAMPIRE: {
		fighter1 = new Vampire(1, 12, 1);
		break;
	}
	//set fighter1 to Medusa
	case MEDUSA: {
		fighter1 = new Medusa(2, 6, 1);
		break;
	}
	}
}

//setFighter2 creates a fighter according to the type provided by the user
void Game::setFighter2(int fighter) {
	switch (fighter) {
	//set fighter2 to Harry Potter
	case HARRY: {
		fighter2 = new HarryPotter(2, 6, 2);
		break;
	}
	//set fighter2 to Blue Men
	case BLUEMEN: {
		fighter2 = new BlueMen(2, 10, 3);
		break;
	}
	//set fighter2 to Barbarian
	case BARBARIAN: {
		fighter2 = new Barbarian(2, 6, 2);
		break;
	}
	//set fighter2 to Vampire
	case VAMPIRE: {
		fighter2 = new Vampire(1, 12, 1);
		break;
	}
	//set fighter2 to Medusa
	case MEDUSA: {
		fighter2 = new Medusa(2, 6, 1);
		break;
	}
	}
}

//playRound() takes both fighters and executes their attacking/defending rolls
bool Game::playRound() {

	//fighter 1 attacks
	std::cout << "\n" << *fighter1 << " is attacking!\n";

	//fighter 2 defends
	std::cout << *fighter2 << " is defending with " << fighter2->getArmor() << " armor and " << fighter2->getStrength() << " strength points!\n";

	//get attack and defense rolls dice
	int f1Attack = fighter1->attack();
	int f2Defend = fighter2->defend();
	
	//calculate damage
	int damage = f1Attack - f2Defend;

	//if damage <= 0 attack fails
	if (damage <= 0) {
		std::cout << "That results in zero damage! Attack failed!\n";
		damage = 0;
	}

	//otherwise apply damage
	else {

		//if damage > fighter2's strength, set damage equal to fighter2's strength
		if (damage > fighter2->getStrength()) {
			damage = fighter2->getStrength();
		}

		//apply damange and check if fighter2 died
		std::cout << "That results in " << damage << " damage to " << *fighter2 << ".\n";
		fighter2->setStrength(damage);
		if (fighter2->getStrength() <= 0) {
			std::cout << *fighter2 << " died!\n";
			return false;
		}
	}


	//fighter 2 attacks
	std::cout << "\n" << *fighter2 << " is attacking!\n";

	//fighter 1 defends
	std::cout << *fighter1 << " is defending with " << fighter1->getArmor() << " armor and " << fighter1->getStrength() << " strength points!\n";

	//get attack and defense rolls dice
	int f2Attack = fighter2->attack();
	int f1Defend = fighter1->defend();

	//calculate damage
	damage = f2Attack - f1Defend;

	//if damage <= 0 attack fails
	if (damage <= 0) {
		std::cout << "That results in zero damage! Attack failed!\n";
		damage = 0;
	}

	//otherwise apply damage
	else {

		//if damage > fighter2's strength, set damage equal to fighter2's strength
		if (damage > fighter1->getStrength()) {
			damage = fighter1->getStrength();
		}

		//apply damage and check if figher1 died
		std::cout << "That results in " << damage << " damage to " << *fighter1 << ".\n";
		fighter1->setStrength(damage);
		if (fighter1->getStrength() <= 0) {
			std::cout << *fighter1 << " died!\n";
			return false;
		}
	}
	
	return true;

}

//playGame() proceeds through the Game menus, getting the user choices for character types
//and playing rounds until the user no longer wants to play the game
void Game::playGame() {
	
	//get user choice
	int choice = mainMenu.open();

	//if user wants to play the game, continue
	while (choice != 2) {

		//get both characters
		std::cout << "Select two characters:";
		int char1 = charMenu.open();
		int char2 = charMenu.open();

		//set Game fighters
		this->setFighter1(char1);
		this->setFighter2(char2);

		std::cout << "\nOk! TIME TO BATTLE.\n";

		//continue playing rounds until one character dies
		while (playRound()) {
			std::cout << "\nPress enter to play the next round...\n";
			std::cin.ignore();
		}

		//delete characters
		delete fighter1;
		delete fighter2;

		//see if user wants to play again
		choice = mainMenu.open();
	}

}