// Program name: SpaceTypes.cpp
// Date: 12/9/19
// Author: Max Veregge
// Description: SpaceTypes.cpp contains a definition for the convertSpaceTypes
// function, which converts an enumerated SpaceType to a string.

#include "SpaceTypes.hpp"

//convertSpaceType takes an enum SpaceType value and converts it to 
//a string
std::string convertSpaceType(SpaceType st) {

	if (st == EMPTY) 
	{
		return "empty";
	}

	else if (st == MONSTER) 
	{
		return "monster";
	}

	else if (st == SPELLSTONE) 
	{
		return "spell stone";
	}

	else if (st == HEALTH) 
	{
		return "health";
	}

	else if (st == PACES) 
	{
		return "steps";
	}

	else 
	{
		return "armor";
	}

}