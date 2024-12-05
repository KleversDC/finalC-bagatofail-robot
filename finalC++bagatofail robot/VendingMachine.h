#pragma once
#include "HotDrink.h"
#include <vector>
#include <string>

class VendingMachine {
private:
    std::vector<HotDrink*> drinks;
    double cash;
    double water;
    double coffee;
    double tea;
    double sugar;
    bool checkResources(const std::string& drink);
    void useResources(const std::string& drink);
public:
    VendingMachine();
    ~VendingMachine();
    void adminMode();
    void userMode();
};
