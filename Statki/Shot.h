#pragma once
#include <string>
using namespace std;
#include <iostream>


class Shot
{
public:

	char strColumns='0';
	char strRows='0';
	int columns;
	int rows;
	string toValid;

	Shot(string UnvalidShot);
	Shot(int columns, int rows);

	void divideShotID();
	void convertShotID();

};

