#ifndef INVENTORY_ITEM_
#define INVENTORY_ITEM_

#include <vector>
#include <string>

class InventoryItem
{
public:
	InventoryItem(std::string item, int amount) {
		item_ = item;
		amount_ = amount;
	}

	void UpdateAmount(int amount) {
		amount_ += amount;
	}

	std::string getItem() { return item_; }

	int getAmount() { return amount_; }

private:
	std::string item_;
	int amount_;
};

#endif  // INVENTORY_ITEM_
