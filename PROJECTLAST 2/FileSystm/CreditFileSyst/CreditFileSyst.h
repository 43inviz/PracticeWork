#pragma once
#include "../../CreditCard/CreditCard.h"
#include "../../Exceptions/Exception.h"
#define CREDITPATH "../../../CreditCard/credit_card.txt"
#include <iostream>
#include <fstream>
using namespace std;

class CreditFileSystem {
	vector<CreditCard> _creditVector;
public:
	CreditFileSystem() {
		try {
			ifstream fin;
			fin.open(CREDITPATH);
			if (!fin.is_open()) {
				throw Exceptions(const_cast<char*>("Credit_card.txt cant open for read\n"));
			}
			else {
				while (!fin.eof())
				{
					
					string ownerName, cardNumber, balance, type, creditBalance;
					fin >> ownerName;
					fin >> cardNumber;
					fin >> balance;
					fin >> type;
					fin >> creditBalance;
					CreditCard copyCard;
					if (balance != "") { //проверка на валидность считываемого баланса
						copyCard.setOwnerName(ownerName);
						copyCard.setCurrentBalance(stod(balance));
						copyCard.setCardNumber(cardNumber);
						copyCard.setType(type);
						copyCard.setCurrentCreditBalance(stod(creditBalance));
						_creditVector.push_back(copyCard);
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

	vector<CreditCard> getCreditVector() { return _creditVector; }

	void saveNewCreditCardInFile(CreditCard& card) {
		try {
			ofstream fout;
			fout.open(CREDITPATH, ofstream::app);
			if (!fout.is_open()) {
				throw Exceptions(const_cast<char*>("Credit_card.txt cant open for save\n"));
			}
			else {

				fout << card.getOwnerName() << endl;
				fout << card.getCardNumber() << endl;
				fout << card.getCurrentBalance() << endl;
				fout << card.getType() << endl;
				fout << card.getCurrentCreditBalance() << endl;
			}
			fout.close();
		}
		catch (Exceptions& ex) {
			cout << ex.what() << endl;
		}
	}
};