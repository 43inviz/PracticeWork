
//#include "./PaymentSystem/PaymentSystem.h"
//#include "./DebetCard/DebetCard.h"
//#include "./CreditCard/CreditCard.h"
//#include "./User/User.h"
//
//
//#include "./FileSystm/UserFile/UserFileSyst.h"
//#include "./FileSystm/DebetFile/DebetFileSyst.h"
//#include "./FileSystm/CreditFileSyst/CreditFileSyst.h"

#include "./Interface/mainInteface.h"

//#include "./Menu/UserMenu/UserMenu.h"

#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;


int main()
{


	try {
		start();
	}
	catch (Exceptions& ex) {
		cout << ex.what() << endl;
	}
	//srand(time(0));
	//UserFileSyst file;
	//DebetFileSystem debetFile;
	//CreditFileSystem creditFile;

	//vector<User> userVec = file.getUserVector();
	//vector<CreditCard> creditVec = creditFile.getCreditVector();
	//vector<DebetCard> debetVec = debetFile.getDebetVector();

	///*for (auto& el : creditVec) {
	//	el.show();
	//}*/


	//User user;
	//if (user.authorization(userVec)) {
	//	
	//	user.searchUserPayments(creditVec, debetVec);

	//	//user.showAllPaymentSystems();
	//	user.addMoneyOnSearchedPayment();
	//	user.showAllPaymentSystems();
	//}
	//user.registration();
	//file.saveNewUserInFile(user);
	//user.createNewPayment(debetFile,creditFile);
	//user.createNewPayment(debetFile,creditFile);
	//user.showAllPaymentSystems();


	/*User user;*/

	//РЕГА
	//user.registration();
	//file.saveNewUserInFile(user);
	


	//ПРОВЕРКА 
	//vector<User> userVec = file.getUserVector();
	//vector<int> passVec;
	//for (auto& el : userVec) {
	//	passVec = el.getPassVec();
	//	el.showUser();
	//	for (auto& elem : passVec) {
	//		cout << elem << " ";
	//	}
	//	

	//}
	
	//ОСТАНОВИЛСЯ ТУТ,ШИФР И ДЕШИФР РАБОТАЕТ!
	//if (user.authorization(file.getUserVector())) {
	//	user.showUser();
	//}
	//else {
	//	cout << "cant find ur acc\n";
	//}


	

	
	
	//User user("123", "123", "123");
	//vector<Purchase> vecPur(3);

	//for (auto i = vecPur.begin(); i != vecPur.end(); i++) {
	//	*i = user.createPurchase();
	//}
	//
	//user.setUserPurchase(vecPur);
	//user.showAllPurchase();
	return 0;
}
