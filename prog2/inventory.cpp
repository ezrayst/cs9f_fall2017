//! Implementation of inventory.h

Inventory::Inventory() {
}


void Inventory::Update(std::string item, int amount) {

	bool existFlag = false;
	unsigned id = 0;

	//! Check whether we have the inventory item in list
	for (unsigned i = 0; i < inventory_.size(); ++i) {
		if (inventory_.at(i).getItem() == item) {
			id = i;
			existFlag = true;
			break;
		}
	}
	
	//! Updating main inventory_ vector
	if (existFlag) {
		int temp = inventory_.at(id).getAmount() + amount;
		
		//! Checking for overflow
		if ( (inventory_.at(id).getAmount() > 0 && (amount > 0) && temp < std::numeric_limits<int>::max())) {
			//! Update current data
			int amount_added = std::numeric_limits<int>::max() - inventory_.at(id).getAmount(); 
			inventory_.at(id).UpdateAmount(amount_added);

			//! Expand it
			InventoryItem temp(item, amount - amount_added);
			inventory_.push_back(temp);
		} else if ((inventory_.at(id).getAmount() < 0 && (amount < 0) && temp > std::numeric_limits<int>::min())) {
			//! Update current data
			int amount_added = std::numeric_limits<int>::min() - inventory_.at(id).getAmount(); 
			inventory_.at(id).UpdateAmount(amount_added);

			//! Expand it
			InventoryItem temp(item, amount - amount_added);
			inventory_.push_back(temp);
		} else {
			inventory_.at(id).UpdateAmount(amount);
		}

	} else {
		InventoryItem temp(item, amount);
		inventory_.push_back(temp);
	}

	//! Printing inventory lists
	std::cout << "Current Inventory: \n";
	for (unsigned i = 0; i < inventory_.size(); ++i) {
		std::cout << inventory_.at(i).getItem() << "\t" << inventory_.at(i).getAmount() << "\n";
	}
}


void Inventory::ListByName() {

	std::sort(inventory_.begin(), inventory_.end(), SortByName);

	//! Printing inventory lists
	std::cout << "Current Inventory (sorted by name): \n";
	for (unsigned i = 0; i < inventory_.size(); ++i) {
		std::cout << inventory_.at(i).getItem() << "\t" << inventory_.at(i).getAmount() << "\n";
	}

}

void Inventory::ListByQuantity() {

	std::sort(inventory_.begin(), inventory_.end(), SortByQuantity);

	//! Printing inventory lists
	std::cout << "Current Inventory (sorted by quantity): \n";
	for (unsigned i = 0; i < inventory_.size(); ++i) {
		std::cout << inventory_.at(i).getItem() << "\t" << inventory_.at(i).getAmount() << "\n";
	}
}


bool Inventory::SortByName(InventoryItem& a, InventoryItem& b) {
	return a.getItem() < b.getItem();
}

bool Inventory::SortByQuantity(InventoryItem& a, InventoryItem& b) {
	return a.getAmount() < b.getAmount();
}