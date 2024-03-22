
#include <iostream>
#include <cctype>
#include <string>
#include <windows.h>
using namespace std;

class Shot {
public:

	char strColumns;
	char strRows = '0';
	int columns;
	int rows;

	string toValid;

	//napisac funkcje waliduj¹ca poprawnosc podanych wartosci shot'a
	Shot(string UnvalidShot) : toValid(UnvalidShot) {
		this->divideShotID();
		this->convertShotID();
	};


	void divideShotID() {

		if (toValid.length() == 2) {
			this->strColumns = toValid[0];
			this->strRows = toValid[1];
		}
		else if (toValid.length() == 3) {
			this->strColumns = toValid[0];
			this->rows = 0;
		}
		else {
			cout << "Podales niepoprawna lokalizacje. Sprobuj jeszcze raz\n";
		}
	}

	void convertShotID() {
		switch (strColumns) {
		case 'A': columns = 0;
			break;
		case 'B': columns = 1;
			break;
		case 'C': columns = 2;
			break;
		case 'D': columns = 3;
			break;
		case 'E': columns = 4;
			break;
		case 'F': columns = 5;
			break;
		case 'G': columns = 6;
			break;
		case 'H': columns = 7;
			break;
		case 'I': columns = 8;
			break;
		case 'J': columns = 9;
			break;
		}
		switch (strRows) {
		case '1': rows = 0;
			break;
		case '2': rows = 1;
			break;
		case '3': rows = 2;
			break;
		case '4': rows = 3;
			break;
		case '5': rows = 4;
			break;
		case '6': rows = 5;
			break;
		case '7': rows = 6;
			break;
		case '8': rows = 7;
			break;
		case '9': rows = 8;
			break;
		case '0': rows = 9;
			break;
		}
	}


};

class Ship {
private:
	string name;
	int quantity;
	int size;
	bool isFallen;

public:
	//jakas funkcja sprawdzajaca statki
};

class Board {
private:
	string name;
	char board[10][10];
	bool isVisible;



public:

	void fillInBoard() {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				board[i][j] = '~';
			}
		};
	}

	void displayBoard() {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				cout << board[i][j] << " ";
			}
			cout << endl;
		};
	}

	void updateBoard(Shot x) {

		if (this->board[x.rows][x.columns] == 'X' || this->board[x.rows][x.columns] == '.') {
			cout << "To miejsce jest juz zajete. Sprobuj ponownie.\n";

		}
		else {
			this->board[x.rows][x.columns] = 'X';
		}
	}
	void blockBusyPlace(Shot x) {

		if (x.rows > 0 && x.rows < 9 && x.columns>0 && x.columns < 9) {
			for (int i = x.rows - 1; i < x.rows + 2; i++) {
				for (int j = x.columns - 1; j < x.columns + 2; j++) {
					if (this->board[i][j] != 'X') {
						this->board[i][j] = '.';
					}
				}
			}
		}
		else if (x.rows == 0 && x.columns == 0) {
			for (int i = x.rows; i < x.rows + 2; i++) {
				for (int j = x.columns; j < x.columns + 2; j++) {
					if (this->board[i][j] != 'X') {
						this->board[i][j] = '.';
					}
				}
			}
		}
		else if (x.rows == 9 && x.columns == 9) {
			for (int i = x.rows - 1; i < x.rows + 1; i++) {
				for (int j = x.columns - 1; j < x.columns + 1; j++) {
					if (this->board[i][j] != 'X') {
						this->board[i][j] = '.';
					}
				}
			}
		}
		else if (x.rows == 0 && x.columns == 9) {
			for (int i = x.rows; i < x.rows + 2; i++) {
				for (int j = x.columns - 1; j < x.columns + 1; j++) {
					if (this->board[i][j] != 'X') {
						this->board[i][j] = '.';
					}
				}
			}
		}
		else if (x.rows == 9 && x.columns == 0) {
			for (int i = x.rows - 1; i < x.rows + 1; i++) {
				for (int j = x.columns; j < x.columns + 2; j++) {
					if (this->board[i][j] != 'X') {
						this->board[i][j] = '.';
					}
				}
			}
		}
		else if (x.rows > 0 && x.rows < 9 && x.columns == 0) {
			for (int i = x.rows - 1; i < x.rows + 2; i++) {
				for (int j = x.columns; j < x.columns + 2; j++) {
					if (this->board[i][j] != 'X') {
						this->board[i][j] = '.';
					}
				}
			}
		}
		else if (x.rows > 0 && x.rows < 9 && x.columns == 9) {
			for (int i = x.rows - 1; i < x.rows + 2; i++) {
				for (int j = x.columns - 1; j < x.columns + 1; j++) {
					if (this->board[i][j] != 'X') {
						this->board[i][j] = '.';
					}
				}
			}
		}
		else if (x.columns > 0 && x.columns < 9 && x.rows == 0) {
			for (int i = x.rows; i < x.rows + 2; i++) {
				for (int j = x.columns - 1; j < x.columns + 2; j++) {
					if (this->board[i][j] != 'X') {
						this->board[i][j] = '.';
					}
				}
			}
		}
		else if (x.columns > 0 && x.columns < 9 && x.rows == 9) {
			for (int i = x.rows - 1; i < x.rows + 1; i++) {
				for (int j = x.columns - 1; j < x.columns + 2; j++) {
					if (this->board[i][j] != 'X') {
						this->board[i][j] = '.';
					}
				}
			}
		}

	}
	bool validateShot(Shot x, Board playerBoard) {
		if (this->board[x.rows][x.columns] == 'X' || this->board[x.rows][x.columns] == '.') {
			cout << "W tym miejscu nie mozesz postawic statku. Sprobuj ponownie.";
			return false;
		}
		else {
			cout << "Miejsce calkiem OK!\n";
			return true;
		}
	}
	void insertSingleShip(Board playerBoard) {

		unsigned int singleMastedShips = 4;
		bool validateShot;
		do
		{
			cout << "\nPodaj lokalizacje jednomasztowca.\n";
			string shot;
			cin >> shot;
			Shot first(shot);
			validateShot = playerBoard.validateShot(first, playerBoard);

			if (validateShot == true) {
				playerBoard.updateBoard(first);
				playerBoard.blockBusyPlace(first);
				playerBoard.displayBoard();
				singleMastedShips = singleMastedShips - 1;
			}

		} while (singleMastedShips != 0);



	}
	void insertShips(Board playerBoard) {
		unsigned int singleMastedShip = 4;
		unsigned int twoMastedShip = 3;
		unsigned int threeMastedShip = 2;
		unsigned int foursMastedShip = 1;
		unsigned int choise = 0;

		cout << "\nRozmiesc swoje statki.\n\n";

		do
		{
			cout << "Pozostalo do ustawienia: \n" << singleMastedShip << " - jednomasztowce,\n" << twoMastedShip << " - dwumasztowce,\n" << threeMastedShip << " - trzymasztowce,\n" << foursMastedShip << " - czteromasztowiec\n";
			cout << "Wpisz co chcesz dodaC: 1 - jednomasztowiec, 2 - dwumasztowiec, 3 - trzymasztowiec, 4 - czteromasztowiec.\n";
			cin >> choise;

			if (choise == 1) {
				playerBoard.insertSingleShip(playerBoard);
				singleMastedShip = 0;

			}
			else if (choise == 2 && twoMastedShip > 0) {
				//tu kod jak dodawac 2 masztowiec

			}
			else if (choise == 3 && threeMastedShip > 0) {
				//tu kod jak dodawac 3 masztowiec

			}
			else if (choise == 4 && foursMastedShip > 0) {
				//tu kod jak dodawac 4 masztowiec

			}
		} while (singleMastedShip == 0 && twoMastedShip == 0 && threeMastedShip == 0 && foursMastedShip == 0);




	}
};

int main()
{
	cout << "GRA W STATKI\n\n";

	cout << "Witaj! Podaj swoje imie.\n";

	string playerName;
	cin >> playerName;

	cout << "Witaj " << playerName << "!\n";

	Board tablicaPlayera;
	cout << "To twoja plansza: \n";

	tablicaPlayera.fillInBoard();

	tablicaPlayera.displayBoard();

	tablicaPlayera.insertShips(tablicaPlayera);

	/*string shot;
	cin >> shot;

	Shot first(shot);


	tablicaPlayera.updateBoard(first);

	tablicaPlayera.displayBoard();


	cout << "Kolejny 1 masztowiec, wybierz pole na ktorym ma sie znalezc.\n Lokalizacje zapisz w formacie np. A4\n";

	string shot2;
	cin >> shot2;

	Shot first2(shot2);


	tablicaPlayera.updateBoard(first2);

	tablicaPlayera.displayBoard();
	*/


}/*if (x.rows > 0 && x.rows < 9 && x.columns>0 && x.columns < 9) {
	this->board[x.rows - 1][x.columns - 1] = '.';
	this->board[x.rows + 1][x.columns - 1] = '.';
	this->board[x.rows - 1][x.columns + 1] = '.';
	this->board[x.rows + 1][x.columns + 1] = '.';
}
else if (x.rows == 0 && x.columns == 0) {
	this->board[x.rows + 1][x.columns + 1] = '.';
}
else if (x.rows == 0 && x.columns == 9) {
	this->board[x.rows + 1][x.columns - 1] = '.';
}
else if (x.rows == 9 && x.columns == 0) {
	this->board[x.rows - 1][x.columns + 1] = '.';
}
else if (x.rows == 9 && x.columns == 9) {
	this->board[x.rows - 1][x.columns - 1] = '.';
}
else if (x.rows == 0 && (x.columns < 9 && x.columns>0)) {
	this->board[x.rows + 1][x.columns + 1] = '.';
	this->board[x.rows + 1][x.columns - 1] = '.';
}
else if (x.columns == 0 && (x.rows < 9 && x.rows>0)) {
	this->board[x.rows - 1][x.columns + 1] = '.';
	this->board[x.rows + 1][x.columns + 1] = '.';
}
else if (x.rows == 9 && (x.columns < 9 && x.columns>0)) {
	this->board[x.rows - 1][x.columns + 1] = '.';
	this->board[x.rows - 1][x.columns - 1] = '.';
}
else if (x.columns == 9 && (x.rows < 9 && x.rows>0)) {
	this->board[x.rows - 1][x.columns - 1] = '.';
	this->board[x.rows + 1][x.columns - 1] = '.';
}
		}
		*/