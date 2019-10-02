#include <iostream>
#include "Game.hpp"
#include "Space.hpp"
#include "Bedroom.hpp"
#include "Kitchen.hpp"
#include "SpecialRoom.hpp"
#include "Player.hpp"
#include "SharedRoom.hpp"
#include "Menu.hpp"
#include <string>

Game::Game() {
	menu1 = new Menu;
	menu2 = new Menu;
	menu1->addChoice("Instructions");
	menu1->addChoice("1. Defeat the thieves before they kill you or take your stuff.");
	menu1->addChoice("**You have 15 minutes before the thieves win and you loose");
	menu1->addChoice("2. You have 100 health points, game over at 0.");
	menu1->addChoice("3. You have no items starting out.");
	menu1->addChoice("4. Look for thieves, weapons, medicine, money, and keys.");
	menu1->addChoice("5. You may only carry one weapon.");
	menu1->addChoice("6. There are treasures that need keys.");
	menu1->addChoice("7. The treasure guarantee a win!. ");
	menu1->addChoice("(hint: That closet looks very large, hidden rooms?)");
	menu1->addChoice("8. (hint: check the map for possible treasure locations.)");

	menu2->addChoice("Ways to Win");
	menu2->addChoice("1. Kill Thieves");
	menu2->addChoice("2. Bribe Thieves");
	menu2->addChoice("3. Run for help");
	player = new Player();
	startRoom = new Bedroom(false, false, "wardrobe", "bedside table", player, "bedroom");
	currentSpace = startRoom;
	//currentSpace->setCurrent(currentSpace);
	kidRoom = new Bedroom(false, false, "baby dresser" , "crib", player, "nursery" );//key, theif
	kitchen = new Kitchen(false, true, "kitchen drawer", "pantry", player);
	closet = new SpecialRoom(true, false, "gun cabinet", "drawer", player);
	foyer = new SharedRoom(false, true, "lights", "coat closet", player);
	study = new SpecialRoom(false, false,"desk drawer", "file cabinet", player);
	secretRoom = new SpecialRoom(true, true,"chest", "old bookshelf", player);
	hall = new SharedRoom(false, false,"lights", "wall", player);
	diningRoom = new SharedRoom(false, false, "lights", "table", player);
	livingRoom = new SharedRoom(false, false, "lights", "bookshelf", player);
	bathRoom = new SpecialRoom(false, true, "cabinet", "mirror", player);
	startRoom->addRoom(nullptr, hall, kidRoom, nullptr, "Bedroom");
	kidRoom->addRoom(nullptr, nullptr, nullptr, startRoom, "Nursery");
	kitchen->addRoom(nullptr, diningRoom, foyer, nullptr, "Kitchen");
	closet->addRoom(nullptr, nullptr, secretRoom, study, "Large Closet");
	foyer->addRoom(livingRoom, nullptr, bathRoom, kitchen, "Foyer");
	study->addRoom(hall, bathRoom, closet, livingRoom, "Study");
	secretRoom->addRoom(nullptr, nullptr, nullptr, closet, "Secret Room");
	hall->addRoom(startRoom, livingRoom, nullptr, nullptr, "Hallway");
	diningRoom->addRoom(kitchen, nullptr, livingRoom, nullptr, "Dining Room");
	livingRoom->addRoom(hall, foyer, study, diningRoom, "Living Room");
	bathRoom->addRoom(nullptr, study, foyer, nullptr, "Bath Room");
	createMap();

//player->setLocation(startRoom);

}

Game::~Game() {
	//delete currentSpace;
	delete startRoom;
	delete kidRoom;
	delete kitchen;
	delete closet;
	delete foyer;
	delete study;
	delete diningRoom;
	delete livingRoom;
	delete bathRoom;
	delete hall;
	delete secretRoom;
	delete player;
	delete menu1;
	delete menu2;
	//delete currentSpace;
	for (int i = 0; i < SIZE; ++i) {
		delete[] map[i];
	}
	delete[] map;

}


/**********************************
runGame()
A loop that keeps track of the 
game and calls necessary functions
*****************************/
void Game::runGame() {
	std::cout << "Hello, welcome to the game SAVE YOURSELF" << std::endl;
	std::cout << "It's 3 AM. You hear a noise coming from downstairs. Theives! Try and stop them!" << std::endl;
	std::cout << "If you can stop them from killing you and stealing your things you win!" << std::endl;
	//std::cout << "There are multiple ways to do this, you can convince or bribe them to leave, " <<
	//	"\n you can fight them, or you can run for help and hope you get away unharmed." << std::endl;
	//std::cout << "You start at 100 strength points, $0, and no items on your person" << std::endl;
	//std::cout << "You will have the option to search each room for items that may help you" << std::endl;
	int time = 15;
	
		menu1->printMenu();
		std::cout << std::endl;
		menu2->printMenu();
		//player->getCurrentRoom()->getName();
		//player->getCurrentRoom()->interact();
		while (player->checkAlive() && (!player->getWonGame()) && time!=0) {
			
				printMap();
				//currentSpace = currentSpace->getRoom();
				currentSpace->getName();
				currentSpace->interact();
				if (player->checkAlive() && (!player->getWonGame())) {
					currentSpace->movePlayer(currentSpace);
					currentSpace->getName();
				}

				time--;
				std::cout << "Time left: " << time << " minutes" << std::endl;
		}
		if (player->getWonGame()) {
			std::cout << "\n\n\nGame Over\nYou Won" << std::endl;
		}
		else {
			std::cout << "\n\n\nGame Over\nYou Died" << std::endl;
		}
	
	
}


//prints map
void Game::printMap() {
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			std::cout << map[i][j] << " ";

		}

		std::cout << std::endl;
	}

	std::cout << "  Map Legend" << "\n-----------------" << std::endl;
	std::cout << "0. Kitchen\n1. Nursery (only accessible by Master Bedroom\n2. Master Bedroom\n3. Hallway\n4. Study\n5. Living Room\n" <<
		"6. Dining Room\n7. Closet?\n8. Bath Room\n9. Foyer\n" << std::endl;
}


void Game::createMap() {
	map = new char*[SIZE];
	for (int i = 0; i < SIZE; ++i) {
		map[i] = new char[SIZE];
	}
	updateMap();

}


/****************************************
updateMap
This fills the map 
*****************************************/
void Game::updateMap() {
	for (int x = 0; x < SIZE; ++x) {
		for (int y = 0; y < SIZE; ++y) {
			map[x][y] = ' ';
			if ((x == 0 || y == 0) || (x == (SIZE - 1) || y == (SIZE - 1))) {
				map[x][y] = '*';
			}
			if ((y == (SIZE / 5) && x >= (SIZE / 3)) || // bathroom
				(x == (SIZE - (SIZE / 2) / 2)) || //study/secretrrom
				(x == ((SIZE / 3) * 2) && (y <= (SIZE / 5))) || //secret room
				(x == (SIZE / 3) && y <= (SIZE / 3) * 2) || (x <= (SIZE / 3) && y == (SIZE / 3)) ||//nursery
				(x == ((SIZE / 3) - (SIZE / 10)) && (y >= (SIZE / 3) && y <= ((SIZE / 2) + (SIZE / SIZE)))) ||//hall
				//((x >= ((SIZE / 3) - (SIZE / 10)) && x<=(SIZE/3)) && y ==((SIZE/2) +(SIZE/SIZE))) ||//hall
				((x == ((SIZE / 3) - (SIZE / 10))) && y >= (SIZE / 3)) ||//bedroom/startroom
				((x >= ((SIZE / 3) - (SIZE / 10))) && (y == ((SIZE / 3) * 2)))) { //dining/kitchen
				map[x][y] = '*';
			}
			if (x == (SIZE / 7) && y == (SIZE / 7)) { //nursery
				map[x][y] = '1';
			}
			if (x == (SIZE / 7) && y == ((SIZE / 3) * 2)) { //bedroom
				map[x][y] = '2';
			}
			if (y == (SIZE / 10) && x == (SIZE / 2)) { //study
				map[x][y] = '4';
			}
			if (y == (SIZE / 10) && x == (((SIZE / 3) * 2) + (SIZE / SIZE) * 2)) { // secret
				map[x][y] = '7';
			}
			if (y == (SIZE / 10) && x == ((SIZE / 2) + (SIZE / 3))) { //bath
				map[x][y] = '8';
			}
			if (x == ((SIZE / 3) - (SIZE / SIZE * 2)) && y == ((SIZE / 3) + (4 * (SIZE / SIZE)))) {
				map[x][y] = '3'; //hall
			}
			if (x == (SIZE / 2) && y == (SIZE / 2)) {
				map[x][y] = '5';
			}
			if (x == ((SIZE / 2) + (SIZE / 3)) && y == (SIZE / 2)) { //dinning
				map[x][y] = '9';
			}
			if (x == (SIZE / 2) && y == ((SIZE / 2) + (SIZE / 3))) { //foyer
				map[x][y] = '6';
			}
			if (x == ((SIZE / 2) + (SIZE / 3)) && y == ((SIZE / 2) + (SIZE / 3))) {
				map[x][y] = '0';
				
			}


		}

	}

}