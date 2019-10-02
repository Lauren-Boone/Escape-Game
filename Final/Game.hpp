/************************************************
File: Game.hpp
Name:Lauren Boone
Description: Tis file contains the class Game
************************************************/
//#pragma once
#include <iostream>
#include "Space.hpp"
#include "Bedroom.hpp"
#include "Player.hpp"
#include "Menu.hpp"
#include <vector>
#ifndef GAME_HPP
#define GAME_HPP

class Game {
private:
	//std::vector <Space*> rooms;
	Space* startRoom;
	Space* kidRoom;
	Space* kitchen;
	Space* closet;
	Space* foyer;
	Space* study;
	Space* diningRoom;
	Space* livingRoom;
	Space* bathRoom;
	Space* hall;
	Space* secretRoom;
	Player* player;
	Space* currentSpace;
	Menu* menu1;
	Menu* menu2;
	char** map;
	const int SIZE = 25;
public:
	Game();
	~Game();
	void runGame();
	void printMap();
	void createMap();
	void updateMap();

};
#endif;