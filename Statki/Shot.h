#pragma once
#include <string>
using namespace std;

class Shot
{
public:

	char strColumns;
	char strRows='0';
	int columns;
	int rows;
	string toValid;

	Shot(string UnvalidShot);

	void divideShotID();
	void convertShotID();


};

