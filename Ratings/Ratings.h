#ifndef PAPKA_RATINGS_H
#define PAPKA_RATINGS_H

#include <vector>
#include "../Purchase.h"
using namespace std;

class Ratings {
private:
    vector<Purchase> result;
public:
    void configureRatings(vector<Purchase> arr, Date date, string category, bool isWeek);// type = 0 - spend; 1 - category

    void showRating(vector<Purchase> arr, Date date, string category, bool isWeek = false);// type = 0 - spend; 1 - category
};


#endif //PAPKA_RATINGS_H
