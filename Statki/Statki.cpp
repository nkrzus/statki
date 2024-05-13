
#include <iostream>
#include <cctype>
#include <string>
#include <windows.h>
#include "Shot.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "Board.h"
#include "Statki.h"
using namespace std;

void whoIsTheWinner(bool areHumanPlayerWin, HumanPlayer& player1, bool areComputerPlayerWin, ComputerPlayer& player2)
{
	if (areHumanPlayerWin) {
		cout << "GRATULACJE " << player1.getName() << " - ZWYCIESTWO JEST TWOJE!\n";
	}
	else if (areComputerPlayerWin) {
		cout << "GRATULACJE " << player2.getName() << " - ZWYCIESTWO JEST TWOJE!\n";
	}
}

void playingTheGame(HumanPlayer& player1, bool& areHumanPlayerWin, ComputerPlayer& player2, bool& areComputerPlayerWin)
{
	do
	{
		player1.guessWhereTheShipsAre();
		areHumanPlayerWin = player1.areYouWinner(player1.playBoard, player1.oponentBoard);
		if (areHumanPlayerWin == false) {
			player2.guessWhereTheShipsAre();
			areComputerPlayerWin = player2.areYouWinner(player2.playBoard, player2.oponentBoard);
		}
	} while (!areComputerPlayerWin && !areHumanPlayerWin);
}

void game()
{
	cout << "Witaj! Podaj swoje imie.\n";
	string playerName;
	cin >> playerName;
	cout << "Witaj " << playerName << "!\n";

	HumanPlayer player1(playerName);
	ComputerPlayer player2;

	player1.addShips();
	player2.addShips();

	player1.oponentBoard = player2.getBoard();
	player2.oponentBoard = player1.getBoard();

	bool areHumanPlayerWin = false;
	bool areComputerPlayerWin = false;

	playingTheGame(player1, areHumanPlayerWin, player2, areComputerPlayerWin);
	whoIsTheWinner(areHumanPlayerWin, player1, areComputerPlayerWin, player2);
}

int main()
{
	srand(time(0));
	cout << "GRA W STATKI\n\n";
	game();
	return 0;
}