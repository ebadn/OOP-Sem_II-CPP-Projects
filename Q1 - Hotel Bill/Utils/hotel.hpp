#ifndef HOTEL_HPP
#define HOTEL_HPP

#include <string>

namespace hotel {
    const std::string my_GSTIN = "27CUGPN6461C1Z5";

    class Customer {
        const std::string menu[10]{"Veg Korma", "Paneer Butter Masala", "Indrani Rice", "Chicken Keema", "Chicken Biryani", "Mutton Biryani", "Butter Roti", "Butter Naan", "Dessert", "Ice Cream"};
        const short rates[10] = {200, 300, 150, 350, 400, 700, 30, 50, 100, 150};

    public:
        short table_number = 0;
        std::string customer_name;
        long long customer_contact = 0;
        std::string customer_GSTIN;
        short orders[10] = {};
        short quantities[10] = {};
        const double discount_rate = 0.05;
        double discount_amount = 0;
        const double GST_rate = 0.18;
        double GST_amount = 0;
        double bill_amount = 0;
        double final_amount = 0;

        void takeCustomerDetails();
        void showMenu();
        void takeOrders();
        void calculateBillAmount();
        void displayBill();
    };
}

#endif //HOTEL_HPP