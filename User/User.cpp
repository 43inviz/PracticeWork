#include "User.h"

void User::addDebetCard(DebetCard& card)
{
	shared_ptr<PaymentSystem> debetCard = make_shared<DebetCard>(card);
	_userPayments.push_back(debetCard);
}

void User::addCreditCard(CreditCard& card)
{
	shared_ptr<PaymentSystem> creditCard = make_shared<CreditCard>(card);
	_userPayments.push_back(creditCard);
}

void User::createNewPayment()
{
	int choice;
	cout << "1 - create Debet Card\n";
	cout << "2 - create Credit Card\n";
	cout << "Enter choice: ";
	cin >> choice;

	switch (choice) {
	case 1: {
		DebetCard debetCard(this->createNewCardNumer(), "debet");
		addDebetCard(debetCard);
		break;
	}
	case 2: {
		CreditCard creditCard(this->createNewCardNumer(), "credit");
		addCreditCard(creditCard);
		break;

	}
	
	default:
		break;
	}
}

string User::createNewCardNumer()
{
	string newCard;
	for (int i = 0; i < 10; i++) {
		newCard += to_string(rand() % 10);
	}
	return newCard;
}



void User::showAllPaymentSystems()
{
	for (auto i = _userPayments.begin(); i != _userPayments.end(); i++) {
		(*i)->show();
	}
}

bool User::authorization(vector<User> userVec)
{
	string login, pass;

	cout << "Enter login: ";
	getline(cin, login);
	cout << "Enter pass: ";
	getline(cin, pass);

	for (auto i = userVec.begin(); i != userVec.end(); i++) {
		if (i->_userLogin == login && i->_userPass == pass) {
			this->setName(i->getName());
			this->setLogin(i->getLogin());
			this->setPass(i->getPass());
			return true;
		}
	}
	return false;


}

void User::registration()
{
	string newName, newLogin, newPass;
	cout << "Enter your name: ";
	getline(cin, newName);
	cout << "Enter your login: ";
	getline(cin, newLogin);
	cout << "Create password: ";
	getline(cin, newPass);

	this->setName(newName);
	this->setPass(newPass);
	this->setLogin(newLogin);

	
}
