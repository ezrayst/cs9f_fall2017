#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>
#include <cmath>

class Board  {

public:
	Board();

	void SetCell(int player, int row, int col, char c);

	void Print(int player);

private:
	//! Data is stored in respect to Player 0
	std::vector< std::vector<char> > board_;

};

#include "board.cpp"

#endif