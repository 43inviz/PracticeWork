#include "CreditCard.h"

double CreditCard::_creditLimit = 10000.0;

void CreditCard::show()
{
	Card::show();
	cout << "Current credit balance: " << _currentCreditBalance << endl;
	cout << "Credit limit: " << _creditLimit << endl;
}

void CreditCard::addMoney()
{

	cout << "The credit debt will be charged from this payment\n";
	cout << "Enter sum for add: ";
	double sum;
	cin >> sum;
	if (!isAnyDebt()) {
		double diff = _creditLimit - _currentCreditBalance;
		addMoneyOnCreditBalance(diff);
		sum -= diff;
	}
	addMoneyOnBalance(sum);
	cout << "Add monaye done\n";
	
}

void CreditCard::takeMoney()
{
	cout << "Enter sum for with draw: " << endl;
	double sum;
	cin >> sum;
	if (!isValidTake(sum)) {

		double diff = sum - getCurrentBalance();
		takeMoneyFromCreditBalance(sum);
	}
	
	withDrawMoneyFromBalance(sum);
	
	cout << "Done\n";
}

bool CreditCard::isValidTake(double sum)
{
	return sum < this->getCurrentBalance();
}
