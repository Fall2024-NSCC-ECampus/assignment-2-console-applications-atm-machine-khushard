#include "ATM.h"
#include <iomanip>

using namespace std;

ATM::ATM() {
    // -1 indicates a user is not currently logged in. WHen a user logs in, this changes to their account index in the vector.
    currentAccountIndex = -1;
}


// Prints the intro menu options, when users are not logged in
void ATM::printIntroMenu() {
    cout << "Please select an option from the menu below:" <<endl;
    cout << "l -> Login" <<endl;
    cout << "c -> Create New Account" << endl;
    cout << "q -> Quit" << endl;
    cout << ">" <<endl;
}

// Prints the main menu options, when users are logged in
void ATM::printMainMenu() {
    cout << "d -> Deposit Money" <<endl;
    cout << "w -> Withdraw Money" << endl;
    cout << "r -> Request Balance" << endl;
    cout << "q -> Quit" << endl;
    cout << ">" << endl;
}

//Starts the program
void ATM::start() {
    char choice;

    while (true) {
        if (currentAccountIndex == -1) { // So, if currentAccountIndex is -1, no user is logged in and we show intro menu
            printIntroMenu();
            cin >> choice;

            switch (choice) {
                case 'l':
                    login();
                    break;
                case 'c':
                    createAccount();
                    break;
                case 'q':
                    cout << "Thanks for stopping by!";
                    return;
            }

        }
        // If index isnt -1, we print main menu as someone is logged in.
        else {
            printMainMenu();
            cin >> choice;

            // Switch case calling methods to do operations
            switch (choice) {
                case 'd':
                    deposit();
                    break;
                case 'w':
                    withdraw();
                    break;
                case 'r':
                    requestBalance();
                    break;
                case 'q':
                    currentAccountIndex = -1;
                    cout << "Logged out successfully!" << endl;
                    break;
            }
        }
    }
}

void ATM::createAccount() {
    string userId, password;

    cout << "Please enter your user name: " ;
    cin >> userId;

    // For loop to determine if username exists.
    for (int i = 0; i < accounts.size(); i++) {
        if(accounts[i].userId == userId) {
            cout << "User ID already exists!" <<endl;
            return;
        }
    }

    cout << "Please enter your password: " ;
    cin >> password;

    Account newAccount{userId, password, 0.0};
    accounts.push_back(newAccount);

    cout << "Thank you! Your account has been created!" <<endl;

}


void ATM::login() {
    string userId, password;

    cout << "Please enter your user ID: " ;
    cin >> userId;
    cout << "Please enter your password: " ;
    cin >> password;


    // For loop to loop through vector and log in if current index equals username and password.
    for ( int i = 0; i < accounts.size(); i++) {
        if (accounts[i].userId == userId && accounts[i].password == password){
            currentAccountIndex = i;
            cout << "Access Granted!" << endl;
            return;
        }
    }

    cout << "********** LOGIN FAILED! ********** " <<endl;

}

void ATM::deposit() {
    //Confirms user is logged in before starting method
    if (currentAccountIndex == -1)
        return;

    double amount;
    cout << "Amount of deposit: $" ;
    cin >> amount;

    //Verifies the amount is positive before adding to balance.
    if (amount > 0) {
        accounts[currentAccountIndex].balance += amount;
    } else {
        cout << "Invalid amount!" <<endl;
    }

}

void ATM::withdraw() {
    //Confirms user is logged in before starting method
    if (currentAccountIndex == -1)
        return;

    double amount;
    cout <<"Amount of withdrawal: $";
    cin >> amount;

    //Verifies amount is greater than 0 but less than or equal to balance.
    if (amount > 0 && amount <= accounts[currentAccountIndex].balance){
        accounts[currentAccountIndex].balance -= amount;
    } else {
        cout << "Invalid amount of insufficient funds!" << endl;
    }

}

void ATM::requestBalance() {
    if (currentAccountIndex == -1)
        return;

    cout << "Your balance is $" <<fixed << setprecision(2) << accounts[currentAccountIndex].balance << endl;

}