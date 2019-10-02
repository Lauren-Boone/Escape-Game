/*****************************************************
File Name: Bedroom.hpp
Name: Lauren boone
Date: 3/5/19
Description: This file contains the class BedRoom
THis class inherit from Space
*******************************************************/
#pragma once
#include <iostream>
#ifndef BEDROOM_HPP
#define BEDROOM_CPP
#include "Space.hpp"
#include <string>
#include "Player.hpp"

class Bedroom : public Space {
protected:
	//std::string specialObj1;
	//std::string specialObj2;
public:
	Bedroom(bool key, bool theifIn, std::string object1, std::string object2, Player* user, std::string roomIn);
	virtual void interact();
};
#endif

