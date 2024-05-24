#include "Ratings.h"
#include "../Purchase.h"

void Ratings::configureRatings(vector<Purchase> arr, Date date, string category, bool isWeek) {// type = 0 - spend; 1 - category
    if (arr.empty()) {
        return;
    }

    if (isWeek && category == "") {
        for(Purchase el : arr) {
            if(el.getDate().getYear() == date.getYear() && el.getDate().getMonth() == date.getMonth() && el.getDate().getDay() == date.getDay()&& el.getDate().getDay() == date.getDay()+1 && el.getDate().getDay() == date.getDay()+2 && el.getDate().getDay() == date.getDay()+3&& el.getDate().getDay() == date.getDay()+4 && el.getDate().getDay() == date.getDay()+5 && el.getDate().getDay() == date.getDay()+6) {

                auto it = result.begin();
                if (it->getPrice() < el.getPrice()) {
                    *(it) = el;
                } else if ((it + 1) != result.end() && (it + 1)->getPrice() < el.getPrice()) {
                    *(it + 1) = el;
                } else if ((it + 2) != result.end() && (it + 2)->getPrice() > el.getPrice()) {
                    *(it+2) = el;
                } else return;
            }
        }
    }

    if (!isWeek && category == "") {
        for(Purchase el : arr) {
            if(el.getDate().getYear() == date.getYear() && el.getDate().getMonth() == date.getMonth()) {

                auto it = result.begin();
                if (it->getPrice() < el.getPrice()) {
                    *(it) = el;
                } else if ((it + 1) != result.end() && (it + 1)->getPrice() < el.getPrice()) {
                    *(it + 1) = el;
                } else if ((it + 2) != result.end() && (it + 2)->getPrice() > el.getPrice()) {
                    *(it+2) = el;
                } else return;
            }
        }
    }

    if (isWeek && category != "") {
        for(Purchase el : arr) {
            if(el.getDate().getYear() == date.getYear() && el.getDate().getMonth() == date.getMonth() && el.getDate().getDay() == date.getDay()&& el.getDate().getDay() == date.getDay()+1 && el.getDate().getDay() == date.getDay()+2 && el.getDate().getDay() == date.getDay()+3&& el.getDate().getDay() == date.getDay()+4 && el.getDate().getDay() == date.getDay()+5 && el.getDate().getDay() == date.getDay()+6) {

                auto it = result.begin();
                if (it->getCategory() == category && it->getPrice() < el.getPrice()) {
                    *(it) = el;
                } else if ((it + 1)->getCategory() == category && (it + 1) != result.end() && (it + 1)->getPrice() < el.getPrice()) {
                    *(it + 1) = el;
                } else if ((it + 2)->getCategory() == category && (it + 2) != result.end() && (it + 2)->getPrice() > el.getPrice()) {
                    *(it+2) = el;
                } else return;
            }
        }
    }

    if (!isWeek && category != "") {
        for(Purchase el : arr) {
            if(el.getDate().getYear() == date.getYear() && el.getDate().getMonth() == date.getMonth()) {
                auto it = result.begin();
                if (it->getCategory() == category && it->getPrice() < el.getPrice()) {
                    *(it) = el;
                } else if ((it + 1)->getCategory() == category && (it + 1) != result.end() && (it + 1)->getPrice() < el.getPrice()) {
                    *(it + 1) = el;
                } else if ((it + 2)->getCategory() == category && (it + 2) != result.end() && (it + 2)->getPrice() > el.getPrice()) {
                    *(it+2) = el;
                } else return;
            }
        }
    }
}

void Ratings::showRating(vector<Purchase> arr, Date date, string category, bool isWeek) { // completed // type = 0 - spend; 1 - category
    if (isWeek) {
        configureRatings(arr, date, category, isWeek);
    }
    if (result.empty()) {
        cout << "Here is no one rating" << endl;
        return;
    }
    for (Purchase el : result) {
        cout << "Category: " << el.getCategory() << endl << "Date: "
        << el.getDate().showDate() << endl << "Price: " << el.getPrice() << endl;
    }
}