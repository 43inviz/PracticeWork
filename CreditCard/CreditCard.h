#pragma once
#include "../PaymentSystem/PaymentSystem.h"
#include <string>

class CreditCard :public PaymentSystem {
	double _currentCreditBalance;
	static double _creditLimit;
public:

	CreditCard() = default;
	CreditCard(string cardNumber, string type) :PaymentSystem(cardNumber, type), _currentCreditBalance(_creditLimit) {}

	void show();

	void addMoneyOnBalance();
	void withDrawFromBalance();

	void addMoneyOnCreditBalance(double inputSum) { _currentCreditBalance += inputSum; }
	void withDrawMoneyFromCredit(double withDrawSum) { _currentCreditBalance -= withDrawSum; }

	bool isAnyLoan() { return _currentCreditBalance == _creditLimit; }
};

