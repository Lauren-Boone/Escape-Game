/*****************************************************
File Name: Space.cpp
Name: Lauren boone
Date: 3/5/19
Description: This file contains the class Space
*******************************************************/
#include <iostream>
#include "Space.hpp"
#include <string>
#include <vector>
#include "Player.hpp"
#include "InputValidation.hpp"

Space::Space() {
	hasDiscovered = false;
	forward = nullptr;
	back = nullptr;
	right = nullptr;
	left = nullptr;
	player = nullptr;
	//numThieves = 3;
	//wonGame = false;
}

Space::~Space() {
//	delete forward;
	//delete back;
	//delete left;
	//delete right;
	//delete player;
}


/*******************************
getRequiresKey()
This functions checks to see if 
the room needs a key
******************************/
bool Space::getRequiresKey() {
	return requiresKey;
}

bool Space::checkTheif() {
	return theif;
}



std::string Space::getKeyName() {
	return roomName;
}

bool Space::hasDiscoveredSpace() {
	if (hasDiscovered) {
		return true;
	}
	else {
		return false;
	}
}

/*********************************
addRoom()
This function as a room to the 
space
*******************************/
void Space::addRoom(Space* forwardIn, Space* backIn, Space* leftIn, Space* rightIn, std::string nameIn) {
	this->forward = forwardIn;
	this->back = backIn;
	this->left = leftIn;
	this->right = rightIn;
	this->roomName = nameIn;
	//play = playerIn;
}


std::string Space::getName() {
	//if (this != nullptr) {
		//std::cout << roomName << std::endl;
		return roomName;
	//}
	
}

Space* Space::getBack() {
	//std::cout << "back: " << back->getName() << std::endl;
	if (back != nullptr) {
		std::cout << "Back: " << back->getName() << std::endl;
	}
	else {
		std::cout << "Back: It's blocked by a wall" << std::endl;
	}
	return this->back;
}


Space* Space::getForward() {
	//
	if (forward != nullptr) {
		std::cout << "Forward: " << forward->getName() << std::endl;
	}
	else {
		std::cout << "Forward: It's blocked by a wall" << std::endl;
	}
	return this->forward;
}

Space* Space::getLeft() {
	//
	if (left != nullptr) {
		std::cout << "Left: " << left->getName() << std::endl;
	}
	else {
		std::cout << "Left: It's blocked by a wall" << std::endl;
	}
	return this->left;
}

Space* Space::getRight() {
	
	if (right != nullptr) {
		std::cout << "Right: " << right->getName() << std::endl;
	}
	else {
		std::cout << "Right: It's blocked by a wall" << std::endl;
	}
	return this->right;
}


void Space::foundTheif() {
	bool success;
	
		std::cout << "Oh no! You hear a theif in the " << roomName << "!" <<
			"\nWhat do you want to do?" << std::endl;
		do {
			std::cout << "You must defeat or escape this theif before continueing" << std::endl;
		std::cout << "1. View Inventory\n2. Fight\n3. Bribe\n4. Run" << std::endl;
		int choice = getIntinRange(0, 5);
		switch (choice) {
		case 1:
			player->viewInventory();
			player->useMeds();
			success = false;
			break;
		case 2:
			success = player->fight();
			if (success) {
				this->theif = false;
				player->killTheif();
				//this->numThieves--;
			}
			break;
		case 3:
			success = player->bribe();
			if (success) {
				this->theif = false;
				player->killTheif();
				//numThieves--;
			}
			break;
		case 4:
			success = player->runAway();
			if (success) {
				player->setWonGame(true);
			}
			break;
		}
		
	} while (!success && (player->checkAlive()));
	
	if (player->getNumThieves() == 0) {
		player->setWonGame(true);
	}
}

/*
bool Space::checkWonGame() {
	if (wonGame) {
		return true;
	}
	else {
		return false;
	}
}
*/



/****************************************************
movePlayer
This functions displays avaible spaces to move
and allows the user to decide where they want to 
move
**************************************************/
void Space::movePlayer(Space* &spaceIn) {
	//Space* tempRoom;

	//Display options
	std::cout << "Where do you want to go to find the theives? " << std::endl;
	int choice;
	if (spaceIn->right != nullptr) {
		std::cout << "1. " << spaceIn->right->getName() << std::endl;
	}
	else {
		std::cout << "1. BLOCKED" << std::endl;
	}
	if (spaceIn->left != nullptr) {
		std::cout << "2. " << spaceIn->left->getName() << std::endl;
	}
	else {
		std::cout << "2. BLOCKED" << std::endl;
	}
	if (spaceIn->forward != nullptr) {
		std::cout << "3. " << spaceIn->forward->getName() << std::endl;
	}
	else {
		std::cout << "3. BOCKED" << std::endl;
	}
	if (spaceIn->back != nullptr) {
		std::cout << "4. " << spaceIn->back->getName() << std::endl;
	}
	else {
		std::cout << "4. Blocked" << std::endl;
	}
	std::cout << "5. Stay in Room" << std::endl;

	do {
	
	choice = getIntinRange(0, 6);
	switch (choice) {
	case 1:
		if (spaceIn->right != nullptr) { 
			if (spaceIn->right->getRequiresKey()) { //check for key
				if (spaceIn->right->roomName == "Large Closet") {
					if (!player->checkGunKey()) { //if they dont have key
						std::cout << "Sorry, you don't have the key" << std::endl;
					}
					else {//if they ahve key
						std::cout << "You were able to unlock the " << spaceIn->right->roomName << std::endl;
						spaceIn = spaceIn->right;//moe to new space
						choice = 5;//end loop
					}
				}
				else if (spaceIn->right->roomName == "Secret Room") {
					if (!player->checkSecretKey()) {
						std::cout << "Sorry, you don't have the key" << std::endl;
					}
					else {
						std::cout << "You were able to unlock the " << spaceIn->right->roomName << std::endl;
						spaceIn = spaceIn->right;
						choice = 5;
					}

				}

			}

			else {
				spaceIn = spaceIn->right;
				choice = 5;
			}
		}

		break;
	case 2:
		if (spaceIn->left != nullptr) {
			if (spaceIn->left->getRequiresKey()) {
				if (spaceIn->left->roomName == "Large Closet") {
					if (!player->checkGunKey()) {
						std::cout << "Sorry, you don't have the key" << std::endl;
					}
					else {
						std::cout << "You were able to unlock the " << spaceIn->left->roomName << std::endl;
						spaceIn = spaceIn->left;
						choice = 5;
					}
				}
				else if (spaceIn->left->roomName == "Secret Room") {
					if (!player->checkSecretKey()) {
						std::cout << "Sorry, you don't have the key" << std::endl;
					}
					else {
						std::cout << "You were able to unlock the " << spaceIn->left->roomName << std::endl;
						spaceIn = spaceIn->left;
						choice = 5;
					}

				}

			}

			else {
				spaceIn = spaceIn->left;
				choice = 5;
			}
		}
		
			
		
		break;
	case 3:
		if (spaceIn->forward != nullptr) {
			if (spaceIn->forward->getRequiresKey()) {
				if (spaceIn->forward->roomName == "Large Closet") {
					if (!player->checkGunKey()) {
						std::cout << "Sorry, you don't have the key" << std::endl;
					}
					else {
						std::cout << "You were able to unlock the " << spaceIn->forward->roomName << std::endl;
						spaceIn = spaceIn->forward;
						choice = 5;
					}
				}
				else if (spaceIn->forward->roomName == "Secret Room") {
					if (!player->checkSecretKey()) {
						std::cout << "Sorry, you don't have the key" << std::endl;
					}
					else {
						std::cout << "You were able to unlock the " << spaceIn->forward->roomName << std::endl;
						spaceIn = spaceIn->forward;
						choice = 5;
					}

				}

			}

			else {
				spaceIn = spaceIn->forward;
				choice = 5;
			}
		}

		break;
	case 4:
		if (spaceIn->back != nullptr) {
			if (spaceIn->back->getRequiresKey()) {
				if (spaceIn->back->roomName == "Large Closet") {
					if (!player->checkGunKey()) {
						std::cout << "Sorry, you don't have the key" << std::endl;
					}
					else {
						std::cout << "You were able to unlock the " << spaceIn->back->roomName << std::endl;
						spaceIn = spaceIn->back;
						choice = 5;
					}
				}
				else if (spaceIn->back->roomName == "Secret Room") {
					if (!player->checkSecretKey()) {
						std::cout << "Sorry, you don't have the key" << std::endl;
					}
					else {
						std::cout << "You were able to unlock the " << spaceIn->back->roomName << std::endl;
						spaceIn = spaceIn->back;
						choice = 5;
					}

				}

			}

			else {
				spaceIn = spaceIn->back;
				choice = 5;
			}
		}

		break;
	case 5:
		break;

	}
	if (choice != 5) {
		std::cout << "You can not move there. Try again" << std::endl;
	}
	} while (choice != 5);

	std::cout << "You are now in the " << spaceIn->getName() << std::endl;

}