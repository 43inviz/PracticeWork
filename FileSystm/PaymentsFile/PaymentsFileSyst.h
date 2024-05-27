#pragma once
#include "../../PaymentSystem/PaymentSystem.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class PaymentsFileSystem {

	vector<shared_ptr<PaymentSystem>> _paymentsVector;

};
