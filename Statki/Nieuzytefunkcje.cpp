//
//bool Player::validateSpaceForCompleteShip(Shot x, Board playerBoard, int i) {
//	switch (i) {
//	case 1: {
//		if (this->board.board[x.rows][x.columns] != '~') {
//			cout << "W tym miejscu nie mozesz postawic statku. Sprobuj ponownie.";
//			return false;
//		}
//		else {
//			return true;
//		};
//	};
//		  break;
//	case 2: {
//		if (this->board.board[x.rows][x.columns] != '~') {
//			return false;
//			cout << "W tym miejscu nie mozesz postawic statku. Sprobuj ponownie.";
//		}
//		else if (this->board.board[x.rows + 1][x.columns] == '~' || this->board.board[x.rows - 1][x.columns] == '~' || this->board.board[x.rows][x.columns + 1] == '~' || this->board.board[x.rows][x.columns - 1] == '~') {
//			return true;
//		}
//		else {
//			return false;
//			cout << "W tym miejscu nie mozesz postawic statku. Sprobuj ponownie.";
//		};
//	};
//		  break;
//	case 3: {
//		if (this->board.board[x.rows][x.columns] != '~') {
//			return false;
//			cout << "W tym miejscu nie mozesz postawic statku. Sprobuj ponownie.";
//		}
//		else if (this->board.board[x.rows + 1][x.columns] == '~' || this->board.board[x.rows - 1][x.columns] == '~' || this->board.board[x.rows][x.columns + 1] == '~' || this->board.board[x.rows][x.columns - 1] == '~' || this->board.board[x.rows + 2][x.columns] == '~' || this->board.board[x.rows - 2][x.columns] == '~' || this->board.board[x.rows][x.columns + 2] == '~' || this->board.board[x.rows][x.columns - 2] == '~') {
//			return true;
//		}
//		else {
//			return false;
//			cout << "W tym miejscu nie mozesz postawic statku. Sprobuj ponownie.";
//		};
//	};
//		  break;
//	case 4:
//		if (this->board.board[x.rows][x.columns] != '~') {
//			return false;
//			cout << "W tym miejscu nie mozesz postawic statku. Sprobuj ponownie.";
//		}
//		else if (this->board.board[x.rows + 1][x.columns] == '~' || this->board.board[x.rows - 1][x.columns] == '~' || this->board.board[x.rows][x.columns + 1] == '~' || this->board.board[x.rows][x.columns - 1] == '~' || this->board.board[x.rows + 2][x.columns] == '~' || this->board.board[x.rows - 2][x.columns] == '~' || this->board.board[x.rows][x.columns + 2] == '~' || this->board.board[x.rows][x.columns - 2] == '~' || this->board.board[x.rows + 3][x.columns] == '~' || this->board.board[x.rows - 3][x.columns] == '~' || this->board.board[x.rows][x.columns + 3] == '~' || this->board.board[x.rows][x.columns - 3] == '~') {
//			return true;
//		}
//		else {
//			return false;
//			cout << "W tym miejscu nie mozesz postawic statku. Sprobuj ponownie.";
//		};
//		break;
//	};
//}
//
//bool validateShot(Shot x, Board playerBoard);
//
//bool validateSpaceForCompleteShip(Shot x, Board playerBoard, int i);
//
//bool validateShotNextToShot(Shot x, Shot y);
//
//bool validateShotsForTriplet(Shot x, Shot y, Shot z);
//
//bool validateShotsForQuartet(Shot x, Shot y, Shot z, Shot s);
//
//void blockBusySpace();
//
//void Player::blockBusySpace() {
//	Board board;
//	for (int i = 0; i < 10; i++) {
//		for (int j = 0; j < 10; j++) {
//			if (this->board.board[i][j] == 'X') {
//
//				if (i > 0 && i < 9 && j>0 && j < 9) {
//					for (int k = i - 1; k < i + 2; k++) {
//						for (int l = j - 1; l < j + 2; l++) {
//							if (this->board.board[k][l] != 'X') {
//								this->board.board[k][l] = '.';
//							}
//						}
//					}
//				}
//				else if (i == 0 && j == 0) {
//					for (int k = i; k < i + 2; k++) {
//						for (int l = j; l < j + 2; l++) {
//							if (this->board.board[k][l] != 'X') {
//								this->board.board[k][l] = '.';
//							}
//						}
//					}
//				}
//				else if (i == 9 && j == 9) {
//					for (int k = i - 1; k < i + 1; k++) {
//						for (int l = j - 1; l < j + 1; l++) {
//							if (this->board.board[k][l] != 'X') {
//								this->board.board[k][l] = '.';
//							}
//						}
//					}
//				}
//				else if (i == 0 && j == 9) {
//					for (int k = i; k < i + 2; k++) {
//						for (int l = j - 1; l < j + 1; l++) {
//							if (this->board.board[k][l] != 'X') {
//								this->board.board[k][l] = '.';
//							}
//						}
//					}
//				}
//				else if (i == 9 && j == 0) {
//					for (int k = i - 1; k < i + 1; k++) {
//						for (int l = j; l < j + 2; l++) {
//							if (this->board.board[k][l] != 'X') {
//								this->board.board[k][l] = '.';
//							}
//						}
//					}
//				}
//				else if (i > 0 && i < 9 && j == 0) {
//					for (int k = i - 1; k < i + 2; k++) {
//						for (int l = j; l < j + 2; l++) {
//							if (this->board.board[k][l] != 'X') {
//								this->board.board[k][l] = '.';
//							}
//						}
//					}
//				}
//				else if (i > 0 && i < 9 && j == 9) {
//					for (int k = i - 1; k < i + 2; k++) {
//						for (int l = j - 1; l < j + 1; l++) {
//							if (this->board.board[k][l] != 'X') {
//								this->board.board[k][l] = '.';
//							}
//						}
//					}
//				}
//				else if (j > 0 && j < 9 && i == 0) {
//					for (int k = i; k < i + 2; k++) {
//						for (int l = j - 1; l < j + 2; l++) {
//							if (this->board.board[k][l] != 'X') {
//								this->board.board[k][l] = '.';
//							}
//						}
//					}
//				}
//				else if (j > 0 && j < 9 && i == 9) {
//					for (int k = i - 1; k < i + 1; k++) {
//						for (int l = j - 1; l < j + 2; l++) {
//							if (this->board.board[k][l] != 'X') {
//								this->board.board[k][l] = '.';
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//}
//
//bool Player::validateShotNextToShot(Shot x, Shot y) {
//	if ((x.rows == y.rows && (x.columns == y.columns - 1 || x.columns == y.columns + 1)) || (x.columns == y.columns && (x.rows == y.rows - 1 || x.rows == y.rows + 1))) {
//		return true;
//	}
//	else {
//		cout << "Nieprawidlowe miejsce!\n";
//		return false;
//	}
//};
//bool Player::validateShotsForTriplet(Shot x, Shot y, Shot z) {
//
//	if (x.rows == y.rows && y.rows == z.rows) {
//		if (x.columns > y.columns && (z.columns == y.columns - 1 || z.columns == x.columns + 1)) {
//			return true;
//		}
//		else if (x.columns < y.columns && (z.columns == y.columns + 1 || z.columns == x.columns - 1)) {
//			return true;
//		}
//		else {
//			cout << "Nieprawidlowe miejsce!\n";
//			return false;
//		}
//	}
//	if (x.columns == y.columns && y.columns == z.columns) {
//		if (x.rows > y.rows && (z.rows == y.rows - 1 || z.rows == x.rows + 1)) {
//			return true;
//		}
//		else if (x.rows < y.rows && (z.rows == y.rows + 1 || z.rows == x.rows - 1)) {
//			return true;
//		}
//		else {
//			cout << "Nieprawidlowe miejsce!\n";
//			return false;
//		}
//	};
//}
//
//bool Player::validateShotsForQuartet(Shot x, Shot y, Shot z, Shot s) {
//	if (x.rows == y.rows && y.rows == z.rows && z.rows == s.rows) {
//		if (s.columns == x.columns + 1 || s.columns == x.columns - 1 || s.columns == y.columns + 1 || s.columns == y.columns - 1 || s.columns == z.columns + 1 || s.columns == z.columns - 1) {
//			return true;
//		}
//	};
//	if (x.columns == y.columns && y.columns == z.columns && z.columns == s.columns) {
//		if (s.rows == x.rows + 1 || s.rows == x.rows - 1 || s.rows == y.rows + 1 || s.rows == y.rows - 1 || s.rows == z.rows + 1 || s.rows == z.rows - 1) {
//			return true;
//		}
//	}
//}
//virtual void insertSingleShip();
//virtual void insertDoubleShip();
//virtual void insertTripleShip();
//virtual void insertFourMastedShip();
//
//void HumanPlayer::insertSingleShip() {
//
//	unsigned int singleMastedShips = 4;
//	bool validateShot;
//	do
//	{
//		cout << "\nPodaj lokalizacje jednomasztowca.\n";
//		string shot;
//		cin >> shot;
//
//		Shot first(shot);
//		validateShot = this->validateShot(first, board);
//
//		if (validateShot == true) {
//			system("cls");
//			this->updateBoard(first, board);
//			this->blockBusySpace();
//			this->displayBoard();
//			singleMastedShips = singleMastedShips - 1;
//
//		}
//
//	} while (singleMastedShips != 0);
//
//	cout << "Jednomasztowce dodane.\n\n";
//
//
//
//};
//
//void HumanPlayer::insertDoubleShip() {
//
//	unsigned int twoMastedShips = 3;
//	bool validateShot;
//	do
//	{
//		cout << "\nPodaj lokalizacje dwumasztowca.\n";
//		unsigned int twoParts = 2;
//
//		do
//		{
//			cout << "Podaj lokalizacje 1 czesci: \n";
//			string shot;
//			cin >> shot;
//			Shot first(shot);
//			validateShot = this->validateShot(first, board);
//
//			if (validateShot == true) {
//				system("cls");
//				this->updateBoard(first, board);
//				this->displayBoard();
//				twoParts = twoParts - 1;
//
//				do
//				{
//					cout << "Podaj lokalizajce 2 czesci: \n";
//					string shot1;
//					cin >> shot1;
//
//					Shot second(shot1);
//					validateShot = this->validateShot(second, board);
//
//					if (validateShot == true) {
//						bool isNextToPreviousShot;
//						isNextToPreviousShot = this->validateShotNextToShot(shot, shot1);
//
//						if (isNextToPreviousShot == true) {
//							system("cls");
//
//							this->updateBoard(second, board);
//							this->blockBusySpace();
//							this->displayBoard();
//							twoParts = twoParts - 1;
//						}
//					}
//				} while (twoParts != 0);
//			}
//		} while (twoParts != 0);
//
//		twoMastedShips = twoMastedShips - 1;
//
//	} while (twoMastedShips != 0);
//	cout << "Dwumasztowce dodane.\n\n";
//};
//
//
//
//
//void HumanPlayer::insertTripleShip() {
//
//	unsigned int threeMastedShips = 2;
//	bool validateShot;
//
//	do
//	{
//		cout << "\nPodaj lokalizacje trzymasztowca.\n";
//		unsigned int threeParts = 3;
//
//		do
//		{
//			cout << "Podaj lokalizacje 1 czesci: \n";
//			string shot;
//			cin >> shot;
//			Shot first(shot);
//			validateShot = this->validateShot(first, board);
//
//			if (validateShot == true) {
//				system("cls");
//
//				this->updateBoard(first, board);
//				this->displayBoard();
//				threeParts = threeParts - 1;
//
//				do
//				{
//					cout << "Podaj lokalizajce 2 czesci: \n";
//					string shot1;
//					cin >> shot1;
//					Shot second(shot1);
//					validateShot = this->validateShot(second, board);
//					if (validateShot == true) {
//						bool isNextToPreviousShot;
//						isNextToPreviousShot = this->validateShotNextToShot(shot, shot1);
//
//						if (isNextToPreviousShot == true) {
//							system("cls");
//
//							this->updateBoard(second, board);
//							this->displayBoard();
//							threeParts = threeParts - 1;
//							do
//							{
//								cout << "Podaj lokalizajce 3 czesci: \n";
//								string shot2;
//								cin >> shot2;
//								Shot third(shot2);
//								validateShot = this->validateShot(third, board);
//								if (validateShot == true) {
//
//									bool isNexttoPreviousTwoShots;
//									isNexttoPreviousTwoShots = validateShotsForTriplet(shot, shot1, shot2);
//									if (isNexttoPreviousTwoShots == true) {
//										system("cls");
//
//										this->updateBoard(third, board);
//										this->blockBusySpace();
//										this->displayBoard();
//										threeParts = threeParts - 1;
//									}
//								}
//
//							} while (threeParts != 0);
//						}
//					}
//
//				} while (threeParts != 0);
//			}
//		} while (threeParts != 0);
//
//		threeMastedShips = threeMastedShips - 1;
//
//	} while (threeMastedShips != 0);
//	cout << "Trzymasztowce dodane.\n\n";
//
//
//};
//
//void HumanPlayer::insertFourMastedShip() {
//
//	unsigned int fourMastedShips = 1;
//	bool validateShot;
//
//	do
//	{
//		cout << "\nPodaj lokalizacje czteromasztowca.\n";
//		unsigned int fourParts = 4;
//
//		do
//		{
//			cout << "Podaj lokalizacje 1 czesci: \n";
//			string shot;
//			cin >> shot;
//			Shot first(shot);
//			validateShot = this->validateShot(first, board);
//
//			if (validateShot == true) {
//				system("cls");
//
//				this->updateBoard(first, board);
//				this->displayBoard();
//				fourParts = fourParts - 1;
//
//				do
//				{
//					cout << "Podaj lokalizajce 2 czesci: \n";
//					string shot1;
//					cin >> shot1;
//					Shot second(shot1);
//					validateShot = this->validateShot(second, board);
//					bool isNextToPreviousShot = this->validateShotNextToShot(shot, shot1);
//					if (validateShot == true && isNextToPreviousShot == true) {
//						system("cls");
//
//						this->updateBoard(second, board);
//						this->displayBoard();
//						fourParts = fourParts - 1;
//						do
//						{
//							cout << "Podaj lokalizajce 3 czesci: \n";
//							string shot2;
//							cin >> shot2;
//							Shot third(shot2);
//							validateShot = this->validateShot(third, board);
//							bool isNexttoPreviousTwoShots = validateShotsForTriplet(shot, shot1, shot2);
//
//							if (validateShot == true && isNexttoPreviousTwoShots == true) {
//								system("cls");
//
//								this->updateBoard(third, board);
//								this->displayBoard();
//								fourParts = fourParts - 1;
//								do
//								{
//									cout << "Podaj lokalizajce 4 czesci: \n";
//									string shot3;
//									cin >> shot3;
//									Shot four(shot3);
//									validateShot = this->validateShot(four, board);
//									bool isNexttoPreviousThreeShots = validateShotsForQuartet(shot, shot1, shot2, shot3);
//
//									if (validateShot == true && isNexttoPreviousThreeShots == true) {
//										system("cls");
//
//										this->updateBoard(four, board);
//										this->blockBusySpace();
//										this->displayBoard();
//										fourParts = fourParts - 1;
//									};
//								} while (fourParts != 0);
//							};
//						} while (fourParts != 0);
//					};
//				} while (fourParts != 0);
//			};
//		} while (fourParts != 0);
//		fourMastedShips = fourMastedShips - 1;
//		cout << "Czteromasztowiec dodany.\n\n";
//	} while (fourMastedShips != 0);
//
//
//};
//void ComputerPlayer::insertSingleShip() {
//	int column;
//	int row;
//	bool isFree;
//	int ships = 4;
//	srand(time(NULL));
//
//	do
//	{
//		column = rand() % 10;
//		row = rand() % 10;
//		Shot shot(column, row);
//		isFree = validateSpaceForCompleteShip(shot, board, 1);
//		if (isFree == true) {
//			updateBoard(shot, board);
//			blockBusySpace();
//			ships--;
//		}
//	} while (ships != 0);
//	displayBoard();
//};
//
//void ComputerPlayer::insertDoubleShip() {
//	int column;
//	int row;
//	bool isFree;
//	int ships = 3;
//	srand(time(NULL));
//	do
//	{
//		column = rand() % 10;
//		row = rand() % 10;
//		Shot shot(column, row);
//		isFree = validateSpaceForCompleteShip(shot, board, 2);
//		if (isFree == true) {
//			updateBoard(shot, board);
//			vector<Shot> choise = { {column,row + 1},{column,row - 1},{column + 1, row},{column - 1,row} };
//			vector<Shot> choiseValidated;
//			for (int i = 0; i < choise.size(); i++) {
//				isFree = validateShot(choise[i], board);
//				if (isFree == true) {
//					choiseValidated.push_back(choise[i]);
//				}
//			};
//
//			int shot1 = rand() % choiseValidated.size();
//			updateBoard(choiseValidated[shot1], board);
//			blockBusySpace();
//			ships--;
//		}
//	} while (ships != 0);
//	displayBoard();
//};
//
//void ComputerPlayer::insertTripleShip() {
//	int column;
//	int row;
//	bool isFree;
//	int ships = 2;
//	srand(time(NULL));
//	do
//	{
//		column = rand() % 10;
//		row = rand() % 10;
//		Shot shot(column, row);
//		isFree = validateSpaceForCompleteShip(shot, board, 3);
//		if (isFree == true) {
//			updateBoard(shot, board);
//			vector<Shot> choise = { {column,row + 1},{column,row - 1},{column + 1, row},{column - 1,row} };
//			vector<Shot> choiseValidated;
//			for (int i = 0; i < choise.size(); i++) {
//				isFree = validateShot(choise[i], board);
//				if (isFree == true) {
//					choiseValidated.push_back(choise[i]);
//				}
//			};
//
//			int loss = rand() % choiseValidated.size();
//			Shot shot2 = choiseValidated[loss];
//			updateBoard(shot2, board);
//			choiseValidated.clear();
//			choise.clear();
//			if (shot2.columns == shot.columns) {
//				if (shot2.rows > shot.rows) {
//					choise.push_back({ shot.columns,shot.rows - 1 });
//					choise.push_back({ shot2.columns, shot2.rows + 1 });
//
//				}
//				else if (shot2.rows < shot.rows) {
//					choise.push_back({ shot.columns,shot.rows + 1 });
//					choise.push_back({ shot2.columns, shot2.rows - 1 });
//
//				}
//
//			}
//			else if (shot2.rows == shot.rows) {
//				if (shot2.columns > shot.columns) {
//					choise.push_back({ shot.columns - 1,shot.rows });
//					choise.push_back({ shot2.columns + 1, shot2.rows });
//
//
//				}
//				else if (shot2.rows < shot.rows) {
//					choise.push_back({ shot.columns + 1,shot.rows });
//					choise.push_back({ shot2.columns - 1, shot2.rows });
//
//
//				}
//			};
//
//			for (int i = 0; i < choise.size(); i++) {
//				isFree = validateShot(choise[i], board);
//				if (isFree == true && shot.columns < 10 && shot.rows < 10 && shot2.columns < 10 && shot.rows < 10 && shot.columns < 0 && shot.rows < 0 && shot2.columns < 0 && shot.rows < 0) {
//					choiseValidated.push_back(choise[i]);
//				};
//			};
//			int loss2 = rand() % choiseValidated.size();
//			Shot shot3 = choiseValidated[loss2];
//			updateBoard(shot3, board);
//			blockBusySpace();
//			ships--;
//		}
//	} while (ships != 0);
//	displayBoard();
//
//
//
//
//};
//
//void ComputerPlayer::insertFourMastedShip() {
//
//
//
//
//};
