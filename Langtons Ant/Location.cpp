// Program name: Location.ccp
// Author: Max Veregge
// Description: This is an implementation of the Location class, used to represent the location of an Ant
// on a Board

#include "Location.h"

// setX takes an int to set the xC
void Location::setX(int x) {
	xC = x;
}

// setY takes an int to set the yC
void Location::setY(int y) {
	yC = y;
}

// getX returns the current xC
int Location::getX() {
	return xC;
}

// getY returns the current yC
int Location::getY() {
	return yC;
}

// Location constructor takes two ints to initialize the xC and yC
Location::Location(int x, int y) {
	xC = x;
	yC = y;
}

// Default constructor 
Location::Location() {
	;
}