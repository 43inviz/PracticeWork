#include "../User/User.h"
#include "../Purchase.h"
#include "../Reports.h"
#include "../Date.h"
#include <string>
#include <vector>
using namespace std;

class Payment :public User {
	vector<int> _cardNumber;
	double _currentBalance;
	vector<Purchase> _purVec;
public:
	Payment() = default;
	Payment(string name, string login, string pass) :User(name, login, pass),_currentBalance(0){
		
		for (int i = 0; i < 10; i++) {
			_cardNumber.push_back(rand() % 9);
		}
	}

	virtual void show() {

		User::showUser();
		cout << "Card number: ";
 		showCardNumber();
		cout << "Current balance: " << _currentBalance << endl;
	}
	virtual void addMoney() = 0;
	virtual void takeMoney() = 0;

	void setBalance(double balance) { _currentBalance = balance; }
	void setNumber(vector<int>cardNumber) { _cardNumber = cardNumber; }
	void setPurVector(vector<Purchase>purVec) { _purVec = purVec; }

	vector<int> getCardNumber()const { return _cardNumber; }
	double getCurrentBalance() const { return _currentBalance; }
	vector<Purchase> getPurchaseVector() const { return _purVec; }

	void addMoneyOnBalance(double sum) {_currentBalance += sum;}
	void withDrawMoneyFromBalance(double sum) { _currentBalance -= sum; }

	void setPurInVec(Purchase pur);


	void showCardNumber() const;
	void showPur();
	
};