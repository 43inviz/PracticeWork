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
<<<<<<< HEAD
	Card() = default;
	Card(string name,string login,string pass,int type):Payment(name,login,pass),_type(type){
		vector<int> cardNumber(10);
		for (auto i = cardNumber.begin(); i != cardNumber.end(); i++) {
			*i = rand() % 9;
		}

		this->setNumber(cardNumber);
=======
	Card() {};
	Card(string name, string login, string pass, int type) :User(name, login, pass), _type(type),_currentBalance(0) {
			
		for (int i = 0; i < 10; i++) {
			_cardNumber.push_back(rand() % 9);
		}
>>>>>>> 3d1b0ac31f0de87e69218065688c5b99e9717857
	}

	void setType(int type) { _type = type; }
	int getType() const { return _type; }

	void addSpend();
	void show();

	void takeMoney();
	void addMoney();
	
	void showReport();

};

