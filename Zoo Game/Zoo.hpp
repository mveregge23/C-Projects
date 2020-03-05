//Program name: Zoo.hpp
//Date: 10/25/19
//Author: Max Veregge
//Description: Zoo.hpp contains a specification for the Zoo class. The Zoo class represents a zoo game, where
//the user is responsible for managing a zoo with three different types of animals: tigers, penguins, and turtles.
//There are data members that represent the actual animals, the number of each type of animal, and the size
//of the data structures containing the actual animals. There are also data members to handle the financials
//of the zoo's current cash balance, daily profit, and daily bonuses. The member functions of zoo help to 
//automate the daily processes, including buying animals, handling the data structures that contain the animals,
//and producing random events that happen each day in the zoo.

#ifndef ZOO_HPP
#define ZOO_HPP

#include "Menu.hpp"
#include "Animal.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"

enum ANIMAL_TYPE { TIGER = 1, PENGUIN, TURTLE };
enum RANDOM_EVENT { SICKNESS = 1, BOOM, BABY };


class Zoo {
private:
	int balance,
		bonus,
		profit,
		numTigers,
		numPenguins,
		numTurtles,
		sizeTigers,
		sizePenguins,
		sizeTurtles;
	Animal** tigers = new Animal * [10];
	Animal** penguins = new Animal * [10];
	Animal** turtles = new Animal * [10];
	Menu buyTigersMenu;
	Menu buyPenguinsMenu;
	Menu buyTurtlesMenu;
	Menu buyAnimalMenu;
	Menu animalTypeMenu;
	Menu endOfDayMenu;

public:
	Zoo();
	~Zoo();
	void startGame();
	bool buyAnimal(enum ANIMAL_TYPE, int = 0);
	int playTurn();
	void randomEvent();
	bool sickness();
	bool boom();
	bool baby();
	void resize(Animal**&, enum ANIMAL_TYPE);
};

#endif
