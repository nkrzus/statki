#include "HumanPlayer.h"



void HumanPlayer::addShip(int size) {

	bool placed = false;
	while (!placed) {
		string choise;
		bool vertical;

		if (size == 1) {
			vertical = true;
		}
		else {
			do
			{
				displayBoard(board);
				cout << "Podaj polozenie statku H - pionowo, V - poziomo\n";
				cin >> choise;
				if (choise == "V") {
					vertical = true;
				}
				else if (choise == "H") {
					vertical = false;
				}
				else {
					cout << "Niepoprawny wybor\n";
				}
			} while ((choise != "H") && (choise != "V"));
			system("cls");
		};

		string shot;
		bool isValid;
		do
		{
			cout << "Podaj lokalizacje pierwszej czesci statku (np A5, D10)\n";
			displayBoard(board);
			cin >> shot;
			Shot first(shot);
			isValid = validationOfShot(first);
		} while (!isValid);

		Shot first(shot);

		if (vertical) {
			if (first.columns + size <= 10) {
				bool canPlace = true;
				for (int i = first.rows - 1; i <= first.rows + 1; ++i) {
					for (int j = first.columns - 1; j <= first.columns + size; ++j) {
						if (i >= 0 && i < 10 && j >= 0 && j < 10 && !validateShot(Shot(j, i), board)) {
							canPlace = false;
							cout << "Niepoprawny wybor\n";
							break;
						}
					}
				}

				if (canPlace) {
					for (int i = first.columns; i < first.columns + size; ++i) {
						updateBoard(Shot(i, first.rows));
					}
					placed = true;
					system("cls");

				}
			}
		}
		else {
			if (first.rows + size <= 10) {
				bool canPlace = true;
				for (int i = first.rows - 1; i <= first.rows + size; ++i) {
					for (int j = first.columns - 1; j <= first.columns + 1; ++j) {
						if (i >= 0 && i < 10 && j >= 0 && j < 10 && !validateShot(Shot(j, i), board)) {
							canPlace = false;
							cout << "Niepoprawny wybor\n";
							break;
						}
					}
				}
				if (canPlace) {
					for (int i = first.rows; i < first.rows + size; ++i) {
						updateBoard(Shot(first.columns, i));

					}
					placed = true;
					system("cls");

				}
			}
		}
	}
}

void HumanPlayer::addShips() {
	cout << "\nRozmiesc swoje statki.\n\n";

	cout << "CZTEROMASZTOWIEC: \n";
	addShip(4);
	for (int i = 0; i < 2; ++i) {
		cout << i + 1 << " - TRZYMASZTOWIEC: \n";
		addShip(3);
	}
	for (int i = 0; i < 3; ++i) {
		cout << i + 1 << " - DWUMASZTOWIEC: \n";
		addShip(2);

	}

	for (int i = 0; i < 4; ++i) {
		cout << i + 1 << " - JEDNOMASZTOWIEC: \n";
		addShip(1);
	}
	cout << "GZ! Dodales wszystkie statki! \n";
	displayBoard(board);
}

void HumanPlayer::guessWhereTheShipsAre() {

	cout << getName() << " - Twoj ruch. Strzelaj!\n";
	string shot;
	cin >> shot;
	Shot first(shot);
	system("cls");
	if (isShipHere(first, oponentBoard)) {
		updatePlayBoard(first);
		cout << "Trafiony\n";
	}
	else {
		updatePlayBoardFail(first);
		cout << "Pudlo\n";
	}
	displayBoard(playBoard);
}

HumanPlayer::HumanPlayer(string playerName) :Player(playerName) {

};
