#include "Purchase.h"

Purchase* Purchase::addPurchase(int type, double creditBalance, double balance) {
    if (isCardCredit(type)) {
        if (isCreditBalance(creditBalance)) {
            creditBalance -= this->price;
            return this;
        }
        else throw Exceptions(const_cast<char*>("��������� ��� ���������!\n"));
    }
    else {
        if (isBalanceValid(balance)) {
            balance -= this->price;
            return this;
        }
        else throw Exceptions(const_cast<char*>("����������� �����!"));
    }
};

bool Purchase::isBalanceValid(double balance) {
    if (balance < price) {
        return false;
    }
    else return true;
};

bool Purchase::isCardCredit(int type) {
    if (type) {
        return true;
    }
    else return false;
};

bool Purchase::isCreditBalance(double creditBalance) {
    if (creditBalance < this->price) {
        return false;
    }
    else return true;
};