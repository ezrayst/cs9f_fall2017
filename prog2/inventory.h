#ifndef INVENTORY_
#define INVENTORY_

#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

#include "inventoryItem.h"

class Inventory
{
public:
	Inventory();

	void Update(std::string item, int amount);

	void ListByName();

	void ListByQuantity();

	static bool SortByName(InventoryItem& a, InventoryItem& b);

	static bool SortByQuantity(InventoryItem& a, InventoryItem& b);

private:
	std::vector<InventoryItem> inventory_;

};

#include "inventory.cpp"

#endif  // INVENTORY_
