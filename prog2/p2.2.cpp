#include <iostream>
#include <string>

#include "inventory.h"

int main() {

	//! Make the myProperties
	Inventory myProperties;

	//! Update and sort
	std::cout << "Updating pen with amount of 2147483647.\n";
	myProperties.Update("pen", 2147483645);

	std::cout << "Updating pen with amount of 3.\n";
	myProperties.Update("pen", 3);

	std::cout << "Updating book with amount of 4.\n";
	myProperties.Update("book", 4);

	std::cout << "Updating book with amount of -5.\n";
	myProperties.Update("book", -5);

	std::cout << "Updating ruler with amount of -2147483647.\n";
	myProperties.Update("ruler", -2147483647);	

	std::cout << "Updating ruler with amount of -6.\n";
	myProperties.Update("ruler", -6);	

	std::cout << "Updating eraser with amount of 8.\n";
	myProperties.Update("eraser", 8);

	std::cout << "Updating paper with amount of 1.\n";
	myProperties.Update("paper", 1);

	myProperties.ListByName();

	myProperties.ListByQuantity();

}