#ifndef PAPKA_REPORTS_H
#define PAPKA_REPORTS_H

#include <iostream>
#include "../Purchase/Purchase.h"
#include <vector>
using namespace std;

class Reports {
private:
    bool _type;
    string _category;
    Date date;
    bool isWeek;
public:
    Reports() = default;

    void reportSetup() {
        //Date datenew; // -- clear data
        //date = datenew; // -- clear data
        //_category = ""; // -- clear data
        //isWeek = false; // -- clear data

        cout << "Output of reports by categories or by costs (categories - 0, costs - 1): ";
        cin >> _type;
        cout << endl;
        if (_type == 1) {
            short choose;
            cout << "Output per day (0), week (1) or month (2): ";
            cin >> choose;
            cout << endl;
            if (choose == 0  || choose == 2) {
                isWeek = false;
                cout << "Enter the date (if you selected a month, enter a date with a zero day): ";
                date.inputDate();
                cout << endl;
            }
            else if (choose == 1) {
                isWeek = true;
                cout << "Enter the first day of week reports for which you want to see: ";
                date.inputDate();
                cout << endl;
            }
        }
        else if (_type == 0) {
            cout << "Enter the category by which you want to see the report: ";
            cin >> _category;
            cout << endl;
            short choose;
            cout << "Output per day (0), week (1) or month (2): ";
            cin >> choose;
            cout << endl;
            if (choose == 0 ||  choose == 2) {
                isWeek = false;
                cout << "Enter the date (if you selected a month, enter a date with a zero day): ";
                date.inputDate();
                cout << endl;
            }
            else if (choose == 1) {
                isWeek = true;
                cout << "Enter the first day of week reports for which you want to see: ";
                date.inputDate();
                cout << endl;
            }
        }

    };

    void showReport(vector<Purchase> arr) {
        if (_type == 1) { // without category
            if (!date.getDay()) { // month reports
                for (auto& el : arr) {
                    if (el.getDate().getYear() == date.getYear() && el.getDate().getMonth() == date.getMonth()) {
                        
                        cout << "Date: ";
                        el.getDate().showDate(); // out date;
                        cout << "\nPrice: " << el.getPrice(); // out price
                        cout << "\nCategory: " << el.getCategory(); // out category
                        cout << endl;
                    }
                }
            }
            else if (isWeek) { // week reports
                for (auto& el : arr) { // костыль? да! У меня просто не на столько много времени чтобы сделать как нужно
                    if (el.getDate().getYear() == date.getYear() && el.getDate().getMonth() == date.getMonth() && el.getDate().getDay() == date.getDay()
                        && el.getDate().getDay() == date.getDay() + 1 && el.getDate().getDay() == date.getDay() + 2 && el.getDate().getDay() == date.getDay() + 3
                        && el.getDate().getDay() == date.getDay() + 4 && el.getDate().getDay() == date.getDay() + 5 && el.getDate().getDay() == date.getDay() + 6) {
                        cout << "Date: ";
                        el.getDate().showDate(); // out date;
                        cout <<"\nPrice: " << el.getPrice(); // out price
                        cout << "\nCategory: " << el.getCategory(); // out category
                        cout << endl;
                    }
                }
            }
            else { // day reports
                for (auto& el : arr) {
                    if (el.getDate().getYear() == date.getYear() && el.getDate().getMonth() == date.getMonth() && el.getDate().getDay() == date.getDay()) {
                        cout << "Date: ";
                        el.getDate().showDate(); // out date;
                        cout <<"\nPrice: " << el.getPrice(); // out price
                        cout << "\nCategory: " << el.getCategory(); // out category
                        cout << endl;
                    }
                }
            }
        }
        else if (_type == 0) { // with category
            if (!date.getDay()) {
                for (Purchase el : arr) {
                    if (el.getDate().getYear() == date.getYear() && el.getDate().getMonth() == date.getMonth() && el.getCategory() == _category) {
                        cout << "\nDate: ";
                        el.getDate().showDate(); // out date
                        cout <<"\nPrice: " << el.getPrice(); // out price
                        cout << "\nCategory: " << el.getCategory(); // out category
                        cout << endl;
                    }
                }
            }
            else if (isWeek) {
                for (Purchase el : arr) { // костыль? да! У меня просто не на столько много времени чтобы сделать как нужно
                    if (el.getDate().getYear() == date.getYear() && el.getDate().getMonth() == date.getMonth() && el.getDate().getDay() == date.getDay()
                        && el.getDate().getDay() == date.getDay() + 1 && el.getDate().getDay() == date.getDay() + 2 && el.getDate().getDay() == date.getDay() + 3
                        && el.getDate().getDay() == date.getDay() + 4 && el.getDate().getDay() == date.getDay() + 5 && el.getDate().getDay() == date.getDay() + 6 && el.getCategory() == _category) {
                        cout << "\nDate: ";
                        el.getDate().showDate(); // out date
                        cout << "\nPrice: " << el.getPrice(); // out price
                        cout << "\nCategory: " << el.getCategory(); // out category
                        cout << endl;
                    }
                }
            }
            else {
                for (Purchase el : arr) {
                    if (el.getDate().getYear() == date.getYear() && el.getDate().getMonth() == date.getMonth() && el.getDate().getDay() == date.getDay() && el.getCategory() == _category) {
                        cout << "\nDate: ";
                        el.getDate().showDate(); // out date
                        cout << "\nPrice: " << el.getPrice(); // out price
                        cout << "\nCategory: " << el.getCategory(); // out category
                        cout << endl;
                    }
                }
            }
        }
    }
    
};


#endif //PAPKA_REPORTS_H
