/*****************************************************
File Name: Space.hpp
Name: Lauren boone
Date: 3/5/19
Description: This file contains the class Space
*******************************************************/
//#pragma once
#include <iostream>
#ifndef SPACE_HPP
#define SPACE_HPP
#include "Player.hpp"
#include <string>



class Space {
protected:
	Space* forward;
	Space* back;
	Space* left;
	Space* right;
	//Space* current;
	Player* player;
	bool theif;
	bool requiresKey;
	std::string roomName;
	bool hasDiscovered;
	std::string specialObj1;
	std::string specialObj2;
	//int numThieves;
	bool obj1, obj2; // to make sure the player only interacts once
	//bool wonGame;

public:
	Space();
	~Space();
	bool hasDiscoveredSpace();
	bool getRequiresKey();
	std::string getKeyName();
	bool checkTheif();
	void foundTheif();
	void addRoom(Space* forwardIn, Space* backIn, Space* leftIn, Space* rightIn, std::string nameIn);
	//bool checkWonGame();
	Space* getLeft();
	Space* getRight();
	Space* getForward();
	Space* getBack();
	void movePlayer(Space* &spaceIn);
	//void setCurrent(Space* loction);
	std::string getName();
	virtual void interact() = 0;

	
};
#endif