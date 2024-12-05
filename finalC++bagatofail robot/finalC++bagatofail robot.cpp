#include "VendingMachine.h"
#include "HotDrink.h"
#include <iostream>
using namespace std;
int main() {
    VendingMachine vm;
    int mode;

    do {
        cout << "\n--- Select Mode ---\n";
        cout << "1. Admin\n";
        cout << "2. User\n";
        cout << "0. Exit\n";
        cout << "Your choice: ";
        cin >> mode;

        switch (mode) {
        case 1:
            vm.adminMode();
            break;
        case 2:
            vm.userMode();
            break;
        case 0:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice!\n";
            break;
        }
    } while (mode != 0);
}
