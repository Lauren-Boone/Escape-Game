//#pragma once

/**********************************************************************************
Lauren Boone
1/15/19
InputValidation
This is the file containing the functions for validation  user input. This file will
be used often for input validation.
************************************************************************************/

//pragma once
#include <iostream>
#ifndef INPUTVALIDATION_HPP
#define INPUTVALIDATION_HPP



int getIntinRange(int low, int high); //checks to make sure  its a positive int in a range

bool checkPositiveInt(int x); //checks for integer and positive
bool checkValue(int x, int low, int high);

int getPositiveInt();

double getPositiveFloat();
double getDoubleInRange(double low, double high);
bool checkPositiveFloat(double x);
bool checkValueFloat(double x, double low, double high);

#endif