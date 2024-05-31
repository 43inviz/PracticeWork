#ifndef PAPKA_RATINGS_H
#define PAPKA_RATINGS_H

#include <vector>
#include "../Purchase/Purchase.h"
#include <algorithm>
using namespace std;

class Ratings {
private:
    //vector<Purchase> result;
   /* vector<Purchase> vecByCategory;*/
    vector<Purchase> vecByPrice;
public:
    Ratings() = default;
    Ratings(vector<Purchase> vector) : vecByPrice(vector){}
    //void configureRatings(vector<Purchase> arr, Date date, string category, bool isWeek);
    void configureRatings(Date date, string category, bool isWeek);

    //void showRating(vector<Purchase> arr, Date date, string category = "", bool isWeek = false);    // arr - общий вектор покупок, date - запрашивать у пользователя,
    void showRating(Date date, string category = "", bool isWeek = false);    // arr - общий вектор покупок, date - запрашивать у пользователя,
                                                                                                    // category - если не передана - вывод по прайсу если передана - по категории,
                                                                                                    // isWeek - запросить у польззователя так же как запрагивали в Purchase
    void ratingSetup(vector<Purchase> arr);

    //void setPurVect(vector<Purchase> vec);

 /*   void addNewPurchaseByPrice(Purchase& pur);
    void addNewPurchaseByCategory(Purchase& pur);*/

    //void addNewPurchase(Purchase& pur);

    void showTopThr(vector<Purchase> vec);
};

#endif //PAPKA_RATINGS_H
