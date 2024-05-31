#pragma once
#include "../../DebetCard/DebetCard.h"
#include "../../Exceptions/Exception.h"
#include <iostream>
#include <fstream>
#define DEBETPATH "../../../DebetCard/debet_card.txt"
using namespace std;

class DebetFileSystem {
	vector<DebetCard> _debetVector;
public:
	DebetFileSystem() {
		try {
			ifstream fin;
			fin.open(DEBETPATH);
			if (!fin.is_open()) {
				throw Exceptions(const_cast <char*>("Debet_card.txt cant be open for read\n"));
			}
			else {
				
				while (!fin.eof() ) {
					DebetCard copyCard;
					string ownerName, cardNumb, balance, type;
					fin >> ownerName;
					fin >> cardNumb;
					fin >> balance;
					fin >> type;
				
					if(balance != "") {
						DebetCard copyCard(ownerName, cardNumb, type, stod(balance));
						_debetVector.push_back(copyCard);
					}
					else {
						break;
					}
					
				}
			

			}
			fin.close();
		}
		catch (Exceptions& ex) {
			cout << ex.what() << endl;
		}
	}

	vector<DebetCard> getDebetVector() { return _debetVector; }

	void saveNewDebetCardIFile(DebetCard& newCard) {
		try {
			ofstream fout;
			fout.open(DEBETPATH, ofstream::app);
			if (!fout.is_open()) {
				throw Exceptions(const_cast<char*>("Debet_card.txt cant be open for save\n"));
			}
			else {
				fout << newCard.getOwnerName() << endl;
				fout << newCard.getCardNumber() << endl;
				fout << newCard.getCurrentBalance() << endl;
				fout << newCard.getType() << endl;

			}
			fout.close();
		}
		catch (Exceptions& ex) {
			cout << ex.what() << endl;
		}
	}
};