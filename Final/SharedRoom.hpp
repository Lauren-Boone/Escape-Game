/*****************************************************
File Name: SharedRoom.hpp
Name: Lauren boone
Date: 3/5/19
Description: This file contains the class SharedRoom
THis class inherit from Space
*******************************************************/
//#pragma once
#include <iostream>
#include "Space.hpp"
#ifndef SHAREDROOM_HPP
#define SHAREDROOM_HPP
#include "Player.hpp"
#include <string>

class SharedRoom : public Space
{
protected:
public:
	SharedRoom(bool key, bool theifIn, std::string object1, std::string object2, Player* user);
	virtual void interact();
};
#endif