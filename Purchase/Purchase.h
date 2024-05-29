#ifndef PAPKA_PURCHASE_H
#define PAPKA_PURCHASE_H

#include <string>
#include "../Date/Date.h"
#include "../Exceptions/Exception.h"
using namespace std;

class Purchase {
private:
    double price;
    Date date;
    string category;
public:
    Purchase(double price, Date date, string category) : price(price), date(date), category(category) {}

    double getPrice() {return price;}
    Date getDate() {return date;}
    string getCategory() {return category;}

    bool isCardCredit(int type);
    bool isCreditBalance(double creditBalance);
    bool isBalanceValid(double balance);

    Purchase* addPurchase(int type, double creditBalance, double balance);
};


#endif //PAPKA_PURCHASE_H
