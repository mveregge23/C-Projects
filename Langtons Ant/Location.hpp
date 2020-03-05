// Program name: Location.h
// Author: Max Veregge
// Description: The Location class represents an x,y coordinate (int xC, int yC). The x and y coordinates
// can be changed (setX, setY) and retrieved (getX, getY).

#ifndef LOCATION_H
#define LOCATION_H

class Location {
	private:
		int xC;
		int yC;
	public:
		void setX(int x);
		void setY(int y);
		int getX();
		int getY();
		Location(int x, int y);
		Location();
};

#endif