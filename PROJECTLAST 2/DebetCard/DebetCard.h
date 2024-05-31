#pragma once
#include "../PaymentSystem/PaymentSystem.h"
#include <string>

class DebetCard :public PaymentSystem {
public:
	DebetCard() = default;
	DebetCard(string ownerName, string cardNumber, string type) :PaymentSystem(ownerName, cardNumber, type) {}
	DebetCard(string ownerName, string cardNumber, string type,double balance) :PaymentSystem(ownerName, cardNumber, type,balance) {}


	void show();
	void addMoneyOnBalance();
	void withDrawFromBalance();

};