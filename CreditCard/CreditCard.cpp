#include "./CreditCard.h"


double CreditCard::_creditLimit = 10000.0;

void CreditCard::show()
{
	cout << "=====\n";
	cout << "Card number: " << this->getCardNumber() << endl;
	cout << "Current balance: " << this->getCurrentBalance() << endl;
	cout << "Type: " << this->getType() << endl;
	cout << "Credit balance: " << this->getCurrentCreditBalance() << endl;
	cout << "=====\n";
}

void CreditCard::addMoneyOnBalance()
{
	double inputSum;

	cout << "Enter sum for add\n";
	cout << " ";
	cin >> inputSum;
	if (!isAnyLoan()) {
		double creditDifference = _creditLimit - _currentCreditBalance;
		if (inputSum <= creditDifference) {
			addMoneyOnCreditBalance(inputSum);
			cout << "All deposited money was written off as debt\n";
		}
		else {
			this->depositMoneyOnBalance(inputSum - creditDifference);
			addMoneyOnCreditBalance(creditDifference);
			cout << "Add money id done!\n";
		}
	}
	else {
		depositMoneyOnBalance(inputSum);
		cout << "Add money is done!\n";
	}
}

void CreditCard::withDrawFromBalance()
{
	double withdrawSum;
	cout << "Enter with draw sum: ";
	cin >> withdrawSum;

	if (withdrawSum > this->getCurrentBalance()) {
		double withDrawFromCreditCard = withdrawSum - this->getCurrentBalance();
		if (withDrawFromCreditCard <= _currentCreditBalance) {
			this->withMoneyFromBalance(this->getCurrentBalance());
			this->withDrawMoneyFromCredit(withDrawFromCreditCard);
		}
		else {
			throw Exceptions(const_cast<char*>("You don't have that much money in both balance\n"));
		}


	}
	else {
		this->withMoneyFromBalance(withdrawSum);
		cout << "Done\n";
	}
}
