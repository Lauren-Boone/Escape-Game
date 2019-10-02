/*****************************************************
File Name: SpecialRoom.hpp
Name: Lauren boone
Date: 3/5/19
Description: This file contains the class Special
THis class inherit from Space
*******************************************************/
//#pragma once
#include <iostream>
#include "Space.hpp"
#ifndef SPECIALROOM_HPP
#define SPECIALROOM_HPP
#include <string>
#include "Player.hpp"

class SpecialRoom : public Space
{
protected:
public:
	SpecialRoom(bool key, bool theifIn, std::string object1, std::string object2, Player* user);
	virtual void interact();
};
#endif