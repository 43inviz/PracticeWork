#include "DebetCard.h"
#define DEBETPATH "../../../DebetCard/debet_card.txt"

void DebetCard::show()
{
	cout << "======\n";
	cout << "Card number: " << this->getCardNumber() << endl;
	cout << "Current balance: " << this->getCurrentBalance() << endl;
	cout << "Type: " << this->getType() << endl;
	cout << "======\n";
}

void DebetCard::addMoneyOnBalance()
{
	double inputSum;
	cout << "Enter the deposit amount: ";
	cin >> inputSum;
	this->depositMoneyOnBalance(inputSum);
	cout << "Done\n";
}

void DebetCard::withDrawFromBalance()
{
	double withdrawSum;
	cout << "Enter withdraw sum: ";
	cin >> withdrawSum;
	if (withdrawSum <= this->getCurrentBalance()) {
		this->withMoneyFromBalance(withdrawSum);
		cout << "Done\n";
	}
	else {
		cout << "You don't have that much money\n";
	}
}

//void DebetCard::savePaymentOnFile()
//{
//
//	try {
//		ofstream fout;
//		fout.open(DEBETPATH);
//		if (!fout.is_open()) {
//			throw Exceptions(const_cast<char*>("Debet_card.txt cant be open for save\n"));
//		}
//		else {
//
//			fout << this->getCardNumber() << endl;
//			fout << this->getCurrentBalance() << endl;
//			fout << this->getType() << endl;
//		}
//	}
//	catch (Exceptions& ex) {
//		cout << ex.what() << endl;
//	}
//}

//void DebetCard::readPaymentsFromFile(vector<PaymentSystem> vec)
//{
//	try {
//		ifstream fin;
//		fin.open(DEBETPATH);
//		if (!fin.is_open()) {
//			throw Exceptions(const_cast <char*>("Debet_card.txt cant be open for read\n"));
//		}
//		else {
//			DebetCard copyCard;
//			string cardNumb, balance, type;
//			fin >> cardNumb;
//			fin >> balance;
//			fin >> type;
//			copyCard.setCardNumber(cardNumb);
//			copyCard.setCurrentBalance(stod(balance));
//			copyCard.setType(type);
//			vec.push_back(copyCard);
//		}
//		fin.close();
//	}
//	catch (Exceptions& ex) {
//		cout << ex.what() << endl;
//	}
//}
