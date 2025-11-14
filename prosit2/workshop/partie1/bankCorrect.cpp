#include <iostream>

class BankAccount {
    private:
        double balance;
    public:
        BankAccount(double _balance) : balance(_balance) {}
        bool depot(double _balance) {
            if(_balance<=0){return false;}
            this->balance+=_balance;
            return true;
        }
        bool retire(double _balance) {
            if(_balance<=0){return false;}
            if (_balance<=this->balance) {
                this->balance-=_balance;
                return true;
            }
            return false;
        }
        double getSolde() {return this->balance;}
};

class Transaction {
private:
    BankAccount* from;
    BankAccount* to;
    double amount;
public:
    Transaction(BankAccount* from, BankAccount* to, double amount) : from(from), to(to), amount(amount) {}

    bool execute() {
        if (from->retire(amount)) {if(to->depot(amount)){return true;}}
        return false;
    }
};


int main() {
    BankAccount* account1 = new BankAccount(1000.0);
    BankAccount* account2 = new BankAccount(500.0);


    Transaction* transaction = new Transaction(account1, account2, 500.0);
    bool res = transaction->execute();
    if (res) {
        std::cout << "Transaction successful" << std::endl;
    }
    else {
        std::cout << "Transaction failed" << std::endl;
    }

    std::cout << account1->getSolde() << std::endl;
    std::cout << account2->getSolde() << std::endl;
    delete account1;
    delete account2;

    account1 = new BankAccount(1000.0);
    account2 = new BankAccount(500.0);
    transaction = new Transaction(account1, account2, 5000.0);

    res = transaction->execute();
    if (res) {
        std::cout << "Transaction successful" << std::endl;
    }
    else {
        std::cout << "Transaction failed" << std::endl;
    }

    std::cout << account1->getSolde() << std::endl;
    std::cout << account2->getSolde() << std::endl;

    return 0;
}
