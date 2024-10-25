#include <iostream>
#include "atm.h"

int main() {

    cout << "Hi! Welcome to Kevin's ATM Machine!" << endl;

    //creating an instance of the ATM class that handles banking operations
    ATM atm;

    //Start the program. This starts the program loop and handles all user interaction.
    atm.start();

    return 0;
}
