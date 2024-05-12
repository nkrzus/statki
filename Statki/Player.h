#pragma once
#include <string>
#include "Board.h"
#include <iostream>
using namespace std;

class Player
{
private:
	string name;
	
protected:
	Board board;

	virtual void addShip(int size) = 0;

	void displayBoard(Board board);

	bool validateShot(Shot x, Board playerBoard);

	void updateBoard(Shot x);
	void updatePlayBoard(Shot x);

	void updatePlayBoardFail(Shot x);

	virtual void guessWhereTheShipsAre()=0;


	bool isShipHere(Shot x, Board board);

public:
	virtual void addShips() = 0;
	Board playBoard;
	Board oponentBoard;
	Board getBoard();
	bool getElementFromBoard(Shot x);
	bool validationOfShot(Shot x);
	bool areYouWinner(Board myPlayBoard, Board myOponentBoard);
	string getName();

	Player(string playerName);
	
};

