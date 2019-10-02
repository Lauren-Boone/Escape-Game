/*****************************************************
File Name: Kitchen.hpp
Name: Lauren boone
Date: 3/5/19
Description: This file contains the class Kitchen
THis class inherit from Space
*******************************************************/
#include <iostream>
#include "Kitchen.hpp"
#include "Space.hpp"
#include "Player.hpp"
#include "InputValidation.hpp"



Kitchen::Kitchen(bool key, bool theifIn, std::string object1, std::string object2, Player* user) {
	requiresKey = key;
	theif = theifIn;
	player = user;
	specialObj1 = object1;
	specialObj2 = object2;
	obj1 = false;
	obj2 = false;
	
}



/*****************************
interact()
This functin allows the user
to interact with the space
******************************/
void Kitchen::interact() {
	std::cout << "You are in your " << roomName << " ." << std::endl;
	std::cout << "Kitchens are filled with limitless items! It's the kitchen afterall" << std::endl;
	int choice = 0;
	while (choice != 3 && (player->checkAlive()) && (!player->getWonGame())) {
		if (checkTheif()) {
			foundTheif();
		}
		else {
			std::string randItem;
			//std::cout << "You are in your " << roomName << " ." << std::endl;
			std::cout << "What do you want to interact with? " <<
				"\n1. " << specialObj1 << "\n2. " << specialObj2 << "\n3. Leave" << std::endl;

			choice = getIntinRange(0, 4);
			if (choice == 1) {
				randItem = player->getItem();
				std::cout << "You ineract with the " << specialObj1 << " and find " << randItem << std::endl;
				std::cout << "Adding " << randItem << " to your inventory" << std::endl;
				player->viewInventory();
			}
			else {
				if (specialObj2 == "crib") {
					std::cout << "The baby looks okay. No objects found in crib" << std::endl;
				}
				else {
					randItem = player->getItem();
					std::cout << "You ineract with the " << specialObj2 << " and find " << randItem << std::endl;
					std::cout << "Adding " << randItem << " to your inventory" << std::endl;
					player->viewInventory();
				}
			}
		}
		if (player->getWonGame()) {
			choice = 3;
		}
	}
}