// Program name: Barbarian.hpp
// Date: 11/7/19
// Author: Max Veregge
// Description: Barbarian.hpp contains a specification for the Barbarian subclass of Character. Barbarian
// inherits data members for attacking, defending, armor, and strength from Character and defines
// them in its constructor. Barbarian implements a basic attack function and defense function.

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "Character.hpp"

class Barbarian : public Character {
public:
	Barbarian(int, int, int, std::string);
	virtual int attack();
	virtual int defend();
};

#endif