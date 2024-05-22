#ifndef PAPKA_REPORTS_H
#define PAPKA_REPORTS_H

#include <iostream>
#include "Purchase.h"
using namespace std;

class Reports {
private:
    bool _type;
    string _category;
    Date date;
public:
    Reports() = default;

    void setup() {
        cout << "Виведення звітів за категоріями або за витратами (категорії - 0, витрати - 1): ";
        cin >> _type;
        cout << endl;
        if (_type == 1) {
            short choose;
            cout << "Виводити за день (0), неділю (1) або місяць (2): ";
            cin >> choose;
            cout << endl;
            if (choose == 0 || choose == 2) {
                cout << "Введіть дату (якщо Ви вибрали місять вводіть дату з нульовим днем): ";
                date.inputDate();
                cout << endl;
            } else if (choose == 1) {
                cout << "Введіть перший день неділі звіти за яку Ви хочете побачити: ";
                date.inputDate();
                cout << endl;
            }
        } else if (_type == 0) {
            cout << "Введіть категорію за якою хочете побачити звіт: ";
            cin >> _category;
            cout << endl;
            short choose;
            cout << "Виводити за день (0), неділю (1) або місяць (2): ";
            cin >> choose;
            cout << endl;
            if (choose == 0 || choose == 2) {
                cout << "Введіть дату (якщо Ви вибрали місять вводіть дату з нульовим днем): ";
                date.inputDate();
                cout << endl;
            } else if (choose == 1) {
                cout << "Введіть перший день неділі звіти за яку Ви хочете побачити: ";
                date.inputDate();
                cout << endl;
            }
        };
    }

    void showReport(Purchase* arr) {

    }

};


#endif //PAPKA_REPORTS_H
