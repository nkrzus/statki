
#include <iostream>
#include <cctype>
#include <string>
using namespace std;

class Shot {
public:

	char strColumns;
	char strRows;
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
			this->strRows = toValid[1] + toValid[2];
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
		case '10': rows = 9;
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
		this->board[x.columns][x.rows] = 'X';
		if (x.columns > 0 && x.columns < 9 && x.rows>0 && x.rows < 9) {
			this->board[x.columns - 1][x.rows - 1] = '.';
			this->board[x.columns + 1][x.rows - 1] = '.';
			this->board[x.columns - 1][x.rows + 1] = '.';
			this->board[x.columns + 1][x.rows + 1] = '.';
		}
		else if (x.columns == 0 && x.rows == 0) {
			this->board[x.columns + 1][x.rows + 1] = '.';
		}
		else if (x.columns == 0 && x.rows == 9) {
			this->board[x.columns + 1][x.rows - 1] = '.';
		}
		else if (x.columns == 9 && x.rows == 0) {
			this->board[x.columns - 1][x.rows + 1] = '.';
		}
		else if (x.columns == 9 && x.rows == 9) {
			this->board[x.columns - 1][x.rows - 1] = '.';
		}
		else if (x.columns == 0 && (x.rows < 9 && x.rows>0)) {
			this->board[x.columns + 1][x.rows + 1] = '.';
			this->board[x.columns + 1][x.rows - 1] = '.';
		}
		else if (x.rows == 0 && (x.columns < 9 && x.columns>0)) {
			this->board[x.columns - 1][x.rows + 1] = '.';
			this->board[x.columns + 1][x.rows + 1] = '.';
		}
		else if (x.columns == 0 && (x.rows < 9 && x.rows>0)) {
			this->board[x.columns - 1][x.rows + 1] = '.';
			this->board[x.columns - 1][x.rows - 1] = '.';
		}
		else if (x.rows == 9 && (x.columns < 9 && x.columns>0)) {
			this->board[x.columns - 1][x.rows - 1] = '.';
			this->board[x.columns + 1][x.rows - 1] = '.';
		}
	}

	//void ifFieldIsValid(Point x) {
	//	if (Point x) {}
	//}

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

	cout << "\n Rozmiesc swoje statki.\n ";

	cout << "Najpierw 1 masztowiec, wybierz pole na ktorym ma sie znalezc.\n Lokalizacje zapisz w formacie np. A4\n";


	string shot;
	cin >> shot;

	Shot first(shot);

	cout << "Wpisales: " << first.columns << " " << first.rows << endl;

	tablicaPlayera.updateBoard(first);

	tablicaPlayera.displayBoard();
	cout << "Kolejny 1 masztowiec, wybierz pole na ktorym ma sie znalezc.\n Lokalizacje zapisz w formacie np. A4\n";

	string shot2;
	cin >> shot2;

	Shot first2(shot2);

	cout << "Wpisales: " << first2.columns << " " << first2.rows << endl;

	tablicaPlayera.updateBoard(first2);

	tablicaPlayera.displayBoard();



}
