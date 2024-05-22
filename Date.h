#ifndef PAPKA_DATE_H
#define PAPKA_DATE_H

#include <string>
#include <iostream>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;
public:
    Date() = default;

    string showDate() {
        string formattedDate;

        if (this->day < 10) {
            formattedDate += "0";
        }
        formattedDate += to_string(this->day) + ".";

        if (this->month < 10) {
            formattedDate += "0";
        }
        formattedDate += to_string(this->month) + ".";

        formattedDate += to_string(this->year);

        return formattedDate;
    }
    void inputDate() {
        cout << "Введіть дату" << " (день місяць рік): ";
        cin >> this->day >> this->month >> this->year;

        if (this->month < 1 || this->month > 12) {
            cout << "Помилка: Невалідний місяць" << endl;
            return;
        }

        if (this->day < 0 || this->day > 31) {
            cout << "Помилка: Невалідний день" << endl;
            return;
        }
    }

    int getDay() {
        return day;
    }
    int getMonth() {
        return month;
    }
    int getYear() {
        return year;
    }
};


#endif //PAPKA_DATE_H
