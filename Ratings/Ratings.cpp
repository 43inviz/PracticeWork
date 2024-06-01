#include "Ratings.h"
<<<<<<< HEAD
#include "../Purchase.h"

void Ratings::configureRatings(vector<Purchase> arr, Date date, string category, bool isWeek) {// type = 0 - spend; 1 - category
    if (arr.empty()) {
=======
#include "../Purchase/Purchase.h"

void Ratings::configureRatings( Date date, string category, bool isWeek) {// type = 0 - spend; 1 - category
    if (vecByPrice.empty()) {
>>>>>>> 53d9510 (proj)
        return;
    }

    if (isWeek && category == "") {
<<<<<<< HEAD
        for(Purchase el : arr) {
            if(el.getDate().getYear() == date.getYear() && el.getDate().getMonth() == date.getMonth() && el.getDate().getDay() == date.getDay()&& el.getDate().getDay() == date.getDay()+1 && el.getDate().getDay() == date.getDay()+2 && el.getDate().getDay() == date.getDay()+3&& el.getDate().getDay() == date.getDay()+4 && el.getDate().getDay() == date.getDay()+5 && el.getDate().getDay() == date.getDay()+6) {

                auto it = result.begin();
                if (it->getPrice() < el.getPrice()) {
                    *(it) = el;
                } else if ((it + 1) != result.end() && (it + 1)->getPrice() < el.getPrice()) {
                    *(it + 1) = el;
                } else if ((it + 2) != result.end() && (it + 2)->getPrice() > el.getPrice()) {
=======
        for(Purchase el : vecByPrice) {
            if(el.getDate().getYear() == date.getYear() && el.getDate().getMonth() == date.getMonth() && el.getDate().getDay() == date.getDay()&& el.getDate().getDay() == date.getDay()+1 && el.getDate().getDay() == date.getDay()+2 && el.getDate().getDay() == date.getDay()+3&& el.getDate().getDay() == date.getDay()+4 && el.getDate().getDay() == date.getDay()+5 && el.getDate().getDay() == date.getDay()+6) {

                auto it = vecByPrice.begin();
                if (it->getPrice() < el.getPrice()) {
                    *(it) = el;
                } else if ((it + 1) != vecByPrice.end() && (it + 1)->getPrice() < el.getPrice()) {
                    *(it + 1) = el;
                } else if ((it + 2) != vecByPrice.end() && (it + 2)->getPrice() > el.getPrice()) {
>>>>>>> 53d9510 (proj)
                    *(it+2) = el;
                } else return;
            }
        }
    }

    if (!isWeek && category == "") {
<<<<<<< HEAD
        for(Purchase el : arr) {
            if(el.getDate().getYear() == date.getYear() && el.getDate().getMonth() == date.getMonth()) {

                auto it = result.begin();
                if (it->getPrice() < el.getPrice()) {
                    *(it) = el;
                } else if ((it + 1) != result.end() && (it + 1)->getPrice() < el.getPrice()) {
                    *(it + 1) = el;
                } else if ((it + 2) != result.end() && (it + 2)->getPrice() > el.getPrice()) {
=======
        for(Purchase el : vecByPrice) {
            if(el.getDate().getYear() == date.getYear() && el.getDate().getMonth() == date.getMonth()) {

                auto it = vecByPrice.begin();
                if (it->getPrice() < el.getPrice()) {
                    *(it) = el;
                } else if ((it + 1) != vecByPrice.end() && (it + 1)->getPrice() < el.getPrice()) {
                    *(it + 1) = el;
                } else if ((it + 2) != vecByPrice.end() && (it + 2)->getPrice() > el.getPrice()) {
>>>>>>> 53d9510 (proj)
                    *(it+2) = el;
                } else return;
            }
        }
    }

    if (isWeek && category != "") {
<<<<<<< HEAD
        for(Purchase el : arr) {
            if(el.getDate().getYear() == date.getYear() && el.getDate().getMonth() == date.getMonth() && el.getDate().getDay() == date.getDay()&& el.getDate().getDay() == date.getDay()+1 && el.getDate().getDay() == date.getDay()+2 && el.getDate().getDay() == date.getDay()+3&& el.getDate().getDay() == date.getDay()+4 && el.getDate().getDay() == date.getDay()+5 && el.getDate().getDay() == date.getDay()+6) {

                auto it = result.begin();
                if (it->getCategory() == category && it->getPrice() < el.getPrice()) {
                    *(it) = el;
                } else if ((it + 1)->getCategory() == category && (it + 1) != result.end() && (it + 1)->getPrice() < el.getPrice()) {
                    *(it + 1) = el;
                } else if ((it + 2)->getCategory() == category && (it + 2) != result.end() && (it + 2)->getPrice() > el.getPrice()) {
=======
        for(Purchase el : vecByPrice) {
            if(el.getDate().getYear() == date.getYear() && el.getDate().getMonth() == date.getMonth() && el.getDate().getDay() == date.getDay()&& el.getDate().getDay() == date.getDay()+1 && el.getDate().getDay() == date.getDay()+2 && el.getDate().getDay() == date.getDay()+3&& el.getDate().getDay() == date.getDay()+4 && el.getDate().getDay() == date.getDay()+5 && el.getDate().getDay() == date.getDay()+6) {

                auto it = vecByPrice.begin();
                if (it->getCategory() == category && it->getPrice() < el.getPrice()) {
                    *(it) = el;
                } else if ((it + 1)->getCategory() == category && (it + 1) != vecByPrice.end() && (it + 1)->getPrice() < el.getPrice()) {
                    *(it + 1) = el;
                } else if ((it + 2)->getCategory() == category && (it + 2) != vecByPrice.end() && (it + 2)->getPrice() > el.getPrice()) {
>>>>>>> 53d9510 (proj)
                    *(it+2) = el;
                } else return;
            }
        }
    }

    if (!isWeek && category != "") {
<<<<<<< HEAD
        for(Purchase el : arr) {
            if(el.getDate().getYear() == date.getYear() && el.getDate().getMonth() == date.getMonth()) {
                auto it = result.begin();
                if (it->getCategory() == category && it->getPrice() < el.getPrice()) {
                    *(it) = el;
                } else if ((it + 1)->getCategory() == category && (it + 1) != result.end() && (it + 1)->getPrice() < el.getPrice()) {
                    *(it + 1) = el;
                } else if ((it + 2)->getCategory() == category && (it + 2) != result.end() && (it + 2)->getPrice() > el.getPrice()) {
=======
        for(Purchase el : vecByPrice) {
            if(el.getDate().getYear() == date.getYear() && el.getDate().getMonth() == date.getMonth()) {
                auto it = vecByPrice.begin();
                if (it->getCategory() == category && it->getPrice() < el.getPrice()) {
                    *(it) = el;
                } else if ((it + 1)->getCategory() == category && (it + 1) != vecByPrice.end() && (it + 1)->getPrice() < el.getPrice()) {
                    *(it + 1) = el;
                } else if ((it + 2)->getCategory() == category && (it + 2) != vecByPrice.end() && (it + 2)->getPrice() > el.getPrice()) {
>>>>>>> 53d9510 (proj)
                    *(it+2) = el;
                } else return;
            }
        }
    }
}

<<<<<<< HEAD
void Ratings::reportSetup(vector<Purchase> arr) {
    bool _type;
    Date date{};
    bool isWeek;

    cout << "Виведення звітів за категоріями або за витратами (категорії - 0, витрати - 1): ";
=======
void Ratings::ratingSetup(vector<Purchase> arr) {
    bool _type;
    Date date;
    bool isWeek;

    // TRANSLATE POWERED BY GOOGLE TRANSLATOR
    cout << "Output of reports by categories or by costs (categories - 0, costs - 1): ";
>>>>>>> 53d9510 (proj)
    cin >> _type;
    cout << endl;
    if (_type == 1) {
        short choose;
<<<<<<< HEAD
        cout << "Виводити за неділю (1) або місяць (2): ";
=======
        cout << "Output for week (1) or month (2): ";
>>>>>>> 53d9510 (proj)
        cin >> choose;
        cout << endl;
        if (choose == 2) {
            isWeek = false;
<<<<<<< HEAD
            cout << "Введіть дату (вводіть дату з нульовим днем): ";
            date.inputDate();
            cout << endl;
            showRating(arr, date);
        } else if (choose == 1) {
            isWeek = true;
            cout << "Введіть перший день неділі: ";
            date.inputDate();
            cout << endl;
            showRating(arr, date, "", false);
        }
    } else if (_type == 0) {
        string category;
        cout << "Введіть категорію: ";
        cin >> category;
        cout << endl;
        short choose;
        cout << "Виводити за неділю (1) або місяць (2): ";
=======
            cout << "Enter a date (enter a date with a zero day): ";
            date.inputDate();
            cout << endl;
            //showRating(arr, date);
            showRating( date);
        }
        else if (choose == 1) {
            isWeek = true;
            cout << "Enter the first day of week: ";
            date.inputDate();
            cout << endl;
            //showRating(arr, date, "", false);
            showRating( date, "", false);
        }
    }
    else if (_type == 0) {
        string category;
        cout << "Enter a category: ";
        cin >> category;
        cout << endl;
        short choose;
        cout << "Output for week (1) or month (2): ";
>>>>>>> 53d9510 (proj)
        cin >> choose;
        cout << endl;
        if (choose == 2) {
            isWeek = false;
<<<<<<< HEAD
            cout << "Введіть дату (вводіть дату з нульовим днем): ";
            date.inputDate();
            cout << endl;
            showRating(arr, date, category, isWeek);
        } else if (choose == 1) {
            isWeek = true;
            cout << "Введіть перший день неділі: ";
            date.inputDate();
            cout << endl;
            showRating(arr, date, category, isWeek);
=======
            cout << "Enter a date (enter a date with a zero day): ";
            date.inputDate();
            cout << endl;
            //showRating(arr, date, category, isWeek);
            showRating(date, category, isWeek);
        }
        else if (choose == 1) {
            isWeek = true;
            cout << "Enter the first day of week: ";
            date.inputDate();
            cout << endl;
            //showRating(arr, date, category, isWeek);
            showRating( date, category, isWeek);
>>>>>>> 53d9510 (proj)
        }
    };
}

<<<<<<< HEAD
void Ratings::showRating(vector<Purchase> arr, Date date, string category, bool isWeek) { // completed // type = 0 - spend; 1 - category

    configureRatings(arr, date, category, isWeek);

    if (result.empty()) {
=======
//void Ratings::showTopThr(vector<Purchase> vec)
//{
//    sort(vec.begin(), vec.end(), [](Purchase& pur1, Purchase& pur2) {return pur1.getPrice() < pur2.getPrice(); });
//   
//
//
//}



//void Ratings::addNewPurchaseByPrice(Purchase& pur)
//{
//
//    sort(vecByPrice.begin(), vecByPrice.end(), [](Purchase& pur, Purchase& pur2) {return pur.getPrice() < pur2.getPrice(); });
//
//}

//void Ratings::addNewPurchaseByCategory(Purchase& pur)
//{
//    
//}

//void Ratings::addNewPurchase(Purchase& pur)
//{
//    this->addNewPurchaseByPrice(pur);
//}

void Ratings::showRating( Date date, string category, bool isWeek) { // completed // type = 0 - spend; 1 - category

    configureRatings( date, category, isWeek);

    if (vecByPrice.empty()) {
>>>>>>> 53d9510 (proj)
        cout << "Here is no one rating" << endl;
        return;
    }

<<<<<<< HEAD
    for (Purchase el : result) {
        cout << "Category: " << el.getCategory() << endl << "Date: "
        << el.getDate().showDate() << endl << "Price: " << el.getPrice() << endl;
=======
    for (Purchase el : vecByPrice) {
        cout << "Category: " << el.getCategory() << endl;
        "Date: ";
        el.getDate().showDate();
        cout << "\nPrice: " << el.getPrice() << endl;
>>>>>>> 53d9510 (proj)
    }
}