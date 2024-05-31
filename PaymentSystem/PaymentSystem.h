#pragma once
#include "../Exceptions/Exception.h"
#include "../Purchase/Purchase.h"
#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

class PaymentSystem {
	string _ownerName;
	string _cardNumber;
	double _currentBalance;
	string _type;
	vector<Purchase> _purVec;


public:
	PaymentSystem() = default;
	PaymentSystem(string ownerName, string cardNumber, string type) : _ownerName(ownerName), _cardNumber(cardNumber), _type(type), _currentBalance(0.0) {}
	PaymentSystem(string ownerName,string cardNumber,string type,double balance) :_ownerName(ownerName),_cardNumber(cardNumber),_type(type), _currentBalance(balance){}


	string getCardNumber() const { return _cardNumber; }
	double getCurrentBalance() const { return _currentBalance; }
	string getType()const { return _type; }
	string getOwnerName() const { return _ownerName; }

	void setCardNumber(string cardNumber) { _cardNumber = cardNumber; }
	void setType(string type) { _type = type; }
	void setCurrentBalance(double balance) { _currentBalance = balance; }
	void setOwnerName(string name) { _ownerName = name; }


	virtual void show() = 0;
	virtual void addMoneyOnBalance() = 0;
	virtual void withDrawFromBalance() = 0;

	void depositMoneyOnBalance(double sum) { _currentBalance += sum; }
	void withMoneyFromBalance(double sum) { _currentBalance -= sum; }

	void addPurchaseInPayment(Purchase& pur) { _purVec.push_back(pur); }

	void showPaymentPurchase() {
		for (auto& purchase : _purVec) {
			purchase.showPurchase();
		}
	}

};