#include "VendingMachine.h"
#include <iostream>
using namespace std;
VendingMachine::VendingMachine() : cash(0), water(5000), coffee(1000), tea(500), sugar(1000) {
    drinks.push_back(new Coffee());
    drinks.push_back(new Tea());
    drinks.push_back(new Cappuccino());
}
VendingMachine::~VendingMachine() {
    for (auto drink : drinks) {
        delete drink;
    }
}

bool VendingMachine::checkResources(const string& drink) {
    if (drink == "Coffee" && (water < 200 || coffee < 20 || sugar < 10)) return false;
    if (drink == "Tea" && (water < 200 || tea < 10 || sugar < 10)) return false;
    if (drink == "Cappuccino" && (water < 200 || coffee < 20 || sugar < 15)) return false;
    return true;
}

void VendingMachine::useResources(const string& drink) {
    if (drink == "Coffee") {
        water -= 200;
        coffee -= 20;
        sugar -= 10;
    }
    else if (drink == "Tea") {
        water -= 200;
        tea -= 10;
        sugar -= 10;
    }
    else if (drink == "Cappuccino") {
        water -= 200;
        coffee -= 20;
        sugar -= 15;
    }
}

void VendingMachine::adminMode() {
    int choice;
    do {
        system("cls");
        cout << "\n--- Admin Mode ---\n";
        cout << "1. Refill resources\n";
        cout << "2. View resource statistics\n";
        cout << "3. Change drink prices\n";
        cout << "4. Collect cash\n";
        cout << "0. Exit\n";
        cout << "Your choice: ";
        cin >> choice;

        system("cls");

        switch (choice) {
        case 1: {
            double addWater, addCoffee, addTea, addSugar;
            cout << "How much water to add (ml)? "; cin >> addWater; water += addWater;
            cout << "How much coffee to add (g)? "; cin >> addCoffee; coffee += addCoffee;
            cout << "How much tea to add (g)? "; cin >> addTea; tea += addTea;
            cout << "How much sugar to add (g)? "; cin >> addSugar; sugar += addSugar;
            break;
        }
        case 2:
            cout << "\nResource Statistics:\n";
            cout << "Water: " << water << " ml\n";
            cout << "Coffee: " << coffee << " g\n";
            cout << "Tea: " << tea << " g\n";
            cout << "Sugar: " << sugar << " g\n";
            cout << "Cash: " << cash << " UAH\n";
            system("pause");
            break;
        case 3: {
            for (auto drink : drinks) {
                double newPrice;
                cout << "Enter new price for " << drink->getName() << ": ";
                cin >> newPrice;
                drink->setPrice(newPrice);
            }
            break;
        }
        case 4:
            cout << "Collected cash: " << cash << " UAH\n";
            cash = 0;
            system("pause");
            break;
        case 0:
            cout << "Exiting admin mode.\n";
            break;
        default:
            cout << "Invalid choice!\n";
            system("pause");
            break;
        }
    } while (choice != 0);
}

void VendingMachine::userMode() {
    int choice;
    do {
        system("cls");
        cout << "\n--- User Mode ---\n";
        cout << "1. Order a drink\n";
        cout << "2. View drinks\n";
        cout << "0. Exit\n";
        cout << "Your choice: ";
        cin >> choice;

        system("cls");

        switch (choice) {
        case 1: {
            int drinkChoice;
            cout << "\nSelect a drink:\n";
            for (size_t i = 0; i < drinks.size(); ++i) {
                cout << i + 1 << ". ";
                drinks[i]->display();
            }
            cout << "Your choice: ";
            cin >> drinkChoice;

            system("cls");

            if (drinkChoice >= 1 && drinkChoice <= drinks.size()) {
                HotDrink* selectedDrink = drinks[drinkChoice - 1];
                if (checkResources(selectedDrink->getName())) {
                    double payment;
                    cout << "Insert " << selectedDrink->getPrice() << " UAH: ";
                    cin >> payment;

                    if (payment >= selectedDrink->getPrice()) {
                        cout << "Thank you for your purchase!\n";
                        cash += selectedDrink->getPrice();
                        useResources(selectedDrink->getName());
                        if (payment > selectedDrink->getPrice()) {
                            cout << "Your change: " << payment - selectedDrink->getPrice() << " UAH\n";
                        }
                    }
                    else {
                        cout << "Not enough money!\n";
                    }
                }
                else {
                    cout << "Not enough resources to make this drink!\n";
                }
            }
            else {
                cout << "Invalid choice!\n";
            }
            system("pause");
            break;
        }
        case 2:
            cout << "\nAvailable drinks:\n";
            for (auto drink : drinks) {
                drink->display();
            }
            system("pause");
            break;
        case 0:
            cout << "Exiting user mode.\n";
            break;
        default:
            cout << "Invalid choice!\n";
            system("pause");
            break;
        }
    } while (choice != 0);
}

