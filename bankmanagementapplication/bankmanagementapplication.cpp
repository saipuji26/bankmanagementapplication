#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    string name;
    double balance;

public:
    BankAccount() {
        accountNumber = 0;
        name = "";
        balance = 0.0;
    }

    BankAccount(int accNo, string n, double bal) {
        accountNumber = accNo;
        name = n;
        balance = bal;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    void createAccount() {
        cout << "\nEnter Account Number: ";
        cin >> accountNumber;

        cin.ignore();
        cout << "Enter Customer Name: ";
        getline(cin, name);

        cout << "Enter Initial Deposit: ";
        cin >> balance;

        cout << "\nAccount created successfully!\n";
    }

    void deposit() {
        double amount;

        cout << "Enter amount to deposit: ";
        cin >> amount;

        if (amount > 0) {
            balance += amount;
            cout << "Amount deposited successfully!\n";
            cout << "Current Balance: " << balance << endl;
        }
        else {
            cout << "Invalid amount!\n";
        }
    }

    void withdraw() {
        double amount;

        cout << "Enter amount to withdraw: ";
        cin >> amount;

        if (amount <= 0) {
            cout << "Invalid amount!\n";
        }
        else if (amount > balance) {
            cout << "Insufficient balance!\n";
        }
        else {
            balance -= amount;
            cout << "Withdrawal successful!\n";
            cout << "Current Balance: " << balance << endl;
        }
    }

    void display() {
        cout << "\n----- Account Details -----\n";
        cout << "Account Number : " << accountNumber << endl;
        cout << "Customer Name  : " << name << endl;
        cout << "Balance        : " << balance << endl;
    }

    void saveToFile() {
        ofstream file("accounts.txt", ios::app);

        if (file.is_open()) {
            file << accountNumber << endl;
            file << name << endl;
            file << balance << endl;
            file.close();
        }
    }
};

int main() {
    BankAccount account;
    int choice;

    do {
        cout << "\n================================\n";
        cout << "      BANK MANAGEMENT SYSTEM\n";
        cout << "================================\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Check Balance / Account Details\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            account.createAccount();
            account.saveToFile();
            break;

        case 2:
            account.deposit();
            break;

        case 3:
            account.withdraw();
            break;

        case 4:
            account.display();
            break;

        case 5:
            cout << "\nThank you for using Bank Management System!\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}