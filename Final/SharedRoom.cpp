/*****************************************************
File Name: SharedRoom.hpp
Name: Lauren boone
Date: 3/5/19
Description: This file contains the class SharedRoom
THis class inherit from Space
*******************************************************/
#include <iostream>
#include "SharedRoom.hpp"
#include "Space.hpp"
#include "InputValidation.hpp"
#include "Player.hpp"


SharedRoom::SharedRoom(bool key, bool theifIn, std::string object1, std::string object2, Player* user) {
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
void SharedRoom::interact(){
	std::cout << "You are in your " << roomName << " ." << std::endl;
	int choice = 0;
	do{
	if (checkTheif()) {
		foundTheif();
	}
	else {
		
		std::string randItem;
		//std::cout << "You are in your " << roomName << " ." << std::endl;
		std::cout << "What do you want to interact with? " <<
			"\n1. " << specialObj1 << "\n2. " << specialObj2 << "\n3. Leave" << std::endl;

		choice = getIntinRange(0, 4);
		if (choice == 1 && obj1 == false) {
			//randItem = player->getItem();
			std::cout << "You turn on the " << specialObj1 << " and hear movement" << std::endl;
			std::cout << "The theives know that you are awake! Be carefull!" << std::endl;
			obj1 = true;
			//player->viewInventory();
		}
		else if(choice == 1 && obj1 == true){
			std::cout << "You already checked " << specialObj1 << std::endl;
		}
		if (choice == 2 && obj2 == false) {
			if (specialObj2 == "wall") {
				std::cout << "You put your ear to the wall and you hear noise coming from the kitchen" << std::endl;
			}
			else {
				randItem = player->getItem();
				std::cout << "You ineract with the " << specialObj2 << " and find " << randItem << std::endl;
				std::cout << "Adding " << randItem << " to your inventory" << std::endl;
				player->viewInventory();
				}
			obj2 = true;
			}
		else if(choice == 2 && obj2 == true) {
			std::cout << "You already checked " << specialObj2 << std::endl;
		}
	}
	} while (choice != 3 && (player->checkAlive()));
}