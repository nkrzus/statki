#include "ComputerPlayer.h"

void ComputerPlayer::addShip(int size) {
	bool placed = false;
	while (!placed) {
		int rows = rand() % 10;
		int col = rand() % 10; 
		bool horizontal = rand() % 2 == 0; 

		if (horizontal) {
			if (col + size <= 10) {
				bool canPlace = true;
				for (int i = rows - 1; i <= rows + 1; ++i) {
					for (int j = col - 1; j <= col + size; ++j) {
						if (i >= 0 && i < 10 && j >= 0 && j < 10 && !validateShot(Shot(j, i), board)) {
							canPlace = false;
							break;
						}
					}
				}
				
				if (canPlace) {
					for (int i = col; i < col + size; ++i) {
						updateBoard(Shot(i, rows));
					}
					placed = true;
				}
			}
		}
		else {
			if (rows + size <= 10) {
				bool canPlace = true;
				for (int i = rows - 1; i <= rows + size; ++i) {
					for (int j = col - 1; j <= col + 1; ++j) {
						if (i >= 0 && i < 10 && j >= 0 && j < 10 && !validateShot(Shot(j, i), board)) {
							canPlace = false;
							break;
						}
					}
				}
				if (canPlace) {
					for (int i = rows; i < rows + size; ++i) {
						updateBoard(Shot(col, i));

					}
					placed = true;
				}
			}
		}
	}
}

void ComputerPlayer:: addShips() {
	// Dodawanie czteromasztowca
	addShip(4);
	// Dodawanie trójmasztowców
	for (int i = 0; i < 2; ++i) {
		addShip(3);
	}
	// Dodawanie dwumasztowców
	for (int i = 0; i < 3; ++i) {
		addShip(2);
	}
	// Dodawanie jednomasztowców
	for (int i = 0; i < 4; ++i) {
		addShip(1);
	}
	cout << "Udalo sie stworzyc tablice dla komputera:\n";
	displayBoard(board);
}

void ComputerPlayer::guessWhereTheShipsAre() {
	cout << getName() << " - Twoj ruch. Strzelaj!\n";
	int rows = rand() % 10;
	int col = rand() % 10;
	Shot first(col, rows);

	if (isShipHere(first, oponentBoard)) {
		updatePlayBoard(first);
		cout << getName() << " - trafiony\n";
	}
	else {
		updatePlayBoardFail(first);
		cout << getName() << " - pudlo\n";

	}
	displayBoard(playBoard);
}


ComputerPlayer::ComputerPlayer() :Player("Computer") {};