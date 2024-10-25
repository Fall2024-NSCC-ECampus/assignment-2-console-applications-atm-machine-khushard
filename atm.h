#ifndef ATM_H
#define ATM_H

#include <iostream>
#include <vector>
using namespace std;

class ATM {

private:
    struct Account {
        string userId;
        string password;
        double balance;
    };

    vector<Account> accounts;
    int currentAccountIndex = -1; //Start with nobody logged in.

public:
    ATM();
    void printIntroMenu();
    void printMainMenu();
    void start();
    void login();
    void createAccount();
    void deposit();
    void withdraw();
    void requestBalance();

};

#endif
