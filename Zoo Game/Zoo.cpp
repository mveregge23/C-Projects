//Program name: Zoo.cpp
//Date: 10/25/19
//Author: Max Veregge
//Description: Zoo.cpp contains a specification for the Zoo class. The Zoo class represents a zoo game, where
//the user is responsible for managing a zoo with three different types of animals: tigers, penguins, and turtles.
//There are data members that represent the actual animals, the number of each type of animal, and the size
//of the data structures containing the actual animals. There are also data members to handle the financials
//of the zoo's current cash balance, daily profit, and daily bonuses. The member functions of zoo help to 
//automate the daily processes, including buying animals, handling the data structures that contain the animals,
//and producing random events that happen each day in the zoo.

#include "Zoo.hpp"

//constructor initializes member variables and menus
Zoo::Zoo() {

	//initializing member variables for zoo animal and financial management
	balance = 100000;
	bonus = 0;
	profit = 0;
	numTigers = 0;
	numPenguins = 0;
	numTurtles = 0;
	sizeTigers = 10;
	sizeTurtles = 10;
	sizePenguins = 10;
	
	//initializing menus for gameplay
	buyTigersMenu.addGreeting("\nTo start the game, you need to buy 1 or 2 tigers.");
	buyTigersMenu.addOption(1, "Buy 1 tiger");
	buyTigersMenu.addOption(2, "Buy 2 tigers");
	buyPenguinsMenu.addGreeting("\nTo start the game, you need to buy 1 or 2 penguins.");
	buyPenguinsMenu.addOption(1, "Buy 1 penguin");
	buyPenguinsMenu.addOption(2, "Buy 2 penguins");
	buyTurtlesMenu.addGreeting("\nTo start the game, you need to buy 1 or 2 turtles");
	buyTurtlesMenu.addOption(1, "Buy 1 turtle");
	buyTurtlesMenu.addOption(2, "Buy 2 turtles");
	buyAnimalMenu.addGreeting("\nWould you like to buy an adult animal?");
	buyAnimalMenu.addOption(1, "Buy an adult animal");
	buyAnimalMenu.addOption(2, "Do not buy an adult animal");
	animalTypeMenu.addGreeting("\nWhat type of animal would you like to buy?");
	animalTypeMenu.addOption(1, "Tiger - $10000");
	animalTypeMenu.addOption(2, "Penguin - $1000");
	animalTypeMenu.addOption(3, "Turtle - $100");
	endOfDayMenu.addGreeting("\nThe day is over! Would you like to keep playing?");
	endOfDayMenu.addOption(1, "Continue playing");
	endOfDayMenu.addOption(2, "End the game");

}


//playTurn walks through the steps of each day in the zoo, starting with increasing the age of each animal
//and paying their feeding costs, then executing a random event, then adding the profit to the bank, then
//asking the user if they would like to buy a new animal. at the end of the turn, playTurn will ask the user if
//they want to keep playing, and return 1 or 2 depending if they answer yes or no.

int Zoo::playTurn() {

	//reset daily profit to 0
	profit = 0;

	std::cout << "\nAh... another beautiful day at the zoo.\n";

	//increment ages of each animal and notify user if an animal of any type became an adult
	for (int i = 0; i < numTigers; i++) {
		if (tigers[i]->incAge() == 3) {
			std::cout << "One your tigers became an adult!\n";
		}
	}

	for (int i = 0; i < numPenguins; i++) {
		if (penguins[i]->incAge() == 3) {
			std::cout << "One of your penguins became an adult!\n";
		}
	}

	for (int i = 0; i < numTurtles; i++) {
		if (turtles[i]->incAge() == 3) {
			std::wcout << "One of your turtles became an adult!\n";
		}
	}

	std::cout << "\nTime to feed the animals!\n";

	//feed animals and notify user of cost
	int tigerFoodCost = numTigers * Tiger::foodCost;
	std::cout << "We have " << numTigers << " tigers to feed. That will cost " << tigerFoodCost << ".\n";
	balance -= tigerFoodCost;

	int penguinFoodCost = numPenguins * Penguin::foodCost;
	std::cout << "We have " << numPenguins << " penguins to feed. That will cost " << penguinFoodCost << ".\n";
	balance -= penguinFoodCost;

	int turtleFoodCost = numTurtles * Turtle::foodCost;
	std::cout << "We have " << numTurtles << " turtles to feed. That will cost " << turtleFoodCost << ".\n";
	balance -= turtleFoodCost;

	std::cout << "I wish I ate as well as these animals... Food costs for the day totaled $" << tigerFoodCost + penguinFoodCost + turtleFoodCost
		<< " and the resulting balance is $" << balance << ".\n";

	//execute random event
	randomEvent();

	//calculate daily profit and add to the balance
	int dailyPayoff = (numTigers * Tiger::payoff + numPenguins * Penguin::payoff + numTurtles * Turtle::payoff);
	profit += dailyPayoff;
	balance += profit;
	std::cout << "\nAnimal payoff today was $" << dailyPayoff << ", resulting in a total daily profit of $" 
		<< profit << ". End of day balance: $" << balance << ".\n";

	//if balance <= 0 end the game
	if (balance <= 0) {
		std::cout << "Uh oh! You're out of money! Game over.";
		return 2;
	}

	else {

		//initialize variables for animal buying process
		int choice;
		int animalType;
		bool buySuccess = false;

		while (!buySuccess) {

			//ask user if they want to buy animal
			choice = buyAnimalMenu.open();

			if (choice == 1) {

				//attempt to buy animal
				animalType = animalTypeMenu.open();

				switch (animalType) {
				case TIGER:
					buySuccess = buyAnimal(TIGER, 3);
					break;
				case PENGUIN:
					buySuccess = buyAnimal(PENGUIN, 3);
					break;
				case TURTLE:
					buySuccess = buyAnimal(TURTLE, 3);
					break;
				}
			}

			else {
				buySuccess = true;
			}

		}

		//end the day and ask user if they want to continue playing
		return endOfDayMenu.open();
	}
	
}

//buyAnimal buys an animal of the given type and updates the appropriate member variables
bool Zoo::buyAnimal(enum ANIMAL_TYPE animalType, int age) {

	switch (animalType) {
		
	case TIGER: {

		//if number of animals is equal to size of array, resize array
		if (numTigers == sizeTigers) {
			resize(tigers, TIGER);
		}

		if (balance - Tiger::cost < 0) {
			std::cout << "You don't have enough money to buy that animal!\n";
			return false;
		}

		//add new animals to animal array, update the count, and deduct the balance
		tigers[numTigers] = new Tiger(age);
		numTigers += 1;
		balance -= Tiger::cost;
		std::cout << "You bought a tiger! You now have " << numTigers << " tiger(s) and your remaining balance is $" << balance << ".\n";
		break;
	}

	case PENGUIN: {

		//if number of animals is equal to size of array, resize array
		if (numPenguins == sizePenguins) {
			resize(penguins, PENGUIN);
		}

		if (balance - Penguin::cost < 0) {
			std::cout << "You don't have enough money to buy that animal!\n";
			return false;
		}

		//add new animals to animal array, update the count, and deduct the balance
		penguins[numPenguins] = new Penguin(age);
		numPenguins += 1;
		balance -= Penguin::cost;
		std::cout << "You bought a penguin! You now have " << numPenguins << " penguin(s) and your remaining balance is $" << balance << ".\n";
		break;
	}

	case TURTLE: {

		//if number of animals is equal to size of array, resize array
		if (numTurtles == sizeTurtles) {
			resize(turtles, TURTLE);
		}

		if (balance - Turtle::cost < 0) {
			std::cout << "You don't have enough money to buy that animal!\n";
			return false;
		}

		//add new animals to animal array, update the count, and deduct the balance
		turtles[numTurtles] = new Turtle(age);
		numTurtles += 1;
		balance -= Turtle::cost;
		std::cout << "You bought a penguin! You now have " << numTurtles << " turtle(s) and your remaining balance is $" << balance << ".\n";
		break;
	}

	};

	return true;

}

//startGame initializes the balance back to 100000, then asks the user to buy 1 or 2 of each animal type
void Zoo::startGame() {

	//re-initialize balance back to 100000
	balance = 100000;
	std::cout << "Welcome to your new zoo! Your starting cash balance is $" << balance << "\n";

	//ask user how many tigers they'd like to buy and buy that many tigers
	int buyTigers = buyTigersMenu.open();
	for (int i = 0; i < buyTigers; i++) {
		buyAnimal(TIGER, 1);
	}

	//ask user how many penguins they'd like to buy and buy that many penguins
	int buyPenguins = buyPenguinsMenu.open();
	for (int i = 0; i < buyPenguins; i++) {
		buyAnimal(PENGUIN, 1);
	}

	//ask user how many turtles they'd like to buy and buy that many turtles
	int buyTurtles = buyTurtlesMenu.open();
	for (int i = 0; i < buyTurtles; i++) {
		buyAnimal(TURTLE, 1);
	}

	//tell the user how many of each type of animal they bought
	std::cout << "Ok! You have " << numTigers << " tigers, " << numPenguins << " penguins, and " << numTurtles << " turtles. Let's play!\n";

}

//randomEvent picks a RANDOM_EVENT type at random and attempts to execute it -- if it fails it picks another random event
//type to execute until it is successful
void Zoo::randomEvent() {

	//set loop flag and initialize event type
	bool eventSuccess = false;
	int eventType;

	//while the event is unsuccessful, continue trying to execute a random event
	while (!eventSuccess) {

		//choose an event type at random
		eventType = rand() % 3 + 1;

		switch (eventType) {

		case SICKNESS: {
			

			//attempt to remove an animal from the zoo
			eventSuccess = sickness();
			break;

		}

		case BOOM: {

			//calculate a bonus
			eventSuccess = boom();
			break;
		}

		case BABY: {

			//attempt to produce a baby animal
			eventSuccess = baby();
			break;

		}

		}

	}

}

//sickness picks an animal type at random and attempts to remove it from the zoo -- if successful it returns true, if there are 
//no animals of that type it returns false so the program can pick another random event to occur
bool Zoo::sickness() {

	int animalType = rand() % 3 + 1;

	switch (animalType) {

	case TIGER: {

		//if animal exists, delete one of them and adjust that animal array
		if (numTigers > 0) {
			numTigers--;
			delete tigers[numTigers];
			std::cout << "\nOh no! One of your tigers got sick and died. You have " << numTigers << " tigers remaining.\n";
			break;
		}

		else {

			return false;
		
		}
	}
	case PENGUIN: {

		//if animal exists, delete one of them and adjust that animal array
		if (numPenguins > 0) {
			numPenguins--;
			delete penguins[numPenguins];
			std::cout << "\nOh no! One of your penguins got sick and died. You have " << numPenguins << " penguins remaining.\n";
			break;
		}

		else {

			
			return false;
		}
	}
	case TURTLE: {

		//if animal exists, delete one of them and adjust that animal array
		if (numTurtles > 0) {
			numTurtles--;
			delete turtles[numTurtles];
			std::cout << "\nOh no! One of your turtles got sick and died. You have " << numTurtles << " turtles remaining.\n";
			break;
		}

		else {

			return false;
		
		}
	}

	}

	return true;

}

//boom generates a random number between 250 and 500, then multiplies it by the number of 
//tigers in the zoo and sets bonus equal to that number 
bool Zoo::boom() {
	bonus = rand() % 250 + 250;
	profit += (numTigers * bonus);

	std::cout << "\nBusiness is boomin'! You made an extra $" << bonus 
		<< " dollars per tiger today, resulting in a current profit of $" << profit << " today!\n";

	return true;
}

//baby generates a random number to indicate the type of animal that is to have a baby.
//if that type of animal exists in the zoo and is of age to have a baby, it creates a new 
//baby animal of that type and returns true. if that type of animal does not exist or is
//not of age to have a baby, it returns false so the program can pick another random event
bool Zoo::baby() {

	int animalType = rand() % 3 + 1;
	bool isAdult = false;

	switch (animalType) {

	case TIGER:

		//check if there is an animal of the necessary age to have a baby
		for (int i = 0; i < numTigers; i++) {
			
			if (tigers[i]->isAdult()) {
				isAdult = true;
			}

		}

		if (isAdult) {

			//check if array of that animal type needs to be resized
			if (numTigers == sizeTigers) {
				resize(tigers, TIGER);
			}

			//add new animals to animal array, update the count, and deduct the balance
			tigers[numTigers] = new Tiger();
			numTigers += 1;

			std::cout << "\nOne of your tigers had a baby! Now you have " << numTigers << " tigers.\n";

			return true;
		}

		//continue to next type of animal if no adults

	case PENGUIN: {

		//check if there is an animal of the necessary age to have a baby
		for (int i = 0; i < numPenguins; i++) {

			if (penguins[i]->isAdult()) {
				isAdult = true;
			}
		}

		if (isAdult) {

			for (int baby = 0; baby < Penguin::babies; baby++) {

				//check if array of that animal type needs to be resized
				if (numPenguins == sizePenguins) {
					resize(penguins, PENGUIN);
				}

				//add new animals to animal array, update the count, and deduct the balance
				penguins[numPenguins] = new Penguin();
				numPenguins += 1;

			}

			std::cout << "\nOne of your penguins had babies! Now you have " << numPenguins << " penguins.\n";

			return true;
		}

		//continue to next type of animal if no adults

	}

	case TURTLE: {

		//check if there is an animal of the necessary age to have a baby
		for (int i = 0; i < numTurtles; i++) {

			if (turtles[i]->isAdult()) {
				isAdult = true;
			}
		}

		if (isAdult) {

			for (int baby = 0; baby < Turtle::babies; baby++) {

				//check if array of that animal type needs to be resized
				if (numTurtles == sizeTurtles) {
					resize(turtles, TURTLE);
				}

				//add new animals to animal array, update the count, and deduct the balance
				turtles[numTurtles] = new Turtle();
				numTurtles += 1;

			}

			std::cout << "\nOne of your turtles had babies! Now you have " << numTurtles << " turtles.\n";

			return true;
		}

		//continue out of switch statement if no adults, causing new random event to be picked
	}

	}

	return false;

}

//resize takes an array of pointers to animals & the type of animal and doubles the size of that array of pointers
void Zoo::resize(Animal**& arr, enum ANIMAL_TYPE animalType) {

	switch (animalType) {

	case TIGER: {

		//double size, create new array of that size, and copy old array to new one
		const int newSize = sizeTigers * 2;
		Animal** newTigers = new Animal*[newSize]();

		//set temp array contents to same as old array and delete old array
		for (int i = 0; i < numTigers; i++) {
			newTigers[i] = arr[i];
		}

		delete[] arr;

		//set old array equal to new one
		arr = newTigers;
		newTigers = nullptr;
		sizeTigers *= 2;

		break;
	}

	case PENGUIN: {

		//double size, create new array of that size, and copy old array to new one
		const int newSize = sizePenguins * 2;
		Animal** newPenguins = new Animal*[newSize]();
		
		//set temp array contents to same as old array and delete old array
		for (int i = 0; i < numPenguins; i++) {
			newPenguins[i] = arr[i];
		}

		delete[] arr;

		//set old array equal to new one
		arr = newPenguins;
		newPenguins = nullptr;
		sizePenguins *= 2;

		break;
	}

	case TURTLE: {

		//double size, create new array of that size, and copy old array to new one
		const int newSize = sizeTurtles * 2;
		Animal** newTurtles = new Animal*[newSize]();

		//set temp array contents to same as old array and delete old array
		for (int i = 0; i < numTurtles; i++) {
			newTurtles[i] = arr[i];
		}

		delete[] arr;

		//set old array equal to new one
		arr = newTurtles;
		newTurtles = nullptr;
		sizeTurtles *= 2;

		break;
	}

	}

}

Zoo::~Zoo() {
	for (int i = 0; i < numTigers; i++) {
		delete tigers[i];
	}
	delete[] tigers;

	for (int i = 0; i < numPenguins; i++) {
		delete penguins[i];
	}
	delete[] penguins;

	for (int i = 0; i < numTurtles; i++) {
		delete turtles[i];
	}
	delete[] turtles;
}