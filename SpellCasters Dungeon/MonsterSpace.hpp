// Program name: MonsterSpace.hpp
// Date: 12/9/19
// Author: Max Veregge
// Description: MonsterSpace.hpp contains a specification for the derived
// MonsterSpace class. MonsterSpace inherits most data members and functions
// from the Space parent class, but defines its own monster data member, and 
// a constructor and accessor to manage it. 

#ifndef MONSTERSPACE_HPP
#define MONSTERSPACE_HPP

#include "Space.hpp"
#include "Monster.hpp"

class MonsterSpace : public Space
{
private:
	Monster* monster;
public:
	MonsterSpace(Monster*);
	~MonsterSpace();
	virtual void interact();
	Monster* getMonster();
};

#endif
