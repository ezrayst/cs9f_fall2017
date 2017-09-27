#include <vector>
#include <string>

class Inventory
{
public:
	Inventory();

	void Update(std::string& item, int amount);

	void ListByName();

	void ListByQuantity();

private:
	std::vector< std::vector<std::string, int> > inventory_;

};

#include "inventory.cpp"