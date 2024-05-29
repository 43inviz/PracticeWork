#pragma once
#include "../PaymentSystem/PaymentSystem.h"
#include "../DebetCard/DebetCard.h"
#include "../CreditCard/CreditCard.h"

#include "../Purchase/Purchase.h"



#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class User {
	string _userName;
	string _userLogin;
	string _userPass;


	vector<shared_ptr<PaymentSystem>> _userPayments;
	

public:
	User() = default;
	User(string name, string login, string pass) :_userName(name), _userLogin(login), _userPass(pass) {}

	User(string name, string login, string pass, vector<shared_ptr<PaymentSystem>> userPayments) :_userName(name), _userLogin(login), _userPass(pass), _userPayments(userPayments) {}

	void setName(string name) { _userName = name; }
	void setLogin(string login) { _userLogin = login; }
	void setPass(string pass) { _userPass = pass; }
	void setUserPayments(vector<shared_ptr<PaymentSystem>> userPayments) { _userPayments = userPayments; }

	string getName() const { return _userName; }
	string getLogin() const { return _userLogin; }
	string getPass() const { return _userPass; }
	vector<shared_ptr<PaymentSystem>> getPayments() const { return _userPayments; }

	void addDebetCard(DebetCard& card);
	void addCreditCard(CreditCard& card);

	void createNewPayment();


	string createNewCardNumer();


	void showAllPaymentSystems();

	bool authorization(vector<User> userVec);
	void registration();

	void showUser() {
		cout << _userName << endl;
		cout << _userLogin << endl;
		cout << _userPass << endl;
	}

};
