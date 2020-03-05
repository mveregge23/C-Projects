// Program name: Hero.hpp
// Date: 12/9/19
// Author: Max Veregge
// Description: Hero.hpp contains a specification for the Hero class. The Hero
// class represents the character that is controlled in the Game class. It has 
// data members for health points (hp), steps, essences of all elements (fire, water
// earth, wind), number of spell stones, actual spell stones, and armor. It has a 
// variety of accessors and mutators for these objects that allow the Hero to interact
// with items on the map.

#ifndef HERO_HPP
#define HERO_HPP

#include <iostream>
#include "Armor.hpp"
#include "SpellStone.hpp"
#include "Menu.hpp"

class Hero
{
private:
	int hp,
		paces,
		fire,
		water,
		earth,
		wind,
		numStones;
	SpellStone** stones;
	Armor* armor;
	Menu removeStoneMenu;
	Menu swapArmorMenu;

public:
	Hero();
	~Hero();
	SpellStone* getSpellStone(int);
	Armor* getArmor();
	int getNumStones();
	bool takeDamage(int);
	bool setHp(int);
	int getHp() const,
		getPaces() const;
	bool setPaces(int);
	bool addElement(element);
	void printElements() const;
	bool addStone(SpellStone*);
	void removeStone(int);
	bool setArmor(Armor*);
	void removeArmor();
};

#endif
