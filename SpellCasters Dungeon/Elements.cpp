// Program name: Elements.cpp
// Date: 12/8/19
// Author: Max Veregge
// Description: Elements.hpp contains an impelementation for the convertElement
// function, which converts the enum element data type to a string.

#include "Elements.hpp"

//convertElement takes an enum element data value and converts it to 
//a string
std::string convertElement(element el)
{

	if (el == NEUTRAL) 
	{
		return "neutral";
	}

	else if (el == FIRE) 
	{
		return "fire";
	}

	else if (el == WATER)
	{
		return "water";
	}

	else if (el == EARTH)
	{
		return "earth";
	}

	else if (el == WIND)
	{
		return "wind";
	}
}