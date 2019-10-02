#pragma once
#include <iostream>
#ifndef MENU_HPP
#define MENU_CPP
#include <string>
#include <vector>
#include <iomanip>


class Menu
{
private:
	std::vector <std::string> menu;

public:
	Menu();
	void addChoice(std::string input);
	void printMenu();
};
#endif
