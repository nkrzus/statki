
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


	int i = 80;
	do
	{
	player1.guessWhereTheShipsAre();
	player2.guessWhereTheShipsAre();
	i--;

	} while (i!=0);

} 