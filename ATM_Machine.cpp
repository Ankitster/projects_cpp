#include <iostream>
#include <string>
#include <vector>

using namespace std;

// function prototypes
void printIntroMenu();
void printMainMenu();
void start();
void createAccount();
void login();
void depositMoney(int accountIndex);
void withdrawMoney(int accountIndex);
void requestBalance(int accountIndex);

// structure for bank account
struct BankAccount
{
    string userID;
    string password;
    double balance;
};

vector<BankAccount> accounts; // global vector to hold all bank accounts

// the main function
int main()
{

    cout << "Hi! Welcome to Mr. Ankit's ATM Machine!" << endl; // print welcome message

    start(); // call the function start

    return 0;
}

void printIntroMenu()
{
    cout << "Please select an option from the menu below:" << endl;
    cout << "l -> Login" << endl;
    cout << "c -> Create New Account" << endl;
    cout << "q -> Quit" << endl;
    cout << "> ";
}

void printMainMenu()
{
    cout << "Please select an option from the menu below:" << endl;
    cout << "d -> Deposit Money" << endl;
    cout << "w -> Withdraw Money" << endl;
    cout << "r -> Request Balance" << endl;
    cout << "q -> Quit" << endl;
    cout << "> ";
}

void start()
{

    printIntroMenu(); // display intro menu

    // wait for user input
    char menuInput;
    cin >> menuInput;

    // handle user input
    switch (menuInput)
    {
    case 'l':
        login();
        break;
    case 'c':
        createAccount();
        break;
    case 'q':
        exit(0);
        break;
    default:
        cout << "Invalid input. Please try again." << endl;
        start();
    }
}

void createAccount()
{
    // create new bank account
    BankAccount newAccount;
    cout<< "Enter a new user ID: ";
    cin>>newAccount.userID;
    cout<< "Enter a new password: ";
    cin>> newAccount.password;
    newAccount.balance = 0.0;

    // add and update new account to vector
    accounts.push_back(newAccount);

    cout<< "Account created successfully." << endl;

    // go back to start menu
    start();
}

void requestBalance(int accountIndex)
{
    // retrieve balance value from accounts vector
    cout << "Your current balance is Rs." << accounts[accountIndex].balance << endl;
}

void depositMoney(int accountIndex)
{
    double amount;
    cout << "Enter the amount you want to deposit: Rs.";
    cin >> amount;
    accounts[accountIndex].balance += amount; // updating the balance in accounts vector by adding the money
    cout << "Successfully deposited Rs." << amount << endl;
}

void withdrawMoney(int accountIndex)
{
    double amount;
    cout << "Enter the amount you want to withdraw: Rs.";
    cin >> amount;
    if (amount > accounts[accountIndex].balance)
    {
        cout << "Withdrawal failed. Insufficient funds." << endl;
    }
    else
    {
        accounts[accountIndex].balance -= amount; // updating the balance in accounts vector
        cout << "Successfully withdrew Rs." << amount << endl;
    }
}

void quit()
{
    cout << "Thank you for using our banking system. Goodbye!" << endl;
    exit(0);
}

void login()
{
    string userId, password;
    cout << "Enter your user ID: ";
    cin >> userId;
    cout << "Enter your password: ";
    cin >> password;
    // find the account with the matching user ID and password
    int accountIndex = -1;
    for (int i = 0; i < accounts.size(); i++)
    {
        if (accounts[i].userID == userId && accounts[i].password == password)
        {
            accountIndex = i;
            break;
        }
    }

    // if no account found, display error message and return to start
    if (accountIndex == -1)
    {
        cout << "Login failed. Invalid user ID or password." << endl;
        start();
        return;
    }

    // otherwise, display main menu and wait for user input
    char menuInput;
    while (true)
    {
        printMainMenu();
        cin >> menuInput;

        switch (menuInput)
        {
        case 'd':
            depositMoney(accountIndex);
            break;
        case 'w':
            withdrawMoney(accountIndex);
            break;
        case 'r':
            requestBalance(accountIndex);
            break;
        case 'q':
            quit();
        default:
            cout << "Invalid input. Please try again." << endl;
        }
    }
}