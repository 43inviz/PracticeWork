#include "DebetCard.h"
#define DEBETPATH "../../../DebetCard/debet_card.txt"

void DebetCard::show()
{
	cout << "======\n";
	cout << "Card number: " << this->getCardNumber() << endl;
	cout << "Current balance: " << this->getCurrentBalance() << endl;
	cout << "Type: " << this->getType() << endl;
	cout << "======\n";
}

void DebetCard::addMoneyOnBalance()
{
	double inputSum;
	cout << "Enter the deposit amount: ";
	cin >> inputSum;
	this->depositMoneyOnBalance(inputSum);
	cout << "Done\n";
}

void DebetCard::withDrawFromBalance()
{
	double withdrawSum;
	cout << "Enter withdraw sum: ";
	cin >> withdrawSum;
	if (withdrawSum <= this->getCurrentBalance()) {
		this->withMoneyFromBalance(withdrawSum);
		cout << "Done\n";
	}
	else {
		cout << "You don't have that much money\n";
	}
}

