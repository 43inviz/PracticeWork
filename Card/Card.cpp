#include "Card.h"

void Card::addSpend()
{
	Date date;
	double price;
	string category;

	cout << "Enter price: ";
	cin >> price;
	cout << endl;

	cout << "Enter date: ";
	date.inputDate();

	cout << "Enter category: ";
	getline(cin, category);
	Purchase pur(price, date, category);

	setPurInVec(pur);
}

void Card::show()
{
	User::showUser();
	cout << "Type: " << _type << endl;
	cout << "Current balance: " << this->getCurrentBalance() << endl;
	cout << "Card number: ";
	Payment::showCardNumber();
}

void Card::takeMoney()
{
	double withSum;
	cout << "Enter with sum: ";
	cin >> withSum;
	withDrawMoneyFromBalance(withSum);
}

void Card::addMoney()
{
	double addSum;
	cout << "Enter input sum: ";
	cin >> addSum;
	this->addMoneyOnBalance(addSum);
	cout << "Done\n";
}

void Card::showReport()
{
	Reports rep;
	rep.reportSetup();
	rep.showReport(getPurchaseVector());
}

