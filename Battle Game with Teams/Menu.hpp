// Program name: Menu.hpp
// Author: Max Veregge
// Description: The Menu class represents a menu to facilitate user interaction with a program.
// An instance of the Menu class has a map of options (std::map<int, std::string>* options) that
// can be dynamically managed by another program by adding options (void addOption). The user input (int* userChoice)
// is ultimately returned to the program after the menu is opened and the user input is valiated (int open, bool validateInput, 
// int convertInput).

#ifndef MENU_HPP
#define MENU_HPP

#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>

class Menu {
	private:
		std::string greeting;
		std::map<int, std::string>* options;
		int userChoice;
	public:
		int open();
		void addGreeting(std::string);
		void addOption(int, std::string);
		bool validateInput(std::string);
		int convertInput(std::string);
		~Menu();
		Menu();
};

#endif