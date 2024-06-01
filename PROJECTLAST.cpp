
#include "./Interface/mainInteface.h"


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

	return 0;
}
