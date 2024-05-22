#pragma once
#include <iostream>
#include <string>
#include <fstream>

#include "../Exception.h"
using namespace std;
#define FILENAME "../users.txt"

class User {
	string _userName;
	string _userLogin;
	string _userPass;
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

	void show() {
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

