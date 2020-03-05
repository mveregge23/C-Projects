// Program name: Hero.cpp
// Date: 12/9/19
// Author: Max Veregge
// Description: Hero.cpp contains an implementation of the Hero class. The Hero
// class represents the character that is controlled in the Game class. It has 
// data members for health points (hp), paces, essences of all elements (fire, water
// earth, wind), number of spell stones, actual spell stones, and armor. It has a 
// variety of accessors and mutators for these objects that allow the Hero to interact
// with items on the map.

#include "Hero.hpp"


//default constructor initializes all data members
Hero::Hero()
{
	this->hp = 25;
	this->paces = 25;
	this->fire = 0;
	this->water = 0;
	this->earth = 0;
	this->wind = 0;
	this->numStones = 0;
	this->stones = new SpellStone * [4]();
	this->armor = nullptr;
	this->removeStoneMenu.addGreeting("Would you like to remove a stone?");
	this->removeStoneMenu.addOption(1, "Yes");
	this->removeStoneMenu.addOption(2, "No");
	this->swapArmorMenu.addOption(1, "Yes");
	this->swapArmorMenu.addOption(2, "No");
}


//destructor deallocates memory for all objects held by Hero
Hero::~Hero()
{
	//deallocate memory for SpellStones held by Hero
	for (int i = 0; i < 4; i++) {

		//check if current stone is not equal to nullptr
		if (this->stones[i] != nullptr) 
		{

			//yes: deallocate memory for the stone
			delete this->stones[i];
		}
	}
	delete stones;

	//check if armor is not equal to nullptr
	if (this->armor != nullptr)
	{

		//yes: deallocate memory for the armor
		delete this->armor;
	}
}


//getSpellStone is an accessor for the stones array data member
SpellStone* Hero::getSpellStone(int index)
{
	return this->stones[index];
}


//getArmor is an accessor for the armor data member
Armor* Hero::getArmor()
{
	return this->armor;
}


//getNumStones is an accessor for the numStones data member
int Hero::getNumStones()
{
	return this->numStones;
}


//takeDamage is a mutator for the hp & armor data members that
//takes damage from a monster, reduces it using any armor, and applies
//it to the hero. returns true if hp > 0 and false if hp <= 0 after mutation
bool Hero::takeDamage(int damage)
{

	//check if armor exists
	if (this->armor != nullptr)
	{

		//yes: use the armor to reduce hero damage
		int heroDamage = this->armor->useArmor(damage);
		std::cout << "You took " << heroDamage << " damage.\n";

		//check if armor integrity is <= 0
		if (this->armor->getIntegrity() <= 0)
		{
			
			//yes: notify user and remove armor
			std::cout << "Oh no! Your armor broke!\n";
			this->removeArmor();
		}

		//return setHp
		return this->setHp(-heroDamage);
	}

	//no: apply damage without armor
	else
	{
		std::cout << "You took " << damage << " damage.\n";
		return this->setHp(-damage);
	}
}


//setHp is a mutator for for the hp data member that returns true 
//if hp > 0 after mutation, and false if hp <= 0 after mutation
bool Hero::setHp(int diff)
{

	//check if diff results in hp <= 0
	if (this->hp + diff <= 0) 
	{

		//yes: set hp to 0 and return false
		this->hp = 0;
		std::cout << "You have " << this->hp << " health remaining.\n";
		return false;
	}

	//no: check if diff results in hp >= 50
	else if (this->hp + diff >= 25)
	{

		//yes: set hp to 50 and return true
		this->hp = 25;
		std::cout << "You have " << this->hp << " health remaining.\n";
		return true;
	}

	//no: apply to diff to hp and return true
	else
	{
		this->hp += diff;
		std::cout << "You have " << this->hp << " health remaining.\n";
		return true;
	}
}


//getHp is an accessor for the hp data member
int Hero::getHp() const
{
	return this->hp;
}


//getpaces is an accessor for the paces data member
int Hero::getPaces() const
{
	return this->paces;
}


//addElement is a mutator for the fire/water/earth/wind data members
//that returns true if the user has >= 1 of each type, and false otherwise
bool Hero::addElement(element e)
{

	//increment data member that corresponds to the correct element
	switch (e)
	{
	case FIRE:
	{
		this->fire++;
		break;
	}
	case WATER:
	{
		this->water++;
		break;
	}
	case EARTH:
	{
		this->earth++;
		break;
	}
	case WIND:
	{
		this->wind++;
		break;
	}
	}

	//check if Hero has at least one of each element
	if (this->fire >= 1 && this->water >= 1 && this->earth >= 1 && this->wind >= 1)
	{

		//yes: notify user and return true
		this->printElements();
		std::cout << "You have one of each essence! The door has unlocked!\n";
		return true;
	}

	//no: return false
	else 
	{

		//print current numbers of each type of element and return false
		this->printElements();
		return false;
	}
}


//printElements is a print method to print the number of each type of element
//that the Hero has
void Hero::printElements() const
{
	std::cout << "You have " << this->fire << " fire essences, " << this->water <<
		" water essences, " << this->earth << " earth essences, and " << this->wind <<
		" wind essences.\n";
}


//setPaces is a mutator for the paces data member that returns true if
//paces > 0 after mutation and false if paces <= 0 after mutation
bool Hero::setPaces(int diff)
{

	//check if diff results in paces <= 0
	if (this->paces + diff <= 0)
	{

		//yes: set paces to 0 and return false
		this->paces = 0;
		std::cout << "You have " << this->paces << " paces remaining.\n";
		return false;
	}

	//no: check if diff results in paces >= 100
	else if (this->paces + diff >= 25)
	{

		//yes: set paces to 100 and return true
		this->paces = 25;
		std::cout << "You have " << this->paces << " paces remaining.\n";
		return true;
	}

	//no: apply to diff to paces and return true
	else
	{
		this->paces += diff;
		std::cout << "You have " << this->paces << " paces remaining.\n";
		return true;
	}
}


//addStone is a mutator method for the stones container that checks whether or not
//the container is full, and allows the Hero to remove a stone and replace it with the
//one they found
bool Hero::addStone(SpellStone* ss)
{

	//check if numStones == 4
	if (this->numStones == 4)
	{

		//yes: notify the user that they need to remove a stone
		std::cout << "You already have four spell stones, you need to remove one " <<
			"to pick up this " << *ss << ".\n";

		//ask user if they would like to remove a stone
		int userChoice = this->removeStoneMenu.open();

		//check if user chose to remove a stone
		if (userChoice == 1)
		{

			//yes: initialize stone removal menu
			Menu stoneMenu;
			stoneMenu.addGreeting("Please pick a stone.");
			for (int i = 0; i < numStones; i++)
			{

				//add each stone in the stone container to the menu
				stoneMenu.addOption(i + 1, this->stones[i]->getName() + ", " +
					std::to_string(this->stones[i]->getUses()) + " uses remaining");
			}

			//get user choice for which stone to remove, remove that stone and 
			//decrement numStones
			int removeStone = stoneMenu.open() - 1;
			std::cout << "Ok, removing " << *this->stones[removeStone] << ".\n";
			this->removeStone(removeStone);

			//add the new stone, increment numStones, and return true
			this->stones[numStones] = ss;
			this->numStones++;
			return true;
		}

		//no: leave the stone and continue
		else
		{
			std::cout << "Ok, you can pick the stone up later if you need it.\n";
			return false;
		}

	}

	//no: add the stone to the container, increment numStones, and return true
	else
	{
		this->stones[numStones] = ss;
		this->numStones++;
		std::cout << "You added the " << *ss << " to your pack.\n";
		return true;
	}
}


//removeStone is a method to remove a stone from the Hero's stone
//container and rearrange the remaining stones to occupy the lowest spaces in the 
//stone container
void Hero::removeStone(int index)
{

	//check if stone at index exists
	if (this->stones[index] != nullptr)
	{

		//yes: delete the stone and rearrange the container
		delete this->stones[index];
		this->stones[index] = nullptr;

		//decrement the number of stones variable
		this->numStones--;
		
		for (int i = index; i < 3; i++)
		{
			this->stones[i] = this->stones[i+1];
			this->stones[i+1] = nullptr;
		}
	}
}


//removeArmor is a mutator method that removes and deallocates the memory for the
//armor the Hero is currently wearing
void Hero::removeArmor()
{

	//check if armor is not equal to nullptr
	if (this->armor != nullptr) {

		//yes: delete the armor and set armor to nullptr
		delete this->armor;
		this->armor = nullptr;
	}
}


//setArmor is a mutator method for the armor data member that allows the user to choose
//if they would like to remove their current armor and replace it with the armor they found
bool Hero::setArmor(Armor* a)
{

	//check if armor is not equal to nullptr
	if (this->armor != nullptr)
	{

		//yes: ask user if they want to remove their current armor
		std::cout << "You are already equipped with " << *this->armor << ". Would you like "
			<< "to replace it with " << *a << "?";
		int userChoice = this->swapArmorMenu.open();

		//check if user wants to swap armor
		if (userChoice == 1)
		{

			//yes: swap armor
			delete this->armor;
			this->armor = a;

			std::cout << "You put on the " << *this->armor << ".\n";
			return true;
		}

		//no: leave the armor and return false
		else
		{

			std::cout << "Ok, you can pick up the armor later if you need it.\n";
			return false;
		}
	}

	//no: equip the armor
	else 
	{

		//equip the armor and notify the user
		this->armor = a;
		std::cout << "You put on the " << *this->armor << ".\n";
		return true;
	}
}