#include <iostream>
#include <cmath>

#include "positions.h"

/**
 * You define the GetPositions function.
 * It should read legal cat and mouse positions from the user
 * and return the position values in its two arguments.
 */
void GetPositions(Position& cat, Position& mouse) {

	float mouse_angle, cat_radius, cat_angle;
	const float pi = 3.14159265358979323846;

	std::cout << "Enter the position of the cat (radius in m): ";
	std::cin >> cat_radius;

	std::cout << "Enter the position of the cat (angle in degrees): ";
	std::cin >> cat_angle;

	std::cout << "Enter the position of the mouse (angle in degrees): ";
	std::cin >> mouse_angle;

	//! Store angle in radians
	mouse.SetAbsolutePosition(1, mouse_angle * (pi / 180));
	cat.SetAbsolutePosition(cat_radius, cat_angle * (pi / 180));

}

/**
 * You define the RunChase function.
 * Given initialized cat and mouse positions,
 * it should simulate the cat chasing the mouse, printing the 
 * result of each movement of cat and mouse.  Either the cat will 
 * catch the mouse, or 30 time units will go by and the cat will 
 * give up.
 */
void RunChase(Position& cat, Position& mouse) {  

    Position oldCat = cat;
	Position newCat = cat;

	//! Main loop that will terminate after 30 iterations
    for (unsigned i = 0; i < 30; ++i) {
   	
    	//! Check cat
    	if (newCat.Sees(mouse)) {
    		newCat.IncrementPosition(-1, 0);	
    	} else {
    		newCat.IncrementPosition(0, 1.25);
    	}

    	//! Check catching if cat is at the base of the statue
    	if (newCat.IsAtStatue()) {
    		if (mouse.IsBetween(oldCat, newCat)) {
    			std::cout << "Oh no! The cat catches the mouse at time " << i + 1 << "!\n";
    			break;
    		}
    	}  

  	    std::cout << "Time " << i + 1 << ":  mouse is still alive!\n";  		
    	
    	//! Update mouse
    	mouse.IncrementPosition(0, 1);

    	//! Print location
    	std::cout << "Location of cat:\n";
    	newCat.Print();

    	std::cout << "Location of mouse:\n";
    	mouse.Print();
    	std::cout << "\n";
    	
    	oldCat = newCat;
    }
}

int main() {
    Position cat, mouse;
    GetPositions(cat, mouse);
    RunChase(cat, mouse);

    return 0;
}