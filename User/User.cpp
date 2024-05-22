#include "User.h"

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
}

void User::registration()
{
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
}
