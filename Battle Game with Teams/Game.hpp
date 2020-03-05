// Program name: Game.hpp
// Date: 11/8/19
// Author: Max Veregge
// Description: Game.hpp contains a specification for Game class. Game contains a menu from which
// a user will pick two characters. Then Game will take those characters and use the playGame
// and playRound functions to have them battle. Once a round is over, the game is terminated and
// the user should be asked if they want to play again.

#ifndef GAME_HPP
#define GAME_HPP
#include "Menu.hpp"
#include "Character.hpp"
#include "HarryPotter.hpp"
#include "BlueMen.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "Medusa.hpp"
#include "Queue.hpp"
#include "Stack.hpp"
#include "Validate.hpp"

enum fighters {HARRY = 1, BLUEMEN, BARBARIAN, VAMPIRE, MEDUSA};

class Game {
private:
	Menu charMenu;
	Menu losersMenu;
	Queue p1Chars;
	Queue p2Chars;
	Stack losers;
	void initializeChars(int, int);
public:
	Game();
	~Game();
	int playGame(Character*, Character*);
	int playRound(Character*, Character*);
	void playTournament();
};

#endif
