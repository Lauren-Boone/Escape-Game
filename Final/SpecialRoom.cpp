
/*****************************************************
File Name: SpecialRoom.hpp
Name: Lauren boone
Date: 3/5/19
Description: This file contains the class Special
THis class inherit from Space
*******************************************************/
#include <iostream>
#include "Space.hpp"
#include "SpecialRoom.hpp"
#include "InputValidation.hpp"
#include "Player.hpp"

SpecialRoom::SpecialRoom(bool key, bool theifIn, std::string object1, std::string object2, Player* user) {
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
void SpecialRoom::interact(){
	std::cout << "You are in your " << roomName << " ." << std::endl;
	int choice = 0;

		
	while (choice != 3 && (player->checkAlive()) && (!player->getWonGame())) {
		if (checkTheif()) {
			foundTheif();
		}
		else if (!player->getWonGame()) {
			std::string randItem;
			//std::cout << "You are in your " << roomName << " ." << std::endl;
			std::cout << "What do you want to interact with? " <<
				"\n1. " << specialObj1 << "\n2. " << specialObj2 << "\n3. Leave" << std::endl;

			choice = getIntinRange(0, 4);
			if (choice == 1 && !obj1) {
				if (specialObj1 == "chest") {
					std::cout << "Congraduations you found a fortune in gold" << std::endl;
					std::cout << "Now if you bribe the thieves you win!" << std::endl;
					player->addMoney(1000);
				}
				else {
					randItem = player->getItem();
					std::cout << "You ineract with the " << specialObj1 << " and find " << randItem << std::endl;
					std::cout << "Adding " << randItem << " to your inventory" << std::endl;
					player->viewInventory();
				}
				obj1 = true;
			}
			else if (choice == 1 && obj1 == true) {
				std::cout << "You already checked " << specialObj1 << std::endl;
			}
			else if (choice == 2 && !obj2) {
				if (specialObj2 == "old bookshelf") {
					std::cout << "You found a vaproizer! Now you will always win fights" << std::endl;
					player->setSecretWeapon(true);
				}
				else {
					randItem = player->getItem();
					std::cout << "You ineract with the " << specialObj2 << " and find " << randItem << std::endl;
					std::cout << "Adding " << randItem << " to your inventory" << std::endl;
					player->viewInventory();
				}
				obj2 = true;
			}
			else if (choice == 2 && obj2 == true) {
				std::cout << "You already checked " << specialObj2 << std::endl;
			}
			
		}
	}
}