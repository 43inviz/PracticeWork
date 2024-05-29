
#include "./PaymentSystem/PaymentSystem.h"
#include "./DebetCard/DebetCard.h"
#include "./CreditCard/CreditCard.h"
#include "./User/User.h"
#include "./FileSystm/UserFile/UserFileSyst.h"
#include "./Menu/UserMenu/UserMenu.h"
#include "Exceptions/Exception.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

int main()
{

	
	UserFileSyst file;
	int choice;
	startMenu();
	cin >> choice;
	User user("999", "999", "999");
	file.saveNewUserInFile(user);
	//cin.ignore();
	//switch ((choice))
	//{
	//case 1:

	//	if (user.authorization(file.getUserVector())) {
	//		//system("cls");
	//		user.createNewPayment();
	//	}
	//	else {
	//		cout << "We cant find ur account\n";
	//	}
	//	break;
	//case 2:
	//	user.registration();
	//	//system("cls");
	//	break;
	//default:
	//	break;
	//}
	//
	//user.showAllPaymentSystems();
	
	//User user("123", "123", "123");
	//file.saveNewUserInFile(user);
	//DebetCard card1("123456", "debet");
	//CreditCard card2("00000", "credit");
	////user.saveNewUserInFile();
	//
	//if (user.authorization(file.getUserVector())) {
	//	user.showUser();
	//	user.createNewPayment();
	//	user.showAllPaymentSystems();
	//}
	//else {
	//	cout << "U cant enter\n";
	//}



	return 0;
}
