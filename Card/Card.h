#pragma once
#include "../User/User.h"
#include "../Purchase.h"
#include "../Reports.h"
#include "../Date.h"
#include <string>
#include <vector>
using namespace std;

class Card :public User {

	vector<int> _cardNumber;
	double _currentBalance;
	vector<Purchase> _purVec;
	int _type;
public:
	Card() {};
	Card(string name, string login, string pass, int type) :User(name, login, pass), _type(type),_currentBalance(0) {
		
		for (int i = 0; i < 10; i++) {
			_cardNumber.push_back(rand() % 9);
		}

		
	}

	void setBalance(double balance) { _currentBalance = balance; }
	void setType(int type) { _type = type; }

	vector<int> getCardNumber() const { return _cardNumber; }
	double getBalance() const { return _currentBalance; }
	int getType() const { return _type; }

	void addSpend();
	
	void showInfo() {
		User::show();
		cout << "Card number: ";
		for (int i = 0; i < _cardNumber.size(); i++) {
			cout << _cardNumber[i];
		}
		cout << endl;
		cout << "Current balance: " << _currentBalance << endl;
		cout << "Type: " << _type << endl;

	}

	void showPur() {

		for (int i = 0; i < _purVec.size();i++) {
			cout << _purVec[i].getDate().showDate(); // out date;
			cout << _purVec[i].getPrice(); // out price
			cout << _purVec[i].getCategory(); // out category
			cout << endl;
		}
	}

	void addMoney();
	void addSumOnBal(double sum);

	void showReport();

};