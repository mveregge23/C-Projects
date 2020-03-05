// Program name: Game.cpp
// Date: 11/8/19
// Author: Max Veregge
// Description: Game.cpp contains an implementation of Game class. Game contains a menu from which
// a user will pick two characters. Then Game will take those characters and use the playGame
// and playRound functions to have them battle. Once a round is over, the game is terminated and
// the user should be asked if they want to play again.

#include "Game.hpp"

Game::Game() {

	//initialize menu greetings and options for menus
	charMenu.addGreeting("Select a character:");
	charMenu.addOption(1, "Harry Potter");
	charMenu.addOption(2, "Blue Men");
	charMenu.addOption(3, "Barbarian");
	charMenu.addOption(4, "Vampire");
	charMenu.addOption(5, "Medusa");
	losersMenu.addGreeting("\nWould you like to see a list of the losers?");
	losersMenu.addOption(1, "Yes");
	losersMenu.addOption(2, "No");
}

Game::~Game() {
	
}

//playRound() takes both fighters and executes their attacking/defending rolls
int Game::playRound(Character* fighter1, Character* fighter2) {

	//get attack and defense rolls dice
	int f1Attack = fighter1->attack();
	int f2Defend = fighter2->defend();
	
	//calculate damage
	int damage = f1Attack - f2Defend;

	//if damage <= 0 attack fails
	if (damage <= 0) {
		damage = 0;
	}

	//otherwise apply damage
	else {

		//if damage > fighter2's strength, set damage equal to fighter2's strength
		if (damage > fighter2->getStrength()) {
			damage = fighter2->getStrength();
		}

		//apply damange and check if fighter2 died
		fighter2->setStrength(damage);
		if (fighter2->getStrength() <= 0) {
			return 1;
		}
	}

	//get attack and defense rolls dice
	int f2Attack = fighter2->attack();
	int f1Defend = fighter1->defend();

	//calculate damage
	damage = f2Attack - f1Defend;

	//if damage <= 0 attack fails
	if (damage <= 0) {
		damage = 0;
	}

	//otherwise apply damage
	else {

		//if damage > fighter2's strength, set damage equal to fighter2's strength
		if (damage > fighter1->getStrength()) {
			damage = fighter1->getStrength();
		}

		//apply damage and check if figher1 died
		fighter1->setStrength(damage);
		if (fighter1->getStrength() <= 0) {
			return 2;
		}
	}
	
	return 0;

}

//playGame() proceeds through the Game menus, getting the user choices for character types
//and playing rounds until the user no longer wants to play the game
int Game::playGame(Character* fighter1, Character* fighter2) {

	std::cout << "\nOk! TIME TO BATTLE.\n";

	int result = 0;

	//continue playing rounds until one character dies
	do {
		result = playRound(fighter1, fighter2);
	} while (result == 0);

	return result;
}

//initializeChars accepts a number of characters to initialize, and the number of the team for which the characters
//will be initialized, then asks the user for the name and type each character and initializes them in the appropriate queues
void Game::initializeChars(int numChars, int team) {

	for (int i = 0; i < numChars; i++) {

		//get charType and name to initialize characters
		int charType = charMenu.open();
		std::cout << "Enter a name for this character: ";
		std::string name;
		std::getline(std::cin, name);

		switch (charType) {

		//add Harry Potter to the appropriate team
		case HARRY: {

			//check team and add new character
			switch (team) {
			case 1: 
				p1Chars.addBack(new HarryPotter(2, 6, 2, name));
				break;
			case 2:
				p2Chars.addBack(new HarryPotter(2, 6, 2, name));
				break;
			}
			break;
		}
		
		//add Blue Men to the appropriate team
		case BLUEMEN: {

			//check team and add new character
			switch (team) {
			case 1:
				p1Chars.addBack(new BlueMen(2, 6, 2, name));
				break;
			case 2:
				p2Chars.addBack(new BlueMen(2, 6, 2, name));
				break;
			}
			break;
		}
		
		//add Barbarian to the appropriate team
		case BARBARIAN: {

			//check team and add new character
			switch (team) {
			case 1:
				p1Chars.addBack(new Barbarian(2, 6, 2, name));
				break;
			case 2:
				p2Chars.addBack(new Barbarian(2, 6, 2, name));
				break;
			}
			break;
		}
		\
		//add Vampire to the appropriate team
		case VAMPIRE: {

			//check team and add new character
			switch (team) {
			case 1:
				p1Chars.addBack(new Vampire(2, 6, 2, name));
				break;
			case 2:
				p2Chars.addBack(new Vampire(2, 6, 2, name));
				break;
			}
			break;
		}
		
		//add Medusa to the appropriate team
		case MEDUSA: {

			//check team and add new character
			switch (team) {
			case 1:
				p1Chars.addBack(new Medusa(2, 6, 2, name));
				break;
			case 2:
				p2Chars.addBack(new Medusa(2, 6, 2, name));
				break;
			}
			break;
		}
		}
	}
}

void Game::playTournament() {

	//get number of characters for each team
	std::cout << "How many characters would you like to have on Team 1? (Enter  a positive integer): ";
	int numChars1 = getIntInput();
	std::cout << "How many characters would you like to have on Team 2? (Enter a positive integer): ";
	int numChars2 = getIntInput();

	//initialize characters for each team
	std::cout << "Enter your characters for Team 1: \n";
	initializeChars(numChars1, 1);
	std::cout << "Enter your characters for Team 2: \n";
	initializeChars(numChars2, 2);

	//initialize team scores
	int team1Score = 0;
	int team2Score = 0;
	int round = 1;

	//begin tournament loop checking for characters in each queue
	while (!p1Chars.isEmpty() && !p2Chars.isEmpty()) {

		std::cout << "\nRound " << round << "!\n";
		std::cout << "Team 1: " << *p1Chars.getFront() << " vs. Team 2: " << *p2Chars.getFront() << std::endl;

		//play round
		int winningTeam = playGame(p1Chars.getFront(), p2Chars.getFront());
		QueueNode* winnerNode = nullptr;
		QueueNode* loserNode = nullptr;
		Character* winner = nullptr;
		Character* remove = nullptr;

		//check for winning team
		switch (winningTeam) {
		case 1:

			//get winning character and display, then deallocate memory from old QueueNode
			winnerNode = p1Chars.removeFront();
			winner = winnerNode->ch;
			delete winnerNode;
			std::cout << "Team 1: " << *winner << " is the winner!\n";
			
			//increment winning team's score, recover winning character and add to back of queue
			team1Score += 3;
			winner->recover();
			p1Chars.addBack(winner);

			//remove losing character from p2Chars and deallocate QueueNode, then add to losers list
			loserNode = p2Chars.removeFront();
			remove = loserNode->ch;
			delete loserNode;
			losers.push(remove);
			break;

		case 2:

			//get winning character and display
			winnerNode = p2Chars.removeFront();
			winner = winnerNode->ch;
			delete winnerNode;
			std::cout << "Team 2: " << *winner << " is the winner!\n";

			//increment winning team's score, recover winning character and add to back of queue
			team2Score += 3;
			winner->recover();
			p2Chars.addBack(winner);

			//remove losing character from p1Chars and add to losers listo
			loserNode = p1Chars.removeFront();
			remove = loserNode->ch;
			delete loserNode;
			losers.push(remove);
			break;
		}

		round++;
	}

	std::cout << "\nResults of the tournament: \n";
	std::cout << "Team 1: " << team1Score << std::endl;
	std::cout << "Team 2: " << team2Score << std::endl;

	if (team1Score > team2Score) {
		std::cout << "Team 1 is the winner!\n";
	}

	else if (team2Score > team1Score) {
		std::cout << "Team 2 is the winner!\n";
	}

	else {
		std::cout << "It's a tie!\n";
	}

	int choice = losersMenu.open();

	if (choice == 1) {
		std::cout << "\nLosers: \n";
		losers.printStack();
	}

}