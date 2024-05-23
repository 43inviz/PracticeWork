#pragma once
#include "PaymentMethods.h"
#include "../User/User.h"
#include "../Purchase.h"
#include "../Reports.h"
#include "../Date.h"
#include <string>
#include <vector>
using namespace std;

class Card :public Payment {
	int _type;
public:
	Card() = default;
	Card(string name,string login,string pass,int type):Payment(name,login,pass),_type(type){
		vector<int> cardNumber(10);
		for (auto i = cardNumber.begin(); i != cardNumber.end(); i++) {
			*i = rand() % 9;
		}

		this->setNumber(cardNumber);
	}

	void setType(int type) { _type = type; }
	int getType() const { return _type; }

	void addSpend();
	void show();

	void takeMoney();
	void addMoney();
	
	void showReport();

};

