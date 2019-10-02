/*****************************************
File: Player.hpp
Name: Lauren Boone
Description: This file contain the class
Player
*****************************************/
//#pragma once
#include <iostream>
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <vector>


//enum inventory{secretKey, gunRoomKey, money, weapon, health, nothing};
class Player {
private:
	bool isAlive;
	bool hasGunKey;
	bool hasSecretKey;
	bool hasSecretWeapon;
	bool hasMoney;
	bool hasWeapon;
	bool hasMedicine;
	bool wonGame;
	int numHealth;
	int numMoney;
	int numThieves;
	enum inventory { secretKey, gunRoomKey, money, weapon, health, nothing };
	inventory items;
	std::string playerName;
	std::vector<std::string> objects;
public:
	Player();
	~Player();
	void killTheif();
	int getNumThieves();
	void addItem(std::string item);
	std::string getItem();
	void setWonGame(bool x);
	void setSecretWeapon(bool x);
	void addMoney(int x);
	bool getWonGame();
	void viewInventory();
	bool checkAlive();
	bool checkWeapon();
	bool checkMoney();
	bool checkMedicine();
	bool checkGunKey();
	bool checkSecretKey();
	bool fight();
	bool randSuccess(int chance);
	void takeDamage();
	bool bribe();
	bool runAway();
	void useMeds();
};
#endif