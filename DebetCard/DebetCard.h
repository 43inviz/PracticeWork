#pragma once
#include "../PaymentSystem/PaymentSystem.h"
#include <string>

class DebetCard :public PaymentSystem {
public:
	DebetCard() = default;
	DebetCard(string cardNumber, string type) :PaymentSystem(cardNumber, type) {}

	void show();
	void addMoneyOnBalance();
	void withDrawFromBalance();

	/*void savePaymentOnFile();
	void readPaymentsFromFile(vector<PaymentSystem> vec);*/
};