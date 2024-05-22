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
	_purVec.push_back(pur);

	//_purVec.push_back()
}

void Card::addMoney()
{
	double inputSum;
	cout << "Enter the amount of funds to deposit: ";
	cin >> inputSum;
	this->addSumOnBal(inputSum);
	cout << "Funds deposited successfully\n";
}
;
void Card::addSumOnBal(double sum)
{
	_currentBalance += sum;
}

void Card::showReport()
{
	Reports rep;
	rep.reportSetup();
	rep.showReport(_purVec);

}
