#ifndef PAPKA_PURCHASEFILESYST_H
#define PAPKA_PURCHASEFILESYST_H

#include "../../Purchase/Purchase.h"
#include <vector>
#include <fstream>
#include "../../User/User.h"
#include <string>

class PurchaseFileSyst {
private:
public:
    void saveInFile(vector<Purchase> vector, string login) {
        try {
            ofstream fout;
            fout.open("../../Purchse.txt", ofstream::app);
            if (!fout.is_open()) {
                throw Exceptions(const_cast<char*>("'Purchse.txt' cant be open for save\n"));

            } else {
                for (Purchase el : vector) {
                    fout << login << "\n";
                    fout << el.getCategory() << "\n";
                    fout << el.getPrice() << "\n";
                    fout << el.getDate().getDay() << "\n" << el.getDate().getMonth() << "\n" << el.getDate().getYear() << "\n";
                }
            }
            fout.close();
        }
        catch (Exceptions& ex) {
            cout << ex.what() << endl;
        }
    }

    void loadFromFile(vector<Purchase> vector, string login) {
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
                    string category, fileLogin;
                    int dateTemp;

                    fin >> fileLogin;
                    fin >> category;
                    fin >> price;
                    fin >> dateTemp;
                    date.setDay(dateTemp);
                    fin >> dateTemp;
                    date.setMonth(dateTemp);
                    fin >> dateTemp;
                    date.setYear(dateTemp);

                    if (fileLogin != login){
                        Purchase copyPurchase(price, date, category);
                        vector.push_back(copyPurchase);
                    }
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
