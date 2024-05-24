#ifndef PAPKA_RATINGS_H
#define PAPKA_RATINGS_H

#include <vector>
#include "../Purchase.h"
using namespace std;

class Ratings {
private:
    vector<Purchase> result;
public:
    void configureRatings(vector<Purchase> arr, Date date, string category, bool isWeek);

    void showRating(vector<Purchase> arr, Date date, string category = "", bool isWeek = false); // arr - общий вектор покупок, date - запрашивать у пользователя,
};                                                                                                  // category - если не передана - вывод по прайсу если передана - по категории,
                                                                                                    // isWeek - запросить у польззователя так же как запрагивали в Purchase


#endif //PAPKA_RATINGS_H
