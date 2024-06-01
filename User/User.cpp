#include "User.h"

<<<<<<< HEAD
void User::readUserFromFile()
{
    try {
        ifstream fin;
        fin.open(FILENAME);
        if (!fin.is_open()) {
            throw Exceptions(const_cast<char*>("User.txt cant open for read\n"));
        }

        string userName, userLogin, userPass;
        fin >> userName;
        fin >> userLogin;
        fin >> userPass;

        this->setName(userName);
        this->setLogin(userLogin);
        this->setPass(userPass);

        fin.close();
    }
    catch (const Exceptions& ex) {
        cout << ex.what() << endl;
        exit(1);
    }
}

void User::saveNewUserInFile()
{
    try {
        ofstream fout;
        fout.open(FILENAME);
        if (!fout.is_open()) {
            throw Exceptions(const_cast<char*>("User.txt cant opend for save\n"));
        }
        fout << _userName << "\n";
        fout << _userLogin << "\n";
        fout << _userPass << "\n";
        fout.close();
    }
    catch (exception& ex) {
        cout << ex.what() << endl;
    }
}

bool User::autorization()
{
    string userLogin;
    string userPass;

    

    cout << "Enter your login: ";
    getline(cin, userLogin);
    cout << "Enter your password: ";
    getline(cin, userPass);

    if (this->_userLogin == userLogin || this->_userPass == userPass) {
        return true;
    }
    return false;
=======
void User::addDebetCard(DebetCard& card)
{
	shared_ptr<PaymentSystem> debetCard = make_shared<DebetCard>(card);
	_userPayments.push_back(debetCard);
}

void User::addCreditCard(CreditCard& card)
{
	shared_ptr<PaymentSystem> creditCard = make_shared<CreditCard>(card);
	_userPayments.push_back(creditCard);
}

void User::createNewPayment(DebetFileSystem debetFile, CreditFileSystem creditFile)
{
	int choice;
	cout << "1 - create Debet Card\n";
	cout << "2 - create Credit Card\n";
	cout << "Enter choice: ";
	cin >> choice;

	switch (choice) {
	case 1: {
		DebetCard debetCard(this->getName(), this->createNewCardNumer(), "debet");
		addDebetCard(debetCard);
		debetFile.saveNewDebetCardIFile(debetCard);
		break;
	}
	case 2: {
		CreditCard creditCard(this->getName(), this->createNewCardNumer(), "credit");
		addCreditCard(creditCard);
		creditFile.saveNewCreditCardInFile(creditCard);
		break;
	}

	default:
		break;
	}
}



void User::addPurchase(Purchase& pur,PurchaseFileSyst file, Ratings rating)
{
	_userPurchase.push_back(pur);
	file.saveNewPurchaseInFile(pur);
	//rating.addNewPurchase(pur);
}

Purchase User::createPurchase()
{

	double price;
	string category;
	cout << "Enter price: ";
	cin >> price;
	cin.ignore();
	cout << "Enter category: ";
	getline(cin, category);
	Date date;
	date.inputDate();
	Purchase newPur(this->getLogin(), price, date, category);

	return newPur;

}

string User::createNewCardNumer()
{
	string newCard;
	for (int i = 0; i < 10; i++) {
		newCard += to_string(rand() % 10);
	}
	return newCard;
}



void User::showAllPaymentSystems()
{
	for (auto i = _userPayments.begin(); i != _userPayments.end(); i++) {
		(*i)->show();
	}
}

void User::showAllPurchase() //все покупки юзера
{
	for (auto i = _userPurchase.begin(); i != _userPurchase.end(); i++) {
		i->showPurchase();
	}
}

bool User::authorization(vector<User> userVec)
{
	string login, pass;

	cout << "Enter login: ";
	getline(cin, login);
	cout << "Enter pass: ";
	getline(cin, pass);

	for (auto i = userVec.begin(); i != userVec.end(); i++) {
		i->passwordDecryption(*i);
		
		if (i->_userLogin == login && i->_userPass == pass) {
			this->setName(i->getName());
			this->setLogin(i->getLogin());
			this->setPass(i->getPass());
			return true;
		}
	}


	return false;


>>>>>>> 53d9510 (proj)
}

void User::registration()
{
<<<<<<< HEAD
    string newName, newLogin, newPass;
    cout << "Enter your name: ";
    getline(cin, newName);
    cout << "Enter your Phone or E-Mail(will be used as login): ";
    getline(cin, newLogin);
    cout << "Create password: ";
    getline(cin, newPass);

    this->setName(newName);
    this->setLogin(newLogin);
    this->setLogin(newPass);

    this->saveNewUserInFile();
=======
	string newName, newLogin, newPass;
	cout << "Enter your name: ";
	getline(cin, newName);
	cout << "Enter your login: ";
	getline(cin, newLogin);
	cout << "Create password: ";
	getline(cin, newPass);

	this->setName(newName);
	this->setPass(newPass);
	this->setLogin(newLogin);

	this->passwordEncryption();

	

}

void User::showUser()
{
	cout << "Name: " << _userName << endl;
	cout << "Login: " << _userLogin << endl;
	cout << "Count of purchase: " << _userPurchase.size() << endl;
	cout << "Count of cards: " << _userPayments.size() << endl;
}

void User::passwordEncryption() //в шифр!!!!
{
	string newPass(_userPass.size(), '\0');
	vector<int> intVec;
	int currentMove;
	for (int i = 0; i < _userPass.size(); i++) {
		currentMove = rand() % 10;
		newPass[i] = _userPass[i] + currentMove;
		intVec.push_back(currentMove);
	}

	_userPass = newPass;
	_passEncrypt = intVec;
}

void User::passwordDecryption(User& user)//из шифра в норм!!!!!
{

	string newPass(_userPass.size(), '\0');

	for (int i = 0; i < _userPass.size(); i++) {
		newPass[i] = static_cast<char>(_userPass[i] - _passEncrypt[i]);
	}

	user.setPass(newPass);
}

void User::searchUserPayments(vector<CreditCard> creditVec, vector<DebetCard> debetVec) //поиск в векторе при считывании с файла ќЅўјя 
{
	this->searchCreditCard(creditVec);
	this->searchDebetCard(debetVec);
}

void User::searchUserPurchase(vector<Purchase> purchaseVec)
{
	for (auto& pur : purchaseVec) {
		if (pur.getOwnerLogin() == this->getLogin()) {
			_userPurchase.push_back(pur);
		}
	}
}

void User::searchCreditCard(vector<CreditCard> vect) //поиск кредиток при авторизации
{
	for (auto& card : vect) {
		if (card.getOwnerName() == this->getName()) {
			this->addCreditCard(card);
		}
	}
}

void User::searchDebetCard(vector<DebetCard> vect)//дебетовые при авторизации
{
	for (auto& card : vect) {
		if (card.getOwnerName() == this->getName()) {
			this->addDebetCard(card);
		}
	}
}

void User::addMoneyOnSearchedPayment()
{

	cout << "Available cards:" << endl;
	this->showAllPaymentSystems();
	cout << "=======\n";
	string cardNumber;
	cout << "Enter card number: ";
	getline(cin, cardNumber);
	for (auto& card : this->getPayments()) {
		if (card->getCardNumber() == cardNumber) {
			card->addMoneyOnBalance();
			break;
		}
	}
}

void User::withDrawMoneyFromSearchedPayment()
{
	cout << "Available cards" << endl;
	this->showAllPaymentSystems();
	cout << "======\n";
	string cardNumber;
	cout << "Enter card number: ";
	getline(cin, cardNumber);
	for (auto& card : this->getPayments()) {
		if(card->getCardNumber() == cardNumber){
			card->withDrawFromBalance();
			break;
		}
	}

>>>>>>> 53d9510 (proj)
}
