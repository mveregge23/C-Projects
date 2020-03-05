// Program name: Game.cpp
// Date: 12/9/19
// Author: Max Veregge
// Description: Game.cpp contains an implementation of the Game class.
// Game contains a dynamically initialized 2-D board of spaces of different
// types. The Hero moves about the board and interacts with each space
// attempting to gather element essences and stay alive. Once the hero
// gathers an element essence of each type, the game is over.

#include "Game.hpp"

Game::Game()
{
	
	//initialize continueGame
	this->continueGame = true;
	
	//initialize board
	board = new Space * *[10]();
	for (int i = 0; i < 10; i++) {
		board[i] = new Space * [10]();
	}

	//initialize moveMenu
	this->moveMenu.addGreeting("Which way do you want to move?");
	this->moveMenu.addOption(1, "Up");
	this->moveMenu.addOption(2, "Right");
	this->moveMenu.addOption(3, "Down");
	this->moveMenu.addOption(4, "Left");

	//initialize random number generator
	srand(time(NULL));

	//create array of random pairs to represent special spaces on the board
	std::pair<int, int> randPairs[38];

	//fill the array with random pairs
	for (int i = 0; i < 38; i++)
	{
		
		//create variables to test random pairs for randomness
		std::pair<int, int> newPair;
		bool pairAlreadyExists;

		//continue generating random pairs until a unique pair is generated
		do 
		{

			//generate new random pair and set pairAlreadExists to false
			newPair = std::pair<int, int>(rand() % 10, rand() % 10);
			pairAlreadyExists = false;

			//compare to existing random pairs
			for (int i = 0; i < 37; i++) 
			{

				//check if new random pair is equal to the current random pair
				if (randPairs[i] == newPair) 
				{

					//yes: set pairAlreadyExists to true
					pairAlreadyExists = true;
				}
			}

		} while (pairAlreadyExists == true);

		//add new pair to randPairs
		randPairs[i] = newPair;
	}


	Monster* m;

	//initialize fire monster spaces
	for (int i = 0; i < 3; i++) 
	{
		m = new FireMonster();
		board[randPairs[i].first][randPairs[i].second] = new MonsterSpace(m);
	}

	//initialize water monster spaces
	for (int i = 3; i < 6; i++) 
	{
		m = new WaterMonster();
		board[randPairs[i].first][randPairs[i].second] = new MonsterSpace(m);
	}

	//initialize earth monster spaces
	for (int i = 6; i < 9; i++) 
	{
		m = new EarthMonster();
		board[randPairs[i].first][randPairs[i].second] = new MonsterSpace(m);
	}

	//initialize wind monster spaces
	for (int i = 9; i < 12; i++) 
	{
		m = new WindMonster();
		board[randPairs[i].first][randPairs[i].second] = new MonsterSpace(m);
	}


	SpellStone* ss;

	//initialize fire stone spaces
	for (int i = 12; i < 15; i++) 
	{
		ss = new FireStone();
		board[randPairs[i].first][randPairs[i].second] = new SpellStoneSpace(ss);
	}

	//initialize water stone spaces
	for (int i = 15; i < 18; i++) 
	{
		ss = new WaterStone();
		board[randPairs[i].first][randPairs[i].second] = new SpellStoneSpace(ss);
	}

	//initialize earth stone spaces
	for (int i = 18; i < 21; i++) 
	{
		ss = new EarthStone();
		board[randPairs[i].first][randPairs[i].second] = new SpellStoneSpace(ss);
	}

	//initialize wind stone spaces
	for (int i = 21; i < 24; i++) 
	{
		ss = new WindStone();
		board[randPairs[i].first][randPairs[i].second] = new SpellStoneSpace(ss);
	}



	//initialize health spaces
	for (int i = 24; i < 29; i++)
	{
		board[randPairs[i].first][randPairs[i].second] = new HealthSpace(10);
	}



	//initialize pace spaces
	for (int i = 29; i < 34; i++)
	{
		board[randPairs[i].first][randPairs[i].second] = new PaceSpace(10);
	}



	//initialize armor spaces
	board[randPairs[34].first][randPairs[34].second] = new ArmorSpace(new LeatherArmor());
	board[randPairs[35].first][randPairs[35].second] = new ArmorSpace(new ChainmailArmor());
	board[randPairs[36].first][randPairs[36].second] = new ArmorSpace(new PlateArmor());



	//initialize hero coordinates
	this->heroXcoord = randPairs[37].first;
	this->heroYcoord = randPairs[37].second;



	//initialize remaining spaces as empty
	for (int i = 0; i < 10; i++) 
	{
		for (int j = 0; j < 10; j++) 
		{
			if (board[i][j] == nullptr)
			{
				board[i][j] = new EmptySpace();
			}
		}
	}

	//link all spaces on the board
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {

			//check if it is the first or last row
			if (i == 0) 
			{
				board[i][j]->setNeighbor(NORTH, nullptr);
				board[i][j]->setNeighbor(SOUTH, board[i + 1][j]);
			}
			else if (i == 9)
			{
				board[i][j]->setNeighbor(NORTH, board[i - 1][j]);
				board[i][j]->setNeighbor(SOUTH, nullptr);
			}
			else
			{
				board[i][j]->setNeighbor(NORTH, board[i - 1][j]);
				board[i][j]->setNeighbor(SOUTH, board[i + 1][j]);
			}

			//check if it is the first or last column
			if (j == 0)
			{
				board[i][j]->setNeighbor(WEST, nullptr);
				board[i][j]->setNeighbor(EAST, board[i][j + 1]);
			}
			else if (j == 9)
			{
				board[i][j]->setNeighbor(WEST, board[i][j - 1]);
				board[i][j]->setNeighbor(EAST, nullptr);
			}
			else
			{
				board[i][j]->setNeighbor(WEST, board[i][j - 1]);
				board[i][j]->setNeighbor(EAST, board[i][j + 1]);
			}
		}
	}
}


//destructor deallocates memory for every space on the board
Game::~Game()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{

			board[i][j]->setNeighbor(NORTH, nullptr);
			board[i][j]->setNeighbor(EAST, nullptr);
			board[i][j]->setNeighbor(SOUTH, nullptr);
			board[i][j]->setNeighbor(WEST, nullptr);
			delete board[i][j];
		}
		delete board[i];
	};
	delete board;
}


//moveHero moves the hero data member about the board and executes different
//behavior depending on the type of space the hero moves to. returns true if
//the hero can make another move, and false if not
bool Game::moveHero()
{

	//check if hero has any remaining steps
	if (hero.getPaces() <= 0)
	{
		std::cout << "Oh no... You're out of paces! Game over...";
		return false;
	}

	//get direction of movement & corresponding neighbor
	Direction moveDir = static_cast<Direction>(moveMenu.open() - 1);
	Space* neighbor = board[this->heroXcoord][this->heroYcoord]->getNeighbor(moveDir);

	//check if direction results in movement off the board
	while (neighbor == nullptr)
	{

		//yes: notify user and get another move
		std::cout << "Invalid move! Head back toward the center of the board.\n";
		moveDir = static_cast<Direction>(moveMenu.open() - 1);
		neighbor = board[this->heroXcoord][this->heroYcoord]->getNeighbor(moveDir);
	}

	//update hero coordinates
	switch (moveDir)
	{
	case NORTH:
	{
		this->heroXcoord -= 1;
		break;
	}
	case EAST:
	{
		this->heroYcoord += 1;
		break;
	}
	case SOUTH:
	{
		this->heroXcoord += 1;
		break;
	}
	case WEST:
	{
		this->heroYcoord -= 1;
		break;
	}
	}

	//decrement paces
	hero.setPaces(-1);

	//interact with space to display message to user 
	neighbor->interact();

	//execute different behavior based on the type of space
	switch (neighbor->getType())
	{
	case EMPTY:
	{
			
		//empty space, no specific behavior
		break;
	}
	case MONSTER:
	{

		//battle the monster
		bool result = battleMonster(static_cast<MonsterSpace*>(neighbor)->getMonster());
			
		//check if hero lost
		if (!result)
		{

			//yes: return false
			return false;
		}

		//check if monster is out of hp
		else if (static_cast<MonsterSpace*>(neighbor)->getMonster()->getHp() <= 0)
		{

			//yes: convert to empty space
			this->convertToEmpty(neighbor);
		}

		break;
	}
	case SPELLSTONE:
	{

		//attempt to pick up the spell stone and convert the space to empty
		SpellStone* stone = static_cast<SpellStoneSpace*>(neighbor)->getStone();
		bool result = hero.addStone(stone);
		if (result)
		{
			//yes (picked up stone): convert to empty
			this->convertToEmpty(neighbor);
		}

		//no: pass stone back to space
		else
		{
			static_cast<SpellStoneSpace*>(neighbor)->addStone(stone);
		}
		break;
	}
	case HEALTH:
	{

		//pick up the health boost and convert the space to empty
		hero.setHp(static_cast<HealthSpace*>(neighbor)->getHealthBoost());
		this->convertToEmpty(neighbor);
		break;
	}
	case PACES:
	{

		//pick up the pace boost and convert the space to empty
		hero.setPaces(static_cast<PaceSpace*>(neighbor)->getPaceBoost());
		this->convertToEmpty(neighbor);
		break;
	}
	case ARMOR:
	{

		//attempt to pick up the armor and convert the space to empty
		Armor* armor = static_cast<ArmorSpace*>(neighbor)->getArmor();
		bool result = hero.setArmor(armor);
		if (result)
		{

			//yes (picked up armor): convert to empty
			this->convertToEmpty(neighbor);
		}

		//no: pass armor back to space
		else
		{
			static_cast<ArmorSpace*>(neighbor)->addArmor(armor);
		}
		break;
	}
	}
	
	return true;
}


//convertToEmpty takes a reference to a space and converts it o
//an empty space
void Game::convertToEmpty(Space* s)
{

	//create new empty space and pointer for neighbor
	EmptySpace* e = new EmptySpace();
	Space* neighbor;

	//iterate through each direction to update pointers
	for (int i = 0; i < 4; i++)
	{

		//get neighbor in current direction & check if == nullptr
		neighbor = s->getNeighbor(static_cast<Direction>(i));

		if (neighbor == nullptr)
		{

			//yes: set neighbor in current direction of new empty space 
			//to nullptr and continue to next direction
			e->setNeighbor(static_cast<Direction>(i), nullptr);
			continue;
		}

		//no: update pointers for neighbor, new empty space, and current space
		else
		{

			//update pointers for new empty space
			e->setNeighbor(static_cast<Direction>(i), neighbor);
			
			//check current direction and update neighbor to point to new empty space
			if (i <= 1)
			{
				neighbor->setNeighbor(static_cast<Direction>(i + 2), e);
			}
			else if (i >= 2)
			{
				neighbor->setNeighbor(static_cast<Direction>(i - 2), e);
			}

			//update old space to point to nullptr
			s->setNeighbor(static_cast<Direction>(i), nullptr);
		}
	}

	//put new space into board and deallocate memory for old space
	board[this->heroXcoord][this->heroYcoord] = e;
	delete s;
}


//battleMonster battles the Hero with a monster passed to the function, then
//returns true if the user wins the battle and false if they lose
bool Game::battleMonster(Monster* m)
{

	//initiate battle
	bool continueBattle = true;

	//continue battle while continueBattle is true
	while (continueBattle)
	{

		//check if hero has spellstones
		if (hero.getNumStones() <= 0)
		{

			//no: notify the user they can't fight until they have a spell stone
			//and return true to continue
			std::cout << "You don't have any spell stones! You can't fight this "
				<< *m << ". Go find some spell stones (S on the map) and "
				<< "come back later.\n";
			return true;
		}

		//create menu of stones the user can choose from
		Menu stoneMenu;
		for (int i = 0; i < hero.getNumStones(); i++)
		{ 
			stoneMenu.addOption(i + 1, hero.getSpellStone(i)->getName() + ", " +
				std::to_string(hero.getSpellStone(i)->getUses()) + " uses remaining");
		}

		//get user choice of stone
		std::cout << "Pick a spell stone to attack: ";
		int stoneChoice = stoneMenu.open() - 1;
		SpellStone* attackStone = hero.getSpellStone(stoneChoice);

		//attack monster with stone
		std::cout << "Ok, attacking with your " << *attackStone << ".\n";
		continueBattle = m->takeDamage(attackStone->getDamage(), attackStone->getType());
		
		//decrement remaining uses for stone and check if it has any remaining uses
		int remainingUses = attackStone->useStone();
		if (remainingUses <= 0)
		{

			//yes: notify user and remove stone
			std::cout << "Your " << *attackStone << " is out of uses!\n";
			hero.removeStone(stoneChoice);
		}

		std::cout << "Press enter to continue the battle...";
		std::cin.ignore();

		//check if monster was defeated
		if (continueBattle == false) 
		{

			//yes: notify user, add essence to pack, and return true
			std::cout << "You defeated the " << *m << "!\n";
			std::cout << "Adding one " << convertElement(m->getType()) << " essence to your pack.\n";
			this->continueGame = !(hero.addElement(m->getType()));
			return true;
		}

		//no: allow monster to attack
		std::cout << "The " << *m << " is attacking!\n";
		continueBattle = hero.takeDamage(m->getDamage());

		//check: hero was defeated
		if (continueBattle == false)
		{

			//yes: notify the user and return false
			std::cout << "Oh no...you're out of health! Game over...\n";
			return false;
		}

		//battle continues
		std::cout << "Press enter to continue the battle...";
		std::cin.ignore();
	}

}


//playGame introduces the user to the game and executes the movement
//loop until the user can no longer make any moves
void Game::playGame()
{
	std::cout << "Welcome to SpellCaster's Dungeon!\n";
	std::cout << "In search of artifacts, you ventured into an ancient dungeon...\n";
	std::cout << "Unbeknownst to you, the dungeon is cursed!\n";
	std::cout << "Your presence has angered the dungeon monsters, and they've locked you in!\n";
	std::cout << "You notice the door has four symbols on it: a ball of fire, "
		<< " an ocean wave, a towering mountain, and a whirling tornado...";
	std::cout << "...Fire, Water, Earth, Wind! These are the four essences required to open the door.\n";
	std::cout << "Each monster has one of the essences -- you need to defeat one monster of each type "
		<< "to gather all of the essences necessary to unlock the door.\n";
	std::cout << "You are not powerful enough to fight these monsters alone -- you need the help of the "
		<< "ancient spell stones left here by the dungeon masters.\n";
	std::cout << "Move about the dungeon to collect spell stones, armor, health, and paces, then take on "
		<< "the monsters to secure your freedom!\n";
	std::cout << "If you run out of health or paces, you're locked in forever!\n";
	std::cout << "* = Hero, M = Monster, S = Spell Stone, H = Health, P = Paces, A = Armor\n";
	std::cout << "Press Enter to begin...";
	std::cin.ignore();
	

	//continue making moves until the hero can  no longer move
	do
	{
		std::cout << "\n\n\n";
		this->printBoard();
	} while (this->moveHero() && continueGame);
}


//printBoard prints the board in its current state
void Game::printBoard()
{

	//create loop with 2 extra iterations for borders of board
	for (int i = 0; i < 12; i++)
	{

		//check if printing the first row or last row
		if (i == 0 || i == 11) {

			//yes: print a border and continue to next iteration
			std::cout << "------------\n";
			continue;
		}

		//no: enter next loop
		for (int j = 0; j < 12; j++)
		{

			//check if printing the first or last column
			if (j == 0 || j == 11) 
			{

				//yes: print a border and continue to next iteration
				std::cout << "|";
				continue;
			}

			//no: print space
			else {

				//check if hero is on current space
				if (this->heroXcoord == i - 1 && this->heroYcoord == j - 1)
				{

					//yes: print H for hero
					std::cout << "*";
				}

				//no: get space type and print accordingly
				else {
					
					SpaceType st = board[i - 1][j - 1]->getType();

					//print space based on type
					switch (st)
					{
					case EMPTY:
					{
						std::cout << " ";
						break;
					}
					case MONSTER:
					{
						std::cout << "M";
						break;
					}
					case SPELLSTONE:
					{
						std::cout << "S";
						break;
					}
					case HEALTH:
					{
						std::cout << "H";
						break;
					}
					case PACES:
					{
						std::cout << "P";
						break;
					}
					case ARMOR:
					{
						std::cout << "A";
						break;
					}
					}
				}
			}
		}

		std::cout << "\n";
	}
}