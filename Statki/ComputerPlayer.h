#pragma once
#include "Player.h"
#include <string>
#include "ComputerPlayer.h"
#include <string>
#include <iostream>
#include "Board.h"
#include <vector>
using namespace std;

class ComputerPlayer :
	public Player
{
protected:
	virtual void addShip(int size);


public:
	virtual void addShips();
	virtual void guessWhereTheShipsAre();

	ComputerPlayer();
};

