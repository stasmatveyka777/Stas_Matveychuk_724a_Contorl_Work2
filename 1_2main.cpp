#include <iostream>
using namespace std;

struct BankAccount {
    string ownerName;
    string accountNumber;
    double balance;
};

void deposit(BankAccount& account, double amount) {
    if (amount > 0) {
        account.balance += amount;
        cout << "Deposit successful.\n";
    } else {
        cout << "Invalid deposit amount.\n";
    }
}

void withdraw(BankAccount& account, double amount) {
    if (amount > 0 && amount <= account.balance) {
        account.balance -= amount;
        cout << "Withdrawal successful.\n";
    } else {
        cout << "Invalid or insufficient funds.\n";
    }
}

void printBalance(const BankAccount& account) {
    cout << "Account owner: " << account.ownerName << endl;
    cout << "Account number: " << account.accountNumber << endl;
    cout << "Current balance: $" << account.balance << endl;
}

int main() {
    BankAccount account;

    cout << "Enter owner name: ";
    getline(cin, account.ownerName);
    cout << "Enter account number: ";
    getline(cin, account.accountNumber);
    cout << "Enter initial balance: ";
    cin >> account.balance;

    int choice;
    double amount;

    do {
        cout << "\n1. Deposit\n2. Withdraw\n3. Show balance\n4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter amount to deposit: ";
            cin >> amount;
            deposit(account, amount);
            break;
            case 2:
                cout << "Enter amount to withdraw: ";
            cin >> amount;
            withdraw(account, amount);
            break;
            case 3:
                printBalance(account);
            break;
            case 4:
                cout << "Goodbye!\n";
            break;
            default:
                cout << "Invalid option.\n";
        }

    } while (choice != 4);

    return 0;
}
