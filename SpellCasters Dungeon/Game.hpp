// Program name: Game.hpp
// Date: 12/9/19
// Author: Max Veregge
// Description: Game.hpp contains a specification for the Game class.
// Game contains a dynamically initialized 2-D board of spaces of different
// types. The Hero moves about the board and interacts with each space
// attempting to gather element essences and stay alive. Once the hero
// gathers an element essence of each type, the game is over.

#ifndef GAME_HPP
#define GAME_HPP

#include "ArmorSpace.hpp"
#include "EmptySpace.hpp"
#include "MonsterSpace.hpp"
#include "SpellStoneSpace.hpp"
#include "HealthSpace.hpp"
#include "PaceSpace.hpp"
#include "ChainmailArmor.hpp"
#include "LeatherArmor.hpp"
#include "PlateArmor.hpp"
#include "FireMonster.hpp"
#include "WaterMonster.hpp"
#include "EarthMonster.hpp"
#include "WindMonster.hpp"
#include "FireStone.hpp"
#include "WaterStone.hpp"
#include "EarthStone.hpp"
#include "WindStone.hpp"
#include "WaterMonster.hpp"
#include "EarthMonster.hpp"
#include "WindMonster.hpp"
#include "Hero.hpp"
#include <time.h>
#include <iostream>


class Game {
private:
	Space*** board;
	Hero hero;
	int heroXcoord,
		heroYcoord;
	Menu moveMenu;
	bool continueGame;
public:
	bool moveHero();
	bool battleMonster(Monster*);
	void convertToEmpty(Space*);
	void playGame();
	void printBoard();
	Game();
	~Game();
};

#endif
