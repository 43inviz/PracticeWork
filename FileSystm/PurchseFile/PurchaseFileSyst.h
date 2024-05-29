#ifndef PAPKA_PURCHASEFILESYST_H
#define PAPKA_PURCHASEFILESYST_H

#include "../../Purchase/Purchase.h"
#include <vector>
#include <fstream>

class PurchaseFileSyst {
private:
public:
    void saveInFile(vector<Purchase> vector) {
        try {
            ofstream fout;
            fout.open("../../Purchse.txt", ofstream::app);
            if (!fout.is_open()) {
                throw Exceptions(const_cast<char*>("'Purchse.txt' cant be open for save\n"));

            } else {
                for (Purchase el : vector) {
                    fout << el.getCategory() << "\n";
                    fout << el.getPrice() << "\n";
                    fout << el.getDate().getDay() << " " << el.getDate().getMonth() << " " << el.getDate().getYear() << "\n";
                }
            }
            fout.close();
        }
        catch (Exceptions& ex) {
            cout << ex.what() << endl;
        }
    }

    void loadFromFile(vector<Purchase> vector) {
        try {
            ifstream fin;
            fin.open("../../Purchse.txt");
            if (!fin.is_open()) {
                throw Exceptions(const_cast<char*>("'\"../../Purchse.txt\"' cant be open for read\n"));
            }
            else {
                while (!fin.eof()) {
                    double price;
                    Date date;
                    string category;

                    fin >> price;
                    date.inputDate();
                    fin >> category;

                    Purchase copyPurchase(price, date, category);
                    vector.push_back(copyPurchase);
                }
            }
            fin.close();
        }
        catch (Exceptions& ex) {
            cout << ex.what() << endl;
        }
    }
};


#endif //PAPKA_PURCHASEFILESYST_H
