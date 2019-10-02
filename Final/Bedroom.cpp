/*****************************************************
File Name: Bedroom.hpp
Name: Lauren boone
Date: 3/5/19
Description: This file contains the class Bedroom
THis class inherit from Space
*******************************************************/

#include <iostream>
#include "Bedroom.hpp"
#include "Space.hpp"
#include <string>
#include "InputValidation.hpp"
#include "Player.hpp"
#include <stdlib.h>



Bedroom::Bedroom(bool key, bool theifIn, std::string object1, std::string object2,Player* user, std::string roomIn) {
	requiresKey = key;
	theif = theifIn;
	specialObj1 =  object1 ;
	specialObj2 = object2;
	player = user;
	roomName = roomIn;
	obj1 = false;
	obj2 = false;
}



/*****************************
interact()
This functin allows the user
to interact with the space
******************************/
void Bedroom::interact() {
	std::string randItem;
	int choice = 0;
	while (choice != 3 && (player->checkAlive()) && (!player->getWonGame())){
		std::cout << "You are in your " << roomName << " ." << std::endl;
		std::cout << "What do you want to interact with? " <<
			"\n1. " << specialObj1 << "\n2. " << specialObj2 << "\n3. Leave" << std::endl;

		choice = getIntinRange(0, 4);
		if (choice == 1 && obj1 == false) {
			randItem = player->getItem();
			std::cout << "You ineract with the " << specialObj1 << " and find " << randItem << std::endl;
			std::cout << "Adding " << randItem << " to your inventory" << std::endl;
			player->viewInventory();
			obj1 = true;
		}
		else if (choice == 1 && obj1 == true) {
			std::cout << "you have already checked " << specialObj1 << std::endl;
		}
		if (choice == 2 && obj2 == false) {
			if (specialObj2 == "crib") {
				std::cout << "The baby looks okay. No objects found in crib" << std::endl;
			}
			else {
				randItem = player->getItem();
				std::cout << "You ineract with the " << specialObj2 << " and find " << randItem << std::endl;
				std::cout << "Adding " << randItem << " to your inventory" << std::endl;
				player->viewInventory();
			}
			obj2 = true;
		}
		else if (choice == 2 && obj1 == true) {
			std::cout << "you have already checked " << specialObj2 << std::endl;
		}
	} 


	


}