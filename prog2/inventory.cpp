//! Implementation of inventory.h

Inventory::Inventory() {

}


void Inventory::Update(std::string& item, int amount) {

	int order;

	order = std::find (inventory_.begin(), inventory_.end(), item);

	if (order != inventory_.end()) {
		std::vector<std::string, int> tempVec{item, amount};
		inventory_.push_back(tempVec);
	} else {
		inventory_.at(order).at(1) += amount;
	}

}

void Inventory::ListByName() {

}

void Inventory::ListByQuantity() {

}
