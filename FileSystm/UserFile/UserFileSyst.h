#pragma once
#include "../../User/User.h"
#include "../../Exceptions/Exception.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#define FILEPATH "../../../User/user.txt"
using namespace std;

class UserFileSyst {
	
	
	vector<User> _usersFromFile;
public:
	UserFileSyst() {
		try {
			ifstream fin;
			fin.open(FILEPATH);
			if (!fin.is_open()) {
				throw Exceptions(const_cast<char*>("'User.txt' cant be open for read\n"));
			}
			else {
				while (!fin.eof()) {
					string name, login, pass;
					fin >> name;
					fin >> login;
					fin >> pass;

					User copyUser(name, login, pass);
					_usersFromFile.push_back(copyUser);

				}

			}
			fin.close();
		}
		catch (Exceptions& ex) {
			cout << ex.what() << endl;
		}
	}


	vector<User> getUserVector() { return _usersFromFile; }
	void setUserVector(vector<User> userVec) { _usersFromFile = userVec; }

	void saveNewUserInFile(User& user) {
		
		try {
			ofstream fout;
			fout.open(FILEPATH, ofstream::app);
			if (!fout.is_open()) {
				throw Exceptions(const_cast<char*>("'User.txt' cant be open for save\n"));

			}
			else {
				fout << user.getName() << "\n";
				fout <<	user.getLogin() << "\n";
				fout << user.getPass() << "\n";
				
			}
			fout.close();
		}
		catch (Exceptions& ex) {
			cout << ex.what() << endl;
		}
	}




};