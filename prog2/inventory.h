#include <vector>
#include <string>

class Inventory
{
public:
	Inventory();

	void Update(string item, int amount);

	void ListByName();

	void ListByQuantity();

private:
	// TODO:You provide this.
};

#include "inventory.cpp"