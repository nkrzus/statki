#include "Player.h"

void Player::displayBoard(Board board) {
	cout << " / A B C D E F G H I J \n";
	for (int i = 0; i < 10; i++) {
		if (i == 9) {
			cout << i + 1 << " ";
		}
		else {
			cout << " " << i + 1 << " ";
		};
		for (int j = 0; j < 10; j++) {
			cout << board.board[i][j] << " ";
		}
		cout << endl;
	};
}

bool Player::validationOfShot(Shot x) {
	if (x.columns < 10 && x.columns >= 0 && x.rows < 10 && x.rows >= 0) {
		return true;
	}
	else {
		cout << "Strzal jest niepoprawny. Podaj poprawnie lokalizacje (np A5, D10). \n";
		return false;
	}
}
void Player::updateBoard(Shot x) {
	this->board.board[x.rows][x.columns] = 'X';
}

void Player::updatePlayBoard(Shot x) {
	this->playBoard.board[x.rows][x.columns] = 'X';
}

void Player::updatePlayBoardFail(Shot x) {
	this->playBoard.board[x.rows][x.columns] = '.';
}

bool Player::validateShot(Shot x, Board board) {
	if (!validationOfShot(x)) {
		return false;
	}
	else {
		if (board.board[x.rows][x.columns] != '~') {
			return false;
		}
		else if ((board.board[x.rows][x.columns] == '~')) {
			return true;
		}
	}



};

string Player::getName() {
	return name;
};

Board Player::getBoard() {
	return board;
};

bool Player::isShipHere(Shot x, Board board) {
	if (!validateShot(x, board)) {
		return true;
	}
	else
	{
		return false;
	}
}


bool Player::getElementFromBoard(Shot x) {
	if (!validateShot(x, board)) {
		return true;
	}
	else {
		return false;
	}
}

bool Player::areYouWinner(Board myPlayBoard, Board myOponentBoard) {
	int allXOnBoard = 20;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10;j++) {
			if (myOponentBoard.board[i][j] == 'X' && myPlayBoard.board[i][j] == 'X')
				allXOnBoard -= 1;
			else continue;
		}	
	}

	if (allXOnBoard == 0) {
		return true;
	}
	else {
		return false;
	}
}
Player::Player(string playerName) : name(playerName) {
};

