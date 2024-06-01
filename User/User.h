#pragma once
<<<<<<< HEAD
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "../Exception.h"
using namespace std;
#define FILENAME "../users.txt"
=======
#include "../PaymentSystem/PaymentSystem.h"
#include "../DebetCard/DebetCard.h"
#include "../CreditCard/CreditCard.h"

#include "../Purchase/Purchase.h"

#include "../FileSystm/CreditFileSyst/CreditFileSyst.h"
#include "../FileSystm/DebetFile/DebetFileSyst.h"
#include "../FileSystm/PurchseFile/PurchaseFileSyst.h"

#include "../Ratings/Ratings.h"




#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
>>>>>>> 53d9510 (proj)

class User {
	string _userName;
	string _userLogin;
	string _userPass;
<<<<<<< HEAD
public:

	User() {};
	User(string name, string login, string pass) :_userName(name), _userLogin(login), _userPass(pass) {}

	void setName(string name) {
		_userName = name;
	}

	void setLogin(string login) {
		_userLogin = login;
	}


	void setPass(string pass) {
		_userPass = pass;
	}

	string getName() const {
		return _userName;
	}

	string getLogin() const {
		return _userLogin;
	}

	string getPass() const {
		return _userPass;
	}


	void showUser() {
		cout << "Name: " << _userName << endl;
		cout << "Login: " << _userLogin << endl;
		cout << "Pass: " << _userPass << endl;
	}
	void readUserFromFile();
	void saveNewUserInFile();

	bool autorization();
	void registration();

    void enter() {
        int choice;
        cout << "BANK NAME\n";
        cout << "Enter 1 - if u HAVE OUR BANK ACCOUNT\n";
        cout << "Enter 2 - if u WANT TO REGISTER NEW BANK ACCOUNT\n";
        cin >> choice;

        switch (choice)
        {
		
            case 1:

                break;
            case 2:
                registration();
                break;
            case 0:
                cout << "Bye!\n";
                break;
            default:
                cout << "You enter wrong choice\n";
                break;
        }
    };
};

=======


	vector<shared_ptr<PaymentSystem>> _userPayments;
	vector<Purchase> _userPurchase;

	vector<int> _passEncrypt;


public:

	User() = default;
	User(string name, string login, string pass) :_userName(name), _userLogin(login), _userPass(pass) {}

	User(string name, string login, string pass, vector<shared_ptr<PaymentSystem>> userPayments) :_userName(name), _userLogin(login), _userPass(pass), _userPayments(userPayments) {}

	void setName(string name) { _userName = name; }
	void setLogin(string login) { _userLogin = login; }
	void setPass(string pass) { _userPass = pass; }
	void setUserPayments(vector<shared_ptr<PaymentSystem>> userPayments) { _userPayments = userPayments; }
	void setUserPurchase(vector<Purchase> userPurch) { _userPurchase = userPurch; }
	void setPassVec(vector<int> passVec) { _passEncrypt = passVec; }

	string getName() const { return _userName; }
	string getLogin() const { return _userLogin; }
	string getPass() const { return _userPass; }
	vector<shared_ptr<PaymentSystem>> getPayments() const { return _userPayments; }
	vector<Purchase> getPurchseVec() const { return _userPurchase; }
	vector<int> getPassVec() { return _passEncrypt; }
	
	string createNewCardNumer();
	void createNewPayment(DebetFileSystem debetFile,CreditFileSystem creditFile);
	void addDebetCard(DebetCard& card);
	void addCreditCard(CreditCard& card);

	void addPurchase(Purchase& pur,PurchaseFileSyst file,Ratings rating);
	Purchase createPurchase();

	void showAllPaymentSystems();
	void showAllPurchase();

	bool authorization(vector<User> userVec);
	void registration();

	void showUser();



	void passwordEncryption();
	void passwordDecryption(User& user);

	void searchUserPayments(vector<CreditCard> creditVec, vector<DebetCard> debetVec);
	void searchUserPurchase(vector<Purchase> purchaseVec);

	void searchCreditCard(vector<CreditCard> vect);
	void searchDebetCard(vector<DebetCard> vect);

	void addMoneyOnSearchedPayment();
	void withDrawMoneyFromSearchedPayment();


};
>>>>>>> 53d9510 (proj)
