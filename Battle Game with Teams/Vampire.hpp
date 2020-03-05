// Program name: Vampire.hpp
// Date: 11/7/19
// Author: Max Veregge
// Description: Vampire.hpp contains a specification for the Vampire subclass of Character. Vampire
// inherits data members for attacking, defending, armor, and strength from Character and defines
// them in its constructor. Vampire implements an attack function and a defense function with the
// Charm ability.

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "Character.hpp"

class Vampire : public Character {
public:
	Vampire(int, int, int, std::string);
	virtual int attack();
	virtual int defend();
};

#endif
