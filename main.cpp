#include "./Menu/Menu.h"
#include "./User/User.h"

using namespace std;

int main()
{
    srand(time(0));

//    string name = "Alex Cool";
//    string login = "123@gmail.com";
//    string pass = "123Alex!";
    User user("123", "123", "123");
    //bool res = user.autorization();
//    if (res) {
//        cout << "Autorization done!\n";
//        cout << "Welcome back " << user.getName() << endl;
//    } else {
//        cout << "try again\n";
//    }
    user.saveNewUserInFile();
    //choiceEnterMenu();
    User user1{};

    user1.readUserFromFile();

    cout << user1.getName();
    return 0;
}
