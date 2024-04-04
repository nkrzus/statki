#include "Shot.h"
#include <string>
#include <iostream>

using namespace std;

Shot::Shot(string UnvalidShot) : toValid(UnvalidShot) {
	this->divideShotID();
	this->convertShotID();
};


void Shot::divideShotID() {

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

void Shot::convertShotID() {
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


