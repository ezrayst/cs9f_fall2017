#include <iostream>

#include "board.h"

int main() {

	//! Make the gamePlay
	Board gamePlay;

	//! Set it and print
	gamePlay.SetCell(0, 18, 18, 'M');
	gamePlay.SetCell(1, 18, 18, 'X');
	gamePlay.Print(0);
	gamePlay.Print(1);

}