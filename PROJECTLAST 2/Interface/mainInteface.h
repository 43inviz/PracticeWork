#pragma once

#include "../PaymentSystem/PaymentSystem.h"
#include "../DebetCard/DebetCard.h"
#include "../CreditCard/CreditCard.h"
#include "../User/User.h"


#include "../FileSystm/CreditFileSyst/CreditFileSyst.h"
#include "../FileSystm/DebetFile/DebetFileSyst.h"
#include "../FileSystm/UserFile/UserFileSyst.h"
#include "../FileSystm/PurchseFile/PurchaseFileSyst.h"

#include "../Menu/UserMenu/UserMenu.h"

#include "../Exceptions/Exception.h"
#include "../Ratings/Ratings.h"
#include "../Reports/Reports.h"


#include <iostream>
#include <string>
#include <vector>
#include <memory>



void section1(User& user) {
	int infoChoice;

	do {
		informationMenu();
		cin >> infoChoice;

		switch (infoChoice)
		{
		case 1:
		{
			user.showAllPaymentSystems();
			system("pause");
			break;
		}
		case 2:
		{
			user.showAllPurchase();
			system("pause");
			break;
		}
		case 3:
		{
			user.showUser();
			system("pause");
			break;
		}
		default:
			break;
		}

	} while (infoChoice != 0);
	
}

void section2(User& user,DebetFileSystem debetFile,CreditFileSystem creditFile,PurchaseFileSyst purFile,Ratings rating) {
	int cardChoice;
	do {
		cardsMenu();
		cin >> cardChoice;
		cin.ignore();
		switch (cardChoice)
		{
		case 1:
			user.createNewPayment(debetFile,creditFile);
			break;
		case 2: {
			Purchase pur = user.createPurchase();
			user.addPurchase(pur,purFile,rating);
			break;
		}
		case 3:
			user.addMoneyOnSearchedPayment();
			break;
		case 4:
			user.withDrawMoneyFromSearchedPayment();
			break;
		default:
			break;
		}

	} while (cardChoice != 0);

}

void reportSection(User& user,PurchaseFileSyst file) {
	int reportChoice;
	do {
		Reports newRep;
		reportsMenu();
		cin >> reportChoice;
		switch (reportChoice)
		{
		case 1:
		{
			newRep.reportSetup();
			newRep.showReport(user.getPurchseVec());
			system("pause");
			break;
		}
		case 2:
		{
			file.saveInFile(user.getPurchseVec(), user.getLogin());
			break;
		}
	
		default:
			break;
		}
	} while (reportChoice != 0);
}


void ratingSection(User& user,PurchaseFileSyst file) {
	int ratingChoice;
	vector<Purchase> purVec = user.getPurchseVec();
	do {
		ratingsMenu();
		cin >> ratingChoice;
		switch (ratingChoice)
		{
		case 1:
		{
			Ratings rating;
			rating.ratingSetup(purVec);//и тут же вывод
			system("pause");
			break;
		}
		case 2:
		{
			file.saveReport(user.getPurchseVec(), user.getLogin());
			break;
		}
		case 3:
		{
			file.loadReport(user.getPurchseVec(), user.getLogin());
			break;
		}
		default:
			break;
		}

	} while (ratingChoice != 0);
}


void start() {

	//UserFileSyst userFile;
	//DebetFileSystem debetFile;
	//CreditFileSystem creditFile;
	//PurchaseFileSyst purFile;

	User startUser;
	int choice;
	int userMenuChoice;

	int infoChoice;
	int cardChoice;

	string cardNumber;

	do {
		UserFileSyst userFile;
		DebetFileSystem debetFile;
		CreditFileSystem creditFile;
		PurchaseFileSyst purFile;

		Ratings rating;

		startMenu();
		cin >> choice;
		cin.ignore();
		switch (choice)
		{
		case 1: 
		{
			if (startUser.authorization(userFile.getUserVector())) 
			{
				startUser.setUserPurchase(purFile.loadFromFile(startUser.getPurchseVec(), startUser.getLogin()));
				startUser.searchUserPayments(creditFile.getCreditVector(),debetFile.getDebetVector());
				do 
				{
					sectionMenu(startUser);
					cin >> userMenuChoice;
					

					switch (userMenuChoice)
					{
					case 1: 
					{
						section1(startUser);
						break;
						
					}
					
					case 2:
					{
						section2(startUser,debetFile,creditFile,purFile,rating);
						break;
					}
					case 3:
					{
						reportSection(startUser,purFile);
						break;
					}
					case 4:
					{
						ratingSection(startUser,purFile);
					}
					default:
						break;
					}
				} while (userMenuChoice != 0);
				
			}
			else {
				throw Exceptions(const_cast<char*>("We cant find ur acc\n"));
			}

			system("cls");
			cout << "BYE!\n";
			return;
		}
		case 2:
		{
			
			startUser.registration();
			userFile.saveNewUserInFile(startUser);
		}
			
		default:
			break;
		}
	} while (choice != 0);
	


}

