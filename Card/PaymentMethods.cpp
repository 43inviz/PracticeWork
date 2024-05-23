#include "PaymentMethods.h"

void Payment::setPurInVec(Purchase pur)
{
	_purVec.push_back(pur);
}

void Payment::showCardNumber() const
{
	for (auto i = _cardNumber.begin(); i != _cardNumber.end(); i++) {
		cout << *i;
	}
	cout << "\n";
}

void Payment::showPur()
{
	for (auto i = _purVec.begin(); i != _purVec.end(); i++) {
		cout << i->getDate().showDate(); // out date;
		cout << i->getPrice(); // out price
		cout << i->getCategory(); // out category
		cout << endl;
	}
}
