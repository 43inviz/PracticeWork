#ifndef PAPKA_REPORTS_H
#define PAPKA_REPORTS_H

#include <iostream>
#include "Purchase.h"
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
        Date datenew; // -- clear data
        date = datenew; // -- clear data
        _category = ""; // -- clear data
        isWeek = false; // -- clear data

        cout << "Виведення звітів за категоріями або за витратами (категорії - 0, витрати - 1): ";
        cin >> _type;
        cout << endl;
        if (_type == 1) {
            short choose;
            cout << "Виводити за день (0), неділю (1) або місяць (2): ";
            cin >> choose;
            cout << endl;
            if (choose == 0 || choose == 2) {
                isWeek = false;
                cout << "Введіть дату (якщо Ви вибрали місять вводіть дату з нульовим днем): ";
                date.inputDate();
                cout << endl;
            }
            else if (choose == 1) {
                isWeek = true;
                cout << "Введіть перший день неділі звіти за яку Ви хочете побачити: ";
                date.inputDate();
                cout << endl;
            }
        }
        else if (_type == 0) {
            cout << "Введіть категорію за якою хочете побачити звіт: ";
            cin >> _category;
            cout << endl;
            short choose;
            cout << "Виводити за день (0), неділю (1) або місяць (2): ";
            cin >> choose;
            cout << endl;
            if (choose == 0 || choose == 2) {
                isWeek = false;
                cout << "Введіть дату (якщо Ви вибрали місять вводіть дату з нульовим днем): ";
                date.inputDate();
                cout << endl;
            }
            else if (choose == 1) {
                isWeek = true;
                cout << "Введіть перший день неділі звіти за яку Ви хочете побачити: ";
                date.inputDate();
                cout << endl;
            }
        };
    }

    //    double price;
    //    Date date;
    //    string category;

    void showReport(vector<Purchase> arr) {
        if (_type == 1) { // without category
            if (!date.getDay()) { // month reports
                for (int i = 0; i < arr.size(); ++i) {
                    if (arr[i].getDate().getYear() == date.getYear() && arr[i].getDate().getMonth() == date.getMonth()) {
                        cout << arr[i].getDate().showDate(); // out date;
                        cout << arr[i].getPrice(); // out price
                        cout << arr[i].getCategory(); // out category
                        cout << endl;
                    }
                }
            }
            else if (isWeek) { // week reports
                for (int i = 0; i < arr.size(); ++i) { // костыль? да! У меня просто не на столько много времени чтобы сделать как нужно
                    if (arr[i].getDate().getYear() == date.getYear() && arr[i].getDate().getMonth() == date.getMonth() && arr[i].getDate().getDay() == date.getDay()
                        && arr[i].getDate().getDay() == date.getDay() + 1 && arr[i].getDate().getDay() == date.getDay() + 2 && arr[i].getDate().getDay() == date.getDay() + 3
                        && arr[i].getDate().getDay() == date.getDay() + 4 && arr[i].getDate().getDay() == date.getDay() + 5 && arr[i].getDate().getDay() == date.getDay() + 6) {
                        cout << arr[i].getDate().showDate(); // out date;
                        cout << arr[i].getPrice(); // out price
                        cout << arr[i].getCategory(); // out category
                        cout << endl;
                    }
                }
            }
            else { // day reports
                for (int i = 0; i < arr.size(); ++i) {
                    if (arr[i].getDate().getYear() == date.getYear() && arr[i].getDate().getMonth() == date.getMonth() && arr[i].getDate().getDay() == date.getDay()) {
                        cout << arr[i].getDate().showDate(); // out date;
                        cout << arr[i].getPrice(); // out price
                        cout << arr[i].getCategory(); // out category
                        cout << endl;
                    }
                }
            }
        }
        else if (_type == 0) { // with category
            if (!date.getDay()) {
                for (int i = 0; i < arr.size(); ++i) {
                    if (arr[i].getDate().getYear() == date.getYear() && arr[i].getDate().getMonth() == date.getMonth() && arr[i].getCategory() == _category) {
                        cout << arr[i].getDate().showDate(); // out date;
                        cout << arr[i].getPrice(); // out price
                        cout << arr[i].getCategory(); // out category
                        cout << endl;
                    }
                }
            }
            else if (isWeek) {
                for (int i = 0; i < arr.size(); ++i) { // костыль? да! У меня просто не на столько много времени чтобы сделать как нужно
                    if (arr[i].getDate().getYear() == date.getYear() && arr[i].getDate().getMonth() == date.getMonth() && arr[i].getDate().getDay() == date.getDay()
                        && arr[i].getDate().getDay() == date.getDay() + 1 && arr[i].getDate().getDay() == date.getDay() + 2 && arr[i].getDate().getDay() == date.getDay() + 3
                        && arr[i].getDate().getDay() == date.getDay() + 4 && arr[i].getDate().getDay() == date.getDay() + 5 && arr[i].getDate().getDay() == date.getDay() + 6 && arr[i].getCategory() == _category) {
                        cout << arr[i].getDate().showDate(); // out date;
                        cout << arr[i].getPrice(); // out price
                        cout << arr[i].getCategory(); // out category
                        cout << endl;
                    }
                }
            }
            else {
                for (int i = 0; i < arr.size(); ++i) {
                    if (arr[i].getDate().getYear() == date.getYear() && arr[i].getDate().getMonth() == date.getMonth() && arr[i].getDate().getDay() == date.getDay() && arr[i].getCategory() == _category) {
                        cout << arr[i].getDate().showDate(); // out date;
                        cout << arr[i].getPrice(); // out price
                        cout << arr[i].getCategory(); // out category
                        cout << endl;
                    }
                }
            }
        }
    }
};


#endif //PAPKA_REPORTS_H
