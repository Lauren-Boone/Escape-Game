
/*****************************************************
File Name: Kitchen.hpp
Name: Lauren boone
Date: 3/5/19
Description: This file contains the class Kitchen
THis class inherit from Space
*******************************************************/
//#pragma once
#include <iostream>
#include "Space.hpp"
#ifndef KITCHEN_HPP
#define KITCHEN_HPP
#include <string>
#include "Player.hpp"



class Kitchen : public Space
{
protected:
public:
	Kitchen(bool key, bool theifIn, std::string object1, std::string object2, Player* user);
	virtual void interact();

};
#endif