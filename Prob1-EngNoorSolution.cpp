#include <iostream>
using namespace std;


class BankAccount {
private:
    int accountID;
    double balance;

public:
    BankAccount(int accountID_, double balance_){
        accountID = accountID_;
        balance = balance_;
    }

    void deposit(double amount) {
        balance += amount;
    }

    double getBalance() const {
        return balance;
    }

    friend class Transaction;  // Allow Transaction Class to access private members
};

class Transaction {
private:
    BankAccount& fromAccount;
    BankAccount& toAccount;
    double amount;
    bool completed;

public:
    Transaction(BankAccount& fromAccount_, BankAccount& toAccout_, double amount_)
        : fromAccount(fromAccount_), toAccount(toAccout_), amount(amount_), completed(false) {}

    void execute() {
        if (fromAccount.balance >= amount) {
            fromAccount.balance -= amount;
            toAccount.balance += amount;
            completed = true;
            cout << "Transaction executed successfully." << endl;
        } else {
            cout << "Transaction failed: Insufficient funds." << endl;
        }
    }

    void cancel() {
        if (completed) {
            fromAccount.balance += amount;
            toAccount.balance -= amount;
            completed = false;
            cout << "Transaction canceled successfully." << endl;
        } else {
            cout << "Transaction cannot be canceled: It was not completed." << endl;
        }
    }
};

int main() {
    // Create two accounts with initial balances
    BankAccount account1(1, 500.0);
    BankAccount account2(2, 300.0);

    cout << "Initial Balances:\n";
    cout << "Account 1 Balance: $" << account1.getBalance() << endl;
    cout << "Account 2 Balance: $" << account2.getBalance() << endl;
    cout << "***********************************************************************" << endl;

    // Create a transaction to transfer money from account1 to account2
    Transaction transaction(account1, account2, 100.0);

    // Execute the transaction
    transaction.execute();
    cout << "\nBalances after executing the transaction:\n";
    cout << "Account 1 Balance: $" << account1.getBalance() << endl;
    cout << "Account 2 Balance: $" << account2.getBalance() << endl;
    cout << "***********************************************************************" << endl;

    // Cancel the transaction
    transaction.cancel();
    cout << "\nBalances after canceling the transaction:\n";
    cout << "Account 1 Balance: $" << account1.getBalance() << endl;
    cout << "Account 2 Balance: $" << account2.getBalance() << endl;
    cout << "***********************************************************************" << endl;


    return 0;
}
