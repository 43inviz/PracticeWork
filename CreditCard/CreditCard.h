#pragma once
#include "../PaymentSystem/PaymentSystem.h"
#include <string>

class CreditCard :public PaymentSystem {
	double _currentCreditBalance;
	static double _creditLimit;
public:

	CreditCard() = default;
	CreditCard(string ownername, string cardNumber, string type) :PaymentSystem(ownername, cardNumber, type), _currentCreditBalance(_creditLimit) {}
	CreditCard(string ownername, string cardNumber, string type,double balance) :PaymentSystem(ownername, cardNumber, type,balance), _currentCreditBalance(_creditLimit) {}

	void show();

	void addMoneyOnBalance();
	void withDrawFromBalance();

	double getCurrentCreditBalance() { return _currentCreditBalance; }
	void setCurrentCreditBalance(double balance) { _currentCreditBalance = balance; }

	void addMoneyOnCreditBalance(double inputSum) { _currentCreditBalance += inputSum; }
	void withDrawMoneyFromCredit(double withDrawSum) { _currentCreditBalance -= withDrawSum; }

	bool isAnyLoan() { return _currentCreditBalance == _creditLimit; }
};

