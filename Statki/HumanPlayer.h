#pragma once
#include "Player.h"
#include <iostream>
#include "Board.h"
#include "Shot.h"
#include "ComputerPlayer.h"

class HumanPlayer :
	public Player
{
protected:
	virtual void addShip(int size);

public:

	virtual void addShips();	
	virtual void guessWhereTheShipsAre();


	HumanPlayer(string playerName);
};



