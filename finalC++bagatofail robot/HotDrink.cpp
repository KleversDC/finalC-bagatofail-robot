#include "HotDrink.h"
#include <iostream>
using namespace std;
HotDrink::HotDrink(const string& name, double price) : name(name), price(price) {}

void HotDrink::display() const {
    cout << "Drink: " << name << ", Price: " << price << " UAH" << endl;
}

string HotDrink::getName() const {
    return name;
}

double HotDrink::getPrice() const {
    return price;
}

void HotDrink::setPrice(double newPrice) {
    if (newPrice > 0) {
        price = newPrice;
    }
    else {
        cout << "Price must be greater than 0 UAH!" << endl;
    }
}
HotDrink::~HotDrink() {}
Coffee::Coffee() : HotDrink("Coffee", 20.0) {}
Tea::Tea() : HotDrink("Tea", 15.0) {}
Cappuccino::Cappuccino() : HotDrink("Cappuccino", 25.0) {}

