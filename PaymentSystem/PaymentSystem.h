#pragma once
#include "../Purchase/Purchase.h"
#include <iostream>
#include <vector>

using namespace std;

class PaymentSystem {

	string _cardNumber;
	double _currentBalance;
	string _type;

	vector<Purchase> _purVec;
public:
	PaymentSystem() = default;
	PaymentSystem(string cardNumber, string type) : _cardNumber(cardNumber), _type(type), _currentBalance(0.0) {}


	string getCardNumber() const { return _cardNumber; }
	double getCurrentBalance() const { return _currentBalance; }
	string getType()const { return _type; }

	void setCardNumber(string cardNumber) { _cardNumber = cardNumber; }
	void setType(string type) { _type = type; }
	void setCurrentBalance(double balance) { _currentBalance = balance; }


	virtual void show() = 0;
	virtual void addMoneyOnBalance() = 0;
	virtual void withDrawFromBalance() = 0;

	void depositMoneyOnBalance(double sum) { _currentBalance += sum; }
	void withMoneyFromBalance(double sum) { _currentBalance -= sum; }

	void addPurchaseInPayment(Purchase& pur) { _purVec.push_back(pur); }


};