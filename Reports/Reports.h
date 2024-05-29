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

    void reportSetup();

    void showReport(vector<Purchase> arr);
};


#endif //PAPKA_REPORTS_H
