#include <iostream>
#include <string>

#include "inventory.h"

int main() {

	//! Make the myProperties
	Inventory myProperties;

	//! Update and sort
	myProperties.Update("Pen", 2);
	myProperties.Update("Pen", 3);
	myProperties.Update("Book", 4);
	myProperties.Update("Book", -5);
	myProperties.Update("Paper", 1);
	myProperties.ListByName();
	myProperties.ListByQuantity();

}