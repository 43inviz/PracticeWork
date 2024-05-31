#ifndef PAPKA_PURCHASEFILESYST_H
#define PAPKA_PURCHASEFILESYST_H

#include "../../Purchase/Purchase.h"
#include <vector>
#include <fstream>
#include "../../User/User.h"
#include <string>
#include "../../Reports/Reports.h"
#include "../../Ratings/Ratings.h"
#define PURPATH "../../../Purchase/purchase.txt"
#define RATINGPATH "../../../Ratings/ratings.txt"


class PurchaseFileSyst {
private:
public:
    void saveInFile(vector<Purchase> vector, string login) { // for reports
        try {
            ofstream fout;
            fout.open(PURPATH, ofstream::app);
            if (!fout.is_open()) {
                throw Exceptions(const_cast<char*>("'Purchase.txt' cant be open for save\n"));

            }
            else {
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

    vector<Purchase> loadFromFile(vector<Purchase> vector, string login) {
        
        try {
            ifstream fin;
            fin.open(PURPATH);
            
            if (!fin.is_open()) {
                throw Exceptions(const_cast<char*>("'\"../../Purchase.txt\"' cant be open for read\n"));
            }
            else {
                
                while (!fin.eof()) {

                    string price;
                    string day, month, year;
                    string category, fileLogin;
                    Date date;
                    int dateTemp;

                    fin >> fileLogin;
                    fin >> category;
                    fin >> price;
                    fin >> day;
                    fin >> month;
                    fin >> year;

                    if (price != "") {



                        double newPrice = stod(price);

                        date.setDay(stoi(day));
                        date.setMonth(stoi(month));
                        date.setYear(stoi(year));

                        if (fileLogin == login) {
                            Purchase copyPurchase(fileLogin, newPrice, date, category);
                            vector.push_back(copyPurchase);
                        }
                    }


                }   return vector;
            }
            fin.close();
        }
        catch (Exceptions& ex) {
            cout << ex.what() << endl;
        }
        return vector;
    }


    void saveReport(vector<Purchase> vector, string login) { // for reports (args from )
        try {
            ofstream fout;
            fout.open(RATINGPATH, ofstream::app);
            if (!fout.is_open()) {
                throw Exceptions(const_cast<char*>("'Reports.txt' cant be open for save\n"));

            }
            else {
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




    void loadReport(vector<Purchase> result, string login) {
        try {
            ifstream fin;
            fin.open(RATINGPATH);
            if (!fin.is_open()) {
                throw Exceptions(const_cast<char*>("'\"../../Reports.txt\"' cant be open for read\n"));
            }
            else {
                vector<Purchase> vector;
                while (!fin.eof()) {
                    
                    Date date;
                    string category, fileLogin, price,day,month,year;
                    

                    fin >> fileLogin;
                    fin >> category;
                    fin >> price;
                    fin >> day;
                    fin >> month;
                    fin >> year;
                    
                    if (fileLogin != "") {
                        date.setDay(stoi(day));

                        date.setMonth(stoi(month));

                        date.setYear(stoi(year));

                        if (fileLogin == login) {
                            Purchase copyPurchase(fileLogin, stod(price), date, category);
                            vector.push_back(copyPurchase);
                        }
                    }

                }
                result = vector;
            }
            fin.close();
        }
        catch (Exceptions& ex) {
            cout << ex.what() << endl;
        }
    }
    

    void saveNewPurchaseInFile(Purchase& pur) {
        try {
            ofstream fout;
            fout.open(PURPATH,ofstream::app);
            if (!fout.is_open()) {
                throw Exceptions(const_cast < char*>("'\"../../Purchase.txt\"' cant be open for read\n"));
            }
            else {
                fout << pur.getOwnerLogin() << endl;
                fout << pur.getCategory() << endl;
                fout << pur.getPrice() << endl;
                fout << pur.getDate().getDay() << "\n" << pur.getDate().getMonth() << "\n" << pur.getDate().getYear() << "\n";
            }
        }
        catch (Exceptions& ex) {
            cout << ex.what() << endl;
        }
    }
};



#endif //PAPKA_PURCHASEFILESYST_H