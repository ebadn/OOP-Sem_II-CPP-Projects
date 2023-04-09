#include "hotel.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

void hotel::Customer::takeCustomerDetails() {
    cout << "Enter Customer Details..." << endl;

    cout << "  Table number: "
         << "\033[32m";
    cin >> table_number;
    cout << "\033[0m";

    cout << "  Full Name: "
         << "\033[32m";
    cin.ignore();
    getline(cin, customer_name);
    cout << "\033[0m";

    cout << "  Contact Number: "
         << "\033[32m";
    cin >> customer_contact;
    cout << "\033[0m";

    cout << "  GSTIN number: "
         << "\033[32m";
    cin.ignore();
    getline(cin, customer_GSTIN);
    cout << "\033[0m";
}

void hotel::Customer::showMenu() {
    cout << endl;
    cout << right << setw(24) << "--Menu--" << endl << endl;

    for (short i = 0; i < 10; i++) {
        cout << right;
        cout << setw(4) << i + 1 << ". "
             << left
             << setw(24) << menu[i]
             << "Rs. " << rates[i] << ".00" << endl;
    }
}

void hotel::Customer::takeOrders() {
    cout << endl;
    cout << "Enter the index numbers of the items you want to order." << endl
         << R"((eg: Enter "1, 3, 10" to order "Veg Korma, Indrani Rice and Ice Cream"))" << endl;
    cout << "  Enter orders: " << "\033[32m";

    short i = 0;
    while (i < 10) {
        char temp = 'x';
        cin.get(temp);
        if (temp == '\n')
            break;
        else if (temp <= 47 || temp >= 58)
            continue;

        cin.unget();
        cin >> orders[i];
        i++;
    }

    cout << "\033[0m" << endl;
    cout << "Enter quantities for..." << endl;

    i = 0;
    for (short item: orders) {
        if (item == 0)
            break;

        cout << "  " << menu[item - 1] << ": " << "\033[32m";
        cin >> quantities[i];
        cout << "\033[0m";

        i++;
    }
}

void hotel::Customer::calculateBillAmount() {
    short i = 0;
    for (short item: orders) {
        if (item == 0)
            break;

        bill_amount += rates[item - 1] * quantities[i];

        i++;
    }

    discount_amount = bill_amount * discount_rate;
    GST_amount = (bill_amount - discount_amount) * GST_rate;
    final_amount = bill_amount - discount_amount + GST_amount;
}

void hotel::Customer::displayBill() {
    time_t current_time = std::time(nullptr);
    tm *local_time = std::localtime(&current_time);

    cout << endl;
    cout << right << setw(34) << "--Bill--" << endl << endl;

    cout << setfill('0') << right;
    cout << "Date: " << setw(2) << local_time->tm_mday << "/" << setw(2) << (local_time->tm_mon + 1) << "/"
         << (local_time->tm_year + 1900) << endl << endl;
    cout << setfill(' ');

    cout << "Shop GSTIN: " << my_GSTIN << endl
         << "Customer GSTIN: " << customer_GSTIN << endl << endl;

    cout << "Customer details..." << endl
         << "  Table number: " << table_number << endl
         << "  Name: " << customer_name << endl
         << "  Contact Number: " << customer_contact << endl << endl;

    cout << left;
    cout << "Sr No " << setw(24) << "          Item" << setw(8) << "Quantity" << setw(10) << "   Rate" << setw(11)
         << "   Price" << endl;

    short i = 0;
    for (short item: orders) {
        if (item == 0)
            break;

        cout << right;
        cout << setw(4) << i + 1 << ". ";
        cout << left;
        cout << setw(24) << menu[item - 1];
        cout << setw(8) << quantities[i];
        cout << fixed << setprecision(2);
        cout << "   " << setw(7) << static_cast<double>(rates[item - 1]);
        cout << "   " << static_cast<double>(quantities[i] * rates[item - 1]);
        cout << endl;

        i++;
    }

    cout << fixed << setprecision(2) << endl;
    cout << "Total Amount: Rs " << bill_amount << endl
         << "Discount Applicable: 5%" << endl
         << "Discount Amount: Rs " << discount_amount << endl
         << "GST Applicable: 18%" << endl
         << "GST Amount: " << GST_amount << endl
         << "Bill Amount: Rs " << final_amount << endl;
}