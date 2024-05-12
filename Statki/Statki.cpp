
#include <iostream>
#include <cctype>
#include <string>
#include <windows.h>
#include "Shot.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "Board.h"
using namespace std;

class Ship {
private:
	string name;
	int quantity;
	int size;
	bool isFallen;

public:
	//jakas funkcja sprawdzajaca statki
};


int main()
{
	srand(time(0));
	cout << "GRA W STATKI\n\n";

	cout << "Witaj! Podaj swoje imie.\n";

	string playerName;
	cin >> playerName;

	cout << "Witaj " << playerName << "!\n";

	HumanPlayer player1(playerName);

	player1.addShips();
	ComputerPlayer player2;
	player2.addShips();

	//przepisanie tablic przeciwnikow 
	player1.oponentBoard = player2.getBoard();
	player2.oponentBoard = player1.getBoard();

	bool areHumanPlayerWin = false;
	bool areComputerPlayerWin = false;

	do
	{
		player1.guessWhereTheShipsAre();
		areHumanPlayerWin = player1.areYouWinner(player1.playBoard, player1.oponentBoard);
		if (areHumanPlayerWin == false) {
			player2.guessWhereTheShipsAre();
			areComputerPlayerWin = player2.areYouWinner(player2.playBoard, player2.oponentBoard);
		}
	} while (!areComputerPlayerWin && !areHumanPlayerWin);

	if (areHumanPlayerWin) {
		cout << "GRATULACJE " << player1.getName() << " - ZWYCIESTWO JEST TWOJE!\n";	
	}
	else if (areComputerPlayerWin) {
		cout << "GRATULACJE " << player2.getName() << " - ZWYCIESTWO JEST TWOJE!\n";
	}
}