#include <iostream>
#include <stdexcept>
#include <string>
#include "Database.h"

using namespace std;
using namespace Records;

int displayMenu();
void doGiveBonus(Database& inDB);
void doGivePenalty(Database& inDB);
void doAddPosition(Database& inDB);

int main(int argc, char** argv) {
	Database positionsDB;
	bool done = false;
	while (!done) {
		int selection = displayMenu();
		switch (selection) {
			case 1:
				doGiveBonus(positionsDB);
				break;
			case 2:
				doGivePenalty(positionsDB);
				break;
			case 3:
				doAddPosition(positionsDB); 
				break;
			case 4:
				positionsDB.displayAll();
				break;
			case 0:
				done = true;
				break;
			default:
				cerr << "Unknown command." << endl;
		}
	}
}

int displayMenu() {
	int selection;
	cout << endl;
	cout << "Positions Database" << endl;
	cout << "-----------------" << endl;
	cout << "1) Give bonus to a position" << endl;
	cout << "2) Assign penalty to a position" << endl;
	cout << "3) Add a position" << endl;
	cout << "4) List all positions" << endl;
	cout << "0) Quit" << endl;
	cout << endl;

	cout << "---> ";
	cin >> selection;
	return selection;
}

void doAddPosition(Database& inDB) {
	string PositionTitle;
	int Oklad;
	string Obovyazky;
	string Vymogy;
	cout << "What is the title? ";
	cin >> PositionTitle;
	cout << "What salary? ";
	cin >> Oklad;
	cout << "What are the responsibilities? ";
	cin >> Obovyazky;
	cout << "What requirements? ";
	cin >> Vymogy;
	try {
		inDB.addEmployee(PositionTitle, Oklad, Obovyazky, Vymogy);
	} 
	catch (std::exception ex) {
		cerr << "Unable to add a position!" << endl;
	}
}

void doGiveBonus(Database& inDB) {
	int positionNumber;
	int bonusSize;
	cout << "Position code? ";
	cin >> positionNumber;
	cout << "Bonus amount? ";
	cin >> bonusSize;
	try {
	Position& emp = inDB.getPosition(positionNumber);
	emp.giveBonus(bonusSize);
	cout << "With bonus " << emp.getPositionTitle() << "'s new salary is " << emp.getOklad() << "." << endl;
	} 
	catch (std::exception ex) {
	cerr << "Unable to terminate position!" << endl;
	}
}

void doGivePenalty(Database& inDB) {
	int positionNumber;
	int penaltySize;
	cout << "Position code? ";
	cin >> positionNumber;
	cout << "Penalty amount? ";
	cin >> penaltySize;
	try {
	Position& emp = inDB.getPosition(positionNumber);
	emp.givePenalty(penaltySize);
	cout << "With penalty " << emp.getPositionTitle() << "'s new salary is " << emp.getOklad() << "." << endl;
	} 
	catch (std::exception ex) {
	cerr << "Unable to terminate position!" << endl;
	}
}