#pragma once
#include "Card.h"

using namespace std;

class CreditCard :public Card {

	double _currentCreditBalance;
	
public:
	static double _creditLimit;
	CreditCard() = default;
	CreditCard(string name,string login,string pass,int type):Card(name,login,pass,type),_currentCreditBalance(_creditLimit){}

	void setCreditBalance(double balance) { _currentCreditBalance = balance; }
	double getCreditBalance() const { return _currentCreditBalance; }

	void show();

	void addMoney();
	void takeMoney();

	void takeMoneyFromCreditBalance(double sum) { _currentCreditBalance -= sum; }
	void addMoneyOnCreditBalance(double sum) { _currentCreditBalance += sum; }

	bool isValidTake(double sum);

	bool isAnyDebt() { return _currentCreditBalance == _creditLimit; }
};

