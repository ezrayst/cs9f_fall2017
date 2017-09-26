//! Implementation of board.h

Board::Board() {
		//! Initialize to all "." (period)
		for (unsigned i = 0; i < 19; ++i) {
			std::vector<char> tempVec;	

			for (unsigned j = 0; j < 19; ++j) {
				tempVec.push_back('.');
			}

			board_.push_back(tempVec);
		}	

		std::cout << board_.at(0).at(0) << "\n";
}


void Board::SetCell(int player, int row, int col, char c) {
	
	//! Get playerSort to be used for alternating player
	int playerSort = 0;
	if (player == 1) { playerSort = 18; }	

	//! Change row and col depending on the player
	row = std::abs(playerSort - row);
	col = std::abs(playerSort - col);

	//! Update board
	board_.at(row).at(col) = c;
}


void Board::Print(int player) {

	//! Get playerSort to be used for next looping
	int playerSort = 0;
	if (player == 1) { playerSort = 18; }

	std::cout << "Player " << player << "'s perspective:\n";

	//! Loop to print
	int row, col;
	for (int i = 0; i < 19; ++i) {
		for (int j = 0; j < 19; ++j) {
			row = std::abs(playerSort - i);
			col = std::abs(playerSort - j);
			std::cout << board_.at(row).at(col);
		}
		std::cout << '\n';
	}	
	std::cout << '\n';

}

