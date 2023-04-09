#include <iostream>
#include "Utils/hotel.hpp"

using namespace std;
using namespace hotel;

int main() {
    Customer x;

    x.takeCustomerDetails();
    x.showMenu();
    x.takeOrders();
    x.calculateBillAmount();
    x.displayBill();

    cout << endl;
    cout << "Press Enter to exit...";

    char temp = 'x';
    while (true) {
        cin.ignore();
        cin.get(temp);
        if (temp == '\n')
            break;
    }

    return 0;
}
