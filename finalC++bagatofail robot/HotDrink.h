#pragma once
#include <string>
using namespace std;
class HotDrink {
protected:
    string name;
    double price;
public:
    HotDrink(const string& name, double price);
    virtual void display() const;
    string getName() const;
    double getPrice() const;
    void setPrice(double newPrice);
    virtual ~HotDrink();
};
class Coffee : public HotDrink {
public:
    Coffee();
};
class Tea : public HotDrink {
public:
    Tea();
};
class Cappuccino : public HotDrink {
public:
    Cappuccino();
};

