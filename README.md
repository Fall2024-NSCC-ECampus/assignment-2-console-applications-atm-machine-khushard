[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/v8RAz1je)

ATM Machine Project

Description:

This is a C++ program that is meant to act as a simple ATM system. A user can create accounts, login, and perform basic banking operations such as deposits, withdrawals, and balance inquiries.

Features:

  * Account Management
    - Create new accounts using userID and password
    - Basic Login System
    - Support for Multiple accounts using a vector
   
  * Banking Operations
    - Deposit funds
    - Withdraw funds while confirming balance exists to support the withdrawal
    - Check the account balance
   
  * User Interface
    - A clear menu system
    - Simple command line interface
    - Session based account storage



Usage:

1. Run the compile program
2. Follow the prompts on the screen
   - 'C' to create a new account
   - 'L' to log in
   - 'Q' to quit
3. Once logged in you can do the following
   - 'D' to deposit money
   - 'W' to withdraw money
   - 'R' to request balance
   - 'Q' to logout
  
Implementation Details:

* Uses vectors for dynamic account storage
* Indentifies account state by using index tracking
* Implements basic error checks:
   - Duplicate user ID check
   - Invalid ammount check
   - Insufficient funds check
   - Login Validation


Future Improvements:

* Add persistance to the user accounts created ( save the accounts )
* Implement a transaction history
* Add password encryption
* Add functionality for deleting accounts.






