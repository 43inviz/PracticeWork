#ifndef PAPKA_PURCHASE_H
#define PAPKA_PURCHASE_H

#include <string>
#include "Date.h"
#include "Exception.h"
using namespace std;

class Purchase {
private:
    double price;
    Date date;
    string category;
public:
    Purchase(double price, Date date, string category) : price(price), date(date), category(category) {}
    bool isCardCredit(char type) {
        if(type) {
            return true;
        } else return false;
    };
    bool isCreditBalance(double creditBalance) {
        if (creditBalance < this->price) {
            return false;
        } else return true;
    };
    bool isBalanceValid(double balance) {
        if(balance < price) {
            return false;
        } else return true;
    };

    Purchase* addPurchase() {
        if (isCardCredit(type)) {
            if (isCreditBalance(creditBalance)) {
                creditBalance -= this->price;              //отнять от кредитного баланса
                return this;
            } else throw Exceptions("Кредитний ліміт вичерпано!\n");
        } else {
            if(isBalanceValid(balance)) {
                balance -= this->price;                    // отнять от баланса
                return this;
            } else throw Exceptions("Недостатньо коштів!");
        }
    };
};


#endif //PAPKA_PURCHASE_H
