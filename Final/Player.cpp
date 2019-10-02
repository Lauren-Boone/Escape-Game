/*****************************************
File: Player.hpp
Name: Lauren Boone
Description: This file contain the class
Player
*****************************************/
#include <iostream>
#include "Player.hpp"
#include <vector>
#include <string>
#include <stdlib.h>
#include "InputValidation.hpp"


Player::Player() {
	isAlive = true;
	hasGunKey = false;
	hasSecretKey = false;
	hasSecretWeapon = false;
	hasMoney = false;
	hasWeapon = false;
	hasMedicine = false;
	numHealth = 100;
	numMoney = 0;
	numThieves = 4;
	wonGame = false;
//	numWeapons = 0;
}



Player::~Player() {

}


void Player::addItem(std::string item) {
	objects.push_back(item);
}



void Player::killTheif() {
	numThieves--;
}


int Player::getNumThieves() {
	return numThieves;
}



void Player::setWonGame(bool x) {
	wonGame = x;
}


void Player::addMoney(int x) {
	numMoney += x;

}


bool Player::getWonGame() {
	return wonGame;
}


void Player::setSecretWeapon(bool x) {
	hasSecretWeapon = x;
}
/****************************************
getItem()
THis function randomily chooses 
a usefule object for the player
*****************************************/
std::string Player::getItem() {
	int randItem = 0 + rand() % 6;
	std::string itemName = " ";
	do{
		randItem = 0+ rand() % 6;
		//if (randItem != 5) {
			//randItem = 0 + rand() % 6;
		//}
		
		switch (randItem) {
		case secretKey:
			if (hasSecretKey) {
				itemName = "Nothing";
				break;
			}
			else {
				itemName = "Secret Room Key";
				hasSecretKey = true;
				randItem = 10;
				addItem(itemName);
				break;
				
			}
		case gunRoomKey:
			if (hasGunKey) {
				itemName = "Nothing";
				break;
			}
			else {
				itemName = "Large Closet Key";
				randItem = 10;
				addItem(itemName);
				hasGunKey = true;
				break;
			}
		case money:
			if (hasMoney) {
				itemName = "Money";
				numMoney += 1 + rand() % 10;
				randItem = 10;
				break;
			}
			else {
				itemName = "Money";
				hasMoney = true;
				numMoney += 1 + rand() % 10;
				randItem = 10;
				addItem(itemName);
				break;
			}
		case weapon:
			if (hasWeapon) {
				itemName = "Nothing";
				//randItem = 10;
				break;
			}
			else {
				itemName = "Weapon";
				hasWeapon = true;
				addItem(itemName);
				randItem = 10;
				break;
			}
		case health:
			itemName = "Medicine";
			hasMedicine = true;
			//numHealth = 10 + rand() % 40;
			randItem = 10;
			addItem(itemName);
			break;
		case nothing:
			itemName = "Nothing";
			randItem = 10;
			break;
		}
	} while (randItem != 10);
	
//	viewInventory();
	return itemName;
}



/**********************************
viewInventory
This function prints the inventory
of all the items
**********************************/
void Player::viewInventory() {
	std::cout << "Inventory\n----------" << std::endl;
	for (int i = 0; i < objects.size(); ++i) {
		std::cout << objects[i] << " " << std::endl;
	}
	std::cout << std::endl;
		if (hasMoney) {
			std::cout << "Total Money: $" << numMoney << std::endl << std::endl;
		}
	
	
}

/************************************
useMeds()
This function allows the player
to use items
*********************************/
void Player::useMeds() {
	int takeMeds = 0;
	if (hasMedicine) {
		std::cout << "Do you want to take medicine to regain health?\n1. Yes\n2. No" << std::endl;
		takeMeds = getIntinRange(0, 3);
		if (takeMeds == 1) {
			for (int x = 0; x < objects.size(); ++x) {
				if (objects[x] == "Medicine") {
					objects.erase(objects.begin() + x);
					x = objects.size();
				}
			}
			for (int i = 0; i < objects.size(); ++i) {
				if (objects[i] == "Medicine") {
					i = objects.size();
					hasMedicine = true;
				}
				else {
					hasMedicine = false;
				}
				
			}
			takeMeds = 10+rand() % 20;
			numHealth += takeMeds;
			if (numHealth > 100) {
				numHealth = 100;
			}
			std::cout << "Points Regained: " << takeMeds << "\nHealth: " << numHealth << std::endl;
		}
	}
}

bool Player::checkAlive() {
	if (numHealth>0) {
		isAlive = true;
	}
	else {
		isAlive = false;
	}
	return isAlive;
}



bool Player::checkWeapon() {
	if (hasWeapon) {
		return true;
	}
	else {
		return false;
	}
}



bool Player::checkMedicine() {
	if (hasMedicine) {
		return true;
	}
	else {
		return false;
	}
}

bool Player::checkMoney() {
	if (hasMoney) {
		return true;
	}
	else {
		return false;
	}
}


bool Player::randSuccess(int chance) {
	int success = rand() % (chance+1);
	if (success == chance) {
		return true;
	}
	else {
		return false;
	}
}


bool Player::checkGunKey() {
	if (hasGunKey) {
		return true;
	}
	else {
		return false;
	}
}


bool Player::checkSecretKey() {
	if (hasSecretKey) {
		return true;
	}
	else {
		return false;
	}
}



/***********************************
fight()
This functions allows to player
to fight. Chance of success based
on inventory
*************************************/
bool Player::fight() {
	int fight, noWeapons = 0;
	bool wonFight;
	if (hasSecretWeapon) {
		wonFight = true;
		std::cout << "You vaporize the thief with your secret weapon!" << std::endl;
	}
	else {
		if (checkWeapon()) {
			std::cout << "Health: " << numHealth <<
				"\nUse weapon? \n1. Yes\n2. No" << std::endl;
			std::cout << "There is a 50% chance of winning with a weapon, 25% without a weapon" << std::endl;
			fight = getIntinRange(0, 3);
			if (fight == 1) {
				wonFight = randSuccess(2);
			}
			else {
				wonFight = randSuccess(4);
			}
		}
		else {
			std::cout << "You have no weapons. Use your fists?" <<
				"\nOnly a 25% chance of of winning\n 1. Yes\n2. No" << std::endl;
			noWeapons = getIntinRange(0, 3);
			if (noWeapons == 1) {
				wonFight = randSuccess(4);
			}
			else {
				std::cout << "Try to find some weapons by checking the map!" << std::endl;
				wonFight = false;
			}

		}




		if (!wonFight && noWeapons != 2) {
			std::cout << "You have lost the fight" <<
				"\nYou have taken some damage" << std::endl;
			takeDamage();
			std::cout << "Health: " << numHealth << std::endl;
		}
		else if (wonFight) {
			std::cout << "You won the fight! That thief is fleeing." << std::endl;

		}
	}
	return wonFight;

	
}


/*************************************
runAway
The functions allows the player to 
try and escape or hide
************************************/
bool Player::runAway() {
	bool success;
	std::cout << "Do you want to make a run for it? 50% chance of getting away unharmed" << std::endl;
	std::cout << "1. Yes\n2. No" << std::endl;
	int run = getIntinRange(0, 3);
	if (run == 1) {
		success = randSuccess(2);
		if(!success){
			std::cout << "you did not get away in time and took damage" << std::endl;
			takeDamage();
			std::cout << "Health: " << numHealth << std::endl;
		}
	}
	
	return success;
}


/*********************************
takeDamage()
randomly calculates amount of damage
*********************************/
void Player::takeDamage() {
	int damage = rand() % 25;
	std::cout << "Damage: " << damage << std::endl;
	numHealth -= damage;
	if (numHealth <= 0) {
		numHealth = 0;
		isAlive = false;
		std::cout << "You have died" << std::endl;
	}
}



/****************************
bribe()
THis function allows the
player to bribe the thief
************************/
bool Player::bribe() {
	int bribe;
	bool success;
	if (checkMoney()) {
		if (numMoney > 100) {
			std::cout << "The theif took one look at your money filled hands\n grabbed the money" <<
				" \nand ran! " << std::endl;
			std::cout << "Don't worry you still have pockets full of money!" << std::endl;
			success = true;
		}
		else {
			std::cout << "Money: " << numMoney << std::endl;
			std::cout << "Do you want to try to bribe? \n1. Yes\n2. No" << std::endl;
			if (numMoney > 20) {
				std::cout << "You have a 50% chance of convincing him" << std::endl;
			}
			else {
				std::cout << "You only have a 10% chance of convincing him" << std::endl;
			}
			bribe = getIntinRange(0, 3);
			if (bribe == 1 && numMoney > 20) {
				success = randSuccess(2);
				if (!success) {
					std::cout << "Bribe Unsuccessful" << std::endl;
				}
			}
			else if (bribe == 1 && numMoney < 20) {
				success = randSuccess(10);
				if (!success) {
					std::cout << "Bribe Unsuccessful" << std::endl;
				}
			}
			else if (bribe == 2) {
				success = false;
			}
		}
	}
	else {
		std::cout << "You have no money to bribe with" << std::endl;
		success = false;
	}
	return success;
}