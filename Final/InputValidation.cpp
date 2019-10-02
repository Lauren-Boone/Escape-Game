/**********************************************************************************
Lauren Boone
1/15/19
InputValidation
This is the file containing the functions for validation  user input. This file will
be used often for input validation.
************************************************************************************/


#include <iostream>
#include "InputValidation.hpp"

/******************************************************************************
GetAnInt()
This fuction asks for an integer input and validates if it is an integer.
If it is not an integer the buffer is cleared and all extraneous input is ignored.
*************************************************************************************/
int getIntinRange(int low, int high) {
	int x;
	std::cin >> x;
	while (std::cin.get() != '\n') {
		std::cin.clear(); //clears buffer
		std::cin.ignore(30000, '\n'); //removes extranous data
		std::cout << "Oops that input is invalid please try again." << std::endl;
		std::cin >> x;
	}
	while (!checkPositiveInt(x) || !checkValue(x, low, high)) {
		std::cin.clear(); //clears buffer
		std::cin.ignore(30000, '\n'); //removes extranous data
		std::cout << "Oops that input is invalid please try again." << std::endl;
		std::cin >> x;

	}

	return x;

}

/**********************************************************************
bool checkPositiveInt()
This function checks to make sure the input is an int and is Positive
***********************************************************************/

bool checkPositiveInt(int x) {
	if (x >= 0 && x % 1 == 0.0) {
		return true;
	}
	else {
		return false;
	}
}
/***************************************************************
checkValue
This function can be manipulated to meet the needs of the program.
It checks to make sure the integer is within range.
****************************************************************/
bool checkValue(int x, int low, int high) {
	if (x < high && x > low) {
		return true;
	}
	else {
		return false;
	}
}


/************************************************************
getPositiveInt
This function gets to make sure the input is an integer
and is positive
***************************************************************/
int getPositiveInt() {
	int x;
	std::cin >> x;
	while (std::cin.get() != '\n') {
		std::cin.clear(); //clears buffer
		std::cin.ignore(30000, '\n'); //removes extranous data
		std::cout << "Oops that input is invalid please try again." << std::endl;
		std::cin >> x;
	}
	while (!checkPositiveInt(x)) {
		std::cin.clear(); //clears buffer
		std::cin.ignore(30000, '\n'); //removes extranous data
		std::cout << "Oops that input is invalid please try again." << std::endl;
		std::cin >> x;
	}
	return x;

}
/******************************************************
getPositiveFloat()
This function checks to make sure the value is positive
*******************************************************/
double getPositiveFloat() {
	double x;
	std::cin >> x;
	while (!checkPositiveFloat(x)) {
		std::cin.clear();
		std::cin.ignore(30000, '\n');
		std::cout << "Oop that input is invalid. Please try again." << std::endl;
		std::cin >> x;
	}
	return x;
}

/*********************************************************
checkPositiveFloat
This funcitons check to make sure the value is positive
and returns true;
*******************************************************/
bool checkPositiveFloat(double x) {
	if (x >= 0.0) {
		return true;
	}
	else {
		return false;
	}
}

/**********************************************************
getDoubleinRange
This function checks to make sure that the input
is in the correct range
***********************************************************/
double getDoubleInRange(double low, double high) {
	double x;
	std::cin >> x;
	while (!checkValueFloat(x, low, high)) {
		std::cin.clear();
		std::cin.ignore(3000, '\n');
		std::cout << "Oops that input is invalid. Please try again" << std::endl;
		std::cin >> x;
	}
	return x;
}

/*************************************************
checkValueFloat
This funciton checks to see if the input is within
the required range then returns true if yes
**************************************************/
bool checkValueFloat(double x, double low, double high) {
	if (x<high && x > low) {
		return true;
	}
	else {
		return false;
	}
}