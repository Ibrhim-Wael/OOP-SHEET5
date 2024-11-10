#include <iostream>
#include <string>
using namespace std;

class BankAccount{
private:
   int AccountId;
   double balance;
public:
   BankAccount(int id,int balance_){AccountId=id;balance=balance_;}
   void deposit(double n){
    balance+=n;
   }
   double getBalance(){
    return balance;
   }
   friend class Transaction;
};
class Transaction {
private:
    BankAccount &toAccount;
    BankAccount &fromAccount;
    double amount;
    bool completed = false;
public:
    Transaction(BankAccount &from, BankAccount &to, double what)
        : toAccount(to), fromAccount(from), amount(what) {}

    void execute() {
        if (fromAccount.balance>=amount) {
            fromAccount.balance-=amount;
            toAccount.deposit(amount);
            completed = true;
        } else {
            cout << "Transaction can't be done." << endl;
        }
    }

    void cancel() {
        if (completed) {
            fromAccount.deposit(amount);
            toAccount.balance-=amount;
            completed = false;
        } else {
            cout << "The last transaction was not completed." << endl;
        }
    }
};


int main(){
BankAccount ibrahim(1,8000);
BankAccount basil(2,3000);
Transaction trans1(basil,ibrahim,2500);
trans1.execute();
cout<<ibrahim.getBalance()<<endl;//2500+8000=10500
cout<<basil.getBalance()<<endl;//3000-2500=500
}
