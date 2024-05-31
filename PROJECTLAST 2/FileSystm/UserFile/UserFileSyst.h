#pragma once
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
					string name, login, pass, encr;

					fin >> encr;
					fin >> name;
					fin >> login;
					fin >> pass;



					vector<int> passVec;
					for (size_t i = 0; i < encr.size(); i++) {
						passVec.push_back(encr[i] - '0');
					}
					
		

					User copyUser(name, login, pass);
					copyUser.setPassVec(passVec);
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
				vector<int> passVec = user.getPassVec();
				for (auto i = passVec.begin(); i != passVec.end(); i++) {
					fout << *i;
				}
				fout << "\n";
				fout <<  user.getName() << "\n";
				fout <<  user.getLogin() << "\n";
				fout <<  user.getPass() << "\n";
				
			}
			fout.close();
		}
		catch (Exceptions& ex) {
			cout << ex.what() << endl;
		}
	}




};