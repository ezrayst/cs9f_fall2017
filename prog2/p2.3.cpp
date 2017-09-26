#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "board.h"

int main() {

	//! Make the gamePlay
	Board gamePlay;

	//! Set it and print
	gamePlay.SetCell(0, 3, 3, 'M');
	gamePlay.Print(0);
	gamePlay.Print(1);

}