#ifndef PAPKA_PURCHASE_H
#define PAPKA_PURCHASE_H

#include <string>
#include "../Date/Date.h"
#include "../Exceptions/Exception.h"
using namespace std;

class Purchase {
private:
    string ownerLogin;
    double price;
    Date date;
    string category;
public:
    Purchase(string ownLogin,double price, Date date, string category) : ownerLogin(ownLogin), price(price), date(date), category(category) {}

    double getPrice() {return price;}
    Date getDate() {return date;}
    string getCategory() {return category;}

    bool isCardCredit(int type);
    bool isCreditBalance(double creditBalance);
    bool isBalanceValid(double balance);

    Purchase* addPurchase(int type, double creditBalance, double balance);

    void showPurchase() {
        
        cout << "\nprice: " << price << endl;
        cout << "Date: ";
        date.showDate();
        cout << "\n";
        cout << "Caregory: " << category << endl;
    }

    string getOwnerLogin() { return ownerLogin;  }
};


#endif //PAPKA_PURCHASE_H
