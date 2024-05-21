#pragma once

#include <iostream>

using namespace std;


void lining(int count) {
	while (count != 0) {
		cout << "=";
		count--;

	}
}

void choiceEnterMenu() {
	cout << "Enter 1 - if u HAVE OUR BANK ACCOUNT\n";
	cout << "Enter 2 - if u WANT TO REGISTER NEW BANK ACCOUNT\n";
	lining(15);
	cout << "\nEnter choice: ";
}

void enterMenu() {
	int lineSize = 10;
	lining(lineSize);
	cout << "\nBANK NAME\n";
	lining(lineSize);

	int choice;
	do {
		choiceEnterMenu();
		cin >> choice;

	} while (choice != 0);




}