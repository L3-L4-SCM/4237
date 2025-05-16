
~
~
~
~
~
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

class BankAccount 
{
private:
    int accNo;
    string name;
    double balance;

public:
    BankAccount(int acc, string n, double b) 
    {
        accNo = acc;
        name = n;
        balance = b;
    }

    int getAccNo() const 
    {
        return accNo;
    }

    void deposit(double amount) 
    {
        if (amount > 0) 
        {
            balance += amount;
            cout << "Deposited $" << amount << " successfully.\n";
        } 
        else 
        {
            cout << "Invalid deposit amount.\n";
        }
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount.\n";
        } else if (amount > balance) {
            cout << "Insufficient balance.\n";
        } else {
            balance -= amount;
            cout << "Withdrew $" << amount << " successfully.\n";
        }
    }

    void display() const {
        cout << left << setw(10) << accNo << setw(20) << name
             << "$" << fixed << setprecision(2) << balance << endl;
    }

    void showDetails() const 
    {
        cout << "\n--- Account Details ---\n";
        cout << "Account Number: " << accNo << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: $" << fixed << setprecision(2) << balance << endl;
    }
};

class BankSystem 
{
private:
    vector<BankAccount> accounts;

    BankAccount* findAccount(int accNo) 
    {
        for (auto& acc : accounts) 
        {
            if (acc.getAccNo() == accNo) 
            {
                return &acc;
            }
        }
        return nullptr;
    }

public:
    void createAccount() 
    {
        int accNo;
        string name;
        double balance;

        cout << "Enter account number: ";
        cin >> accNo;
        cin.ignore();
        cout << "Enter account holder name: ";
        getline(cin, name);
        cout << "Enter initial deposit: $";
        cin >> balance;

        accounts.emplace_back(accNo, name, balance);
        cout << "Account created successfully.\n";
    }

    void displayAllAccounts() const 
    {
        if (accounts.empty()) 
        {
            cout << "No accounts found.\n";
            return;
        }

        cout << "\n--- All Bank Accounts ---\n";
        cout << left << setw(10) << "AccNo" << setw(20) << "Name" << "Balance\n";
        cout << "-----------------------------------------\n";
        for (const auto& acc : accounts) 
        {
            acc.display();
        }
    }

    void searchAccount() 
    {
        int accNo;
        cout << "Enter account number to search: ";
        cin >> accNo;

        BankAccount* acc = findAccount(accNo);
        if (acc) {
            acc->showDetails();
        } else {
            cout << "Account not found.\n";
        }
    }

    void depositMoney() {
        int accNo;
        double amount;
        cout << "Enter account number: ";
        cin >> accNo;

        BankAccount* acc = findAccount(accNo);
        if (acc) {
            cout << "Enter amount to deposit: $";
            cin >> amount;
            acc->deposit(amount);
        } else {
            cout << "Account not found.\n";
        }
    }

    void withdrawMoney() {
        int accNo;
        double amount;
        cout << "Enter account number: ";
        cin >> accNo;

        BankAccount* acc = findAccount(accNo);
        if (acc) {
            cout << "Enter amount to withdraw: $";
            cin >> amount;
            acc->withdraw(amount);
        } else {
            cout << "Account not found.\n";
        }
    }

    void menu() {
        int choice;
        do {
            cout << "\n====== Bank Management Menu ======\n";
            cout << "1. Create Account\n";
            cout << "2. Display All Accounts\n";
            cout << "3. Search Account\n";
            cout << "4. Deposit Money\n";
            cout << "5. Withdraw Money\n";
            cout << "0. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1: createAccount(); break;

                case 2: displayAllAccounts(); break;

                case 3: searchAccount(); break;

                case 4: depositMoney(); break;

                case 5: withdrawMoney(); break;
                
                case 0: cout << "Exiting program...\n"; break;
                default: cout << "Invalid choice. Try again.\n";
            }
        } while (choice != 0);
    }
};

int main() {
    BankSystem bank;
    bank.menu();
    return 0;
}

~
~
~
~
~

