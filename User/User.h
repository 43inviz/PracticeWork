#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <exception>
using namespace std;
#define FILENAME "users.txt"


class User {
	string _userName;
	string _userLogin;
	string _userPass;

public:

	User() {};
	User(string name, string login, string pass) :_userName(name), _userLogin(login), _userPass(pass) {}

	//bool operator==(const User& right);

	/*void enterMenu();*/

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

	void readUserFromFile() {
            try {
                ifstream fin;
                fin.open(FILENAME);
                if (!fin.is_open()) {
                    throw "User.txt cant open for read\n";
                }

                string userName, userLogin, userPass;
                fin >> userName;
                fin >> userLogin;
                fin >> userPass;

                this->setName(userName);
                this->setLogin(userLogin);
                this->setPass(userPass);
            }
            catch (exception& ex) {
                cout << ex.what() << endl;
            }

        };
#include <exception>

	void saveNewUserInFile() {
        try {

            ofstream fout;
            fout.open(FILENAME);
            if (!fout.is_open()) {
                throw "User.txt cant opend for save\n";
            }
            fout << _userName << "\n";
            fout << _userLogin << "\n";
            fout << _userPass << "\n";
            fout.close();
        }
        catch (exception& ex) {
            cout << ex.what() << endl;
        }
    };

	bool autorization() {
        string userLogin;
        string userPass;

        User compareUser;

        cout << "Enter your login: ";
        getline(cin, userLogin);
        cout << "Enter your password: ";
        getline(cin, userPass);

        if (this->_userLogin == userLogin || this->_userPass == userPass) {
            return true;
        }
        return false;
    };
	//bool compareUserForAutorization(User& user);
	void registration() {
        string newName, newLogin, newPass;
        cout << "Enter your name: ";
        getline(cin, newName);
        cout << "Enter your Phone or E-Mail(will be used as login): ";
        getline(cin, newLogin);
        cout << "Create password: ";
        getline(cin, newPass);

        this->setName(newName);
        this->setLogin(newLogin);
        this->setLogin(newPass);

        this->saveNewUserInFile();

    };

	/*bool isExistingUser();*/

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

