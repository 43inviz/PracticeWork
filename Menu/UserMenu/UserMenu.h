#pragma once
#include <iostream>
using namespace std;


void lining(int count) {
	for (int i = 0; i < count; i++) {
		cout << "=";
	}
	cout << "\n";
}

void startMenu() {
	cout << "WELCOME IN M/L BANK(MAX/LESHA)\n";
	lining(10);
	cout << "If you have an account with our bank press [1]\n";
	cout << "If you want to register press [2]\n";
	lining(10);
	cout << "Enter choice: ";
}

