#pragma once
#include "../../User/User.h"
#include <iostream>
using namespace std;


void lining(int count) {
	for (int i = 0; i < count; i++) {
		cout << "=";
	}
	cout << "\n";
}

void startMenu() {
	//system("cls");
	cout << "WELCOME IN M/L BANK(MAX/LESHA)\n";
	lining(10);
	cout << "If you have an account with our bank press [1]\n";
	cout << "If you want to register press [2]\n";
	lining(10);
	cout << "Enter choice: ";
}

void sectionMenu(User& user) {
	//system("cls");
	lining(10);
	cout << "Welcome back " << user.getName() << endl;
	cout << "[1] - INFORMATION\n";
	cout << "[2] - CARDS\n";
	cout << "[3] - REPORTS\n";
	cout << "[4] - RATINGS\n";
	cout << "[0] - EXIT\n";
	lining(10);
	cout << "Enter choice: ";

}


void informationMenu() {
	//system("cls");
	lining(10);
	cout << "[1] - SHOW ALL PERSONAL CARDS\n";
	cout << "[2] - SHOW ALL PURCHASE\n";
	cout << "[3] - SHOW USER INFORMATION\n";
	cout << "[0] - RETURN BACK\n";
	lining(10);
	cout << "Enter choice: ";

}


void cardsMenu() {
	//system("cls");
	cout << "CARDS\n";
	lining(10);
	cout << "[1] - CREATE NEW CARD\n";
	cout << "[2] - ADD NEW PURCHASE\n";
	cout << "[3] - TOP UP BALANCE\n";
	cout << "[4] - WITH DRAW FROM BALANCE\n";
	cout << "[0] - RETURN BACK\n";
	lining(10);
	cout << "Enter choice: ";

}


void reportsMenu() {
	//system("cls");
	cout << "REPORTS\n";
	lining(10);
	cout << "[1] - CREATE REPORT\n";
	cout << "[2] - SHOW REPORT\n";
	cout << "[3] - SAVE TO FILE\n";
	cout << "[4] - READ FROM FILE\n";
	lining(10);
	cout << "Enter choice: ";

}


void ratingsMenu() {
	//system("cls");
	cout << "RATING\n";
	lining(10);
	cout << "[1] - CREATE RATING\n";
	cout << "[2] - SAVE TO FILE\n";
	cout << "[0] - RETURN BACK\n";
	lining(10);
	cout << "Enter choice: ";

}

