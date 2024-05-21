#include "./Menu/Menu.h"
#include "./User/User.h"

using namespace std;

int main()
{
    srand(time(0));

    string name = "Alex Cool";
    string login = "123@gmail.com";
    string pass = "123Alex!";
    User user(name, login, pass);
    user.readUserFromFile();
    bool res = user.autorization();
    if (res) {
        cout << "Autorization done!\n";
        cout << "Welcome back " << user.getName() << endl;
    } else {
        cout << "try again\n";
    }

    choiceEnterMenu();
    return 0;
}
