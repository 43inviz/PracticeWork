#include "Reports.h"

void Reports::reportSetup() {
    Date datenew; // -- clear data
    date = datenew; // -- clear data
    _category = ""; // -- clear data
    isWeek = false; // -- clear data

    cout << "��������� ���� �� ���������� ��� �� ��������� (������� - 0, ������� - 1): ";
    cin >> _type;
    cout << endl;
    if (_type == 1) {
        short choose;
        cout << "�������� �� ���� (0), ����� (1) ��� ����� (2): ";
        cin >> choose;
        cout << endl;
        if (choose == 0 || choose == 2) {
            isWeek = false;
            cout << "������ ���� (���� �� ������� ����� ������ ���� � �������� ����): ";
            date.inputDate();
            cout << endl;
        }
        else if (choose == 1) {
            isWeek = true;
            cout << "������ ������ ���� ���� ���� �� ��� �� ������ ��������: ";
            date.inputDate();
            cout << endl;
        }
    }
    else if (_type == 0) {
        cout << "������ �������� �� ���� ������ �������� ���: ";
        cin >> _category;
        cout << endl;
        short choose;
        cout << "�������� �� ���� (0), ����� (1) ��� ����� (2): ";
        cin >> choose;
        cout << endl;
        if (choose == 0 || choose == 2) {
            isWeek = false;
            cout << "������ ���� (���� �� ������� ����� ������ ���� � �������� ����): ";
            date.inputDate();
            cout << endl;
        }
        else if (choose == 1) {
            isWeek = true;
            cout << "������ ������ ���� ���� ���� �� ��� �� ������ ��������: ";
            date.inputDate();
            cout << endl;
        }
    };
};

void Reports::showReport(vector<Purchase> arr) {
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
            for (int i = 0; i < arr.size(); ++i) { // �������? ��! � ���� ������ �� �� ������� ����� ������� ����� ������� ��� �����
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
            for (int i = 0; i < arr.size(); ++i) { // �������? ��! � ���� ������ �� �� ������� ����� ������� ����� ������� ��� �����
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
};