// Banking System
#include<iostream>
#include<vector>
#include<fstream>
#include<cstdlib>
#include<map>
using namespace std;

#define MIN_BALANCE 500
#define ll long long int
class InsufficientFunds{};

class Account {
private:
    ll accountNumber;
    string firstName;
    string lastName;
    float balance;
    // for automatically assign account number using static data member
    static ll NextAccountNumber; // only declared for define -> must be explicitly define outside of the class
public:
    Account() {}; //default constructor
    Account(string fname, string lname, float balance); //parameterized constructor
    // getter functions
    ll getAccNo() {return accountNumber;}
    string getFirstName() {return firstName;}
    string getLastName() {return lastName;}
    // above three methods which return AccNo, names
    // which are immutable data cause once assigned account number these are can't be modified
    float getBalance() {return balance;}

    void Deposit(float amount);
    void Withdraw(float amount);
    // to accessing the static data members I have two function static getter and static setter
    static void setLastAccountNumber(ll accountNumber);
    static ll getLastAccountNumber();
    
    // for saving and retieving the files
    // output stream-> used to create file and write data to files
    friend ofstream &operator<<(ofstream &ofs, Account &acc);
    // input stream-> used to reads data from files and displays it.
    friend ifstream &operator>>(ifstream &ifs, Account &acc);
    // output stream-> can write sequences of characters and represent other kinds of data 
    friend ostream &operator<<(ostream &os, Account &acc);
};

// without define explicitly Static data member -> cannot be access
// when we try to access without define give a compiler error(undefined reference to Account::NextAccountNumber) 
ll Account::NextAccountNumber = 9283101930; // defining static data member

class Bank { // Bank will have collection of accounts
private:
    map<ll, Account> accounts;
public:
    Bank(); // default constructor
    Account OpenAccount(string fname, string lname, float balance);
    Account BalanceEnquiry(ll accountNumber);
    Account Deposit(ll accountNumber, float amount);
    Account Withdraw(ll accountNumber, float amount);
    void CloseAccount(ll accountNumber);
    void ShowAllAccounts();
    ~Bank(); // destructor
};

int main() {
    Bank b;
    Account acc;

    int choice;
    string fname, lname;
    ll accountNumber;
    float balance;
    float amount;
    cout<<"***Banking System***"<<endl;
    do {
        cout<<"\n\tSelect one option below ";
        cout<<"\n\t1 Open an Account";
        cout<<"\n\t2 Balance Enquiry";
        cout<<"\n\t3 Deposite";
        cout<<"\n\t4 Withdrawal";
        cout<<"\n\t5 Close an Account";
        cout<<"\n\t6 Show All Accounts";
        cout<<"\n\t7 Quit";
        cout<<"\n\tEnter your choice: ";
        cin>>choice;
        switch(choice) {
            case 1:
                cout<<"Enter First Name: ";
                cin>>fname;
                cout<<"Enter Last Name: ";
                cin>>lname;
                cout<<"Enter initial Balance: ";
                cin>>balance;
                acc = b.OpenAccount(fname, lname, balance);
                cout<<endl<<"Congratulations Account is created"<<endl;
                cout<<acc;
                break;
                
            case 2:
                cout<<"Enter Account Number: ";
                cin>>accountNumber;
                acc = b.BalanceEnquiry(accountNumber);
                cout<<endl<<"Your Account Details"<<endl;
                cout<<acc;
                break;
            case 3:
                cout<<"Enter Account Number: ";
                cin>>accountNumber;
                cout<<"Enter Balance: ";
                cin>>amount;
                acc = b.Deposit(accountNumber, amount);
                cout<<endl<<"Amount is Deposited"<<endl;
                cout<<acc;
                break;
            case 4:
                cout<<"Enter Account Number: ";
                cin>>accountNumber;
                cout<<"Enter Balance: ";
                cin>>amount;
                acc = b.Withdraw(accountNumber, amount);
                cout<<endl<<"Amount Withdrawn"<<endl;
                cout<<acc;
                break;
            case 5:
                cout<<"Enter Account Number: ";
                cin>>accountNumber;
                b.CloseAccount(accountNumber);
                cout<<endl<<"Account is Closed"<<endl;
                cout<<acc;
            case 6:
                b.ShowAllAccounts();
                break;
            case 7: 
                break;
            default:
                cout<<"\nEnter correct choice";
                exit(0);
        }
    }while(choice != 7);

    return 0;
}

Account::Account(string fname, string lname, float balance) {
    NextAccountNumber++;
    accountNumber = NextAccountNumber;
    firstName = fname;
    lastName = lname;
    this->balance = balance;
}

void Account::Deposit(float amount) {
    balance += amount;
}

void Account::Withdraw(float amount) {
    if(balance-amount < MIN_BALANCE) {
        throw InsufficientFunds();
    }
    balance -= amount;
}

void Account::setLastAccountNumber(ll accountNumber) {
    NextAccountNumber = accountNumber;
}

ll Account::getLastAccountNumber() {
    return NextAccountNumber;
}

ofstream & operator<<(ofstream &ofs, Account &acc) {
    ofs<<acc.accountNumber<<endl;
    ofs<<acc.firstName<<endl;
    ofs<<acc.lastName<<endl;
    ofs<<acc.balance<<endl;
    return ofs;
}

ifstream & operator>>(ifstream &ifs, Account &acc) {
    ifs>>acc.accountNumber;
    ifs>>acc.firstName;
    ifs>>acc.lastName;
    ifs>>acc.balance;
    return ifs;
}

ostream & operator<<(ostream &os, Account &acc) {
    os<<"First Name: "<<acc.getFirstName()<<endl;
    os<<"Last Name: "<<acc.getLastName()<<endl;
    os<<"Account: "<<acc.getAccNo()<<endl;
    os<<"Balance: "<<acc.getBalance()<<endl;
    return os;
}

Bank::Bank() {
    Account account;
    ifstream infile;
    infile.open("Bank.data");
    if(!infile) {
        // cout<<"Error in Opening! File Not Found!!"<<endl;
        return;
    }
    while(!infile.eof()) {
        infile>>account;
        accounts.insert(pair<ll, Account>(account.getAccNo(), account));
    }
    Account::setLastAccountNumber(account.getAccNo());
    infile.close();
}

Account Bank::OpenAccount(string fname, string lname, float balance) {
    ofstream outfile;
    Account account(fname, lname, balance);
    accounts.insert(pair<ll, Account>(account.getAccNo(), account));

    // ios::trunc (short for truncate) means that when the file is opened, the old contents are immediately removed. Again, this is only meaningful if the file is also open for output.
    outfile.open("Bank.data", ios::trunc);

    map<ll, Account>:: iterator itr;
    for(itr = accounts.begin(); itr != accounts.end(); itr++) {
        outfile<<itr->second;
    }
    outfile.close();
    return account;
}

Account Bank::BalanceEnquiry(ll accountNumber) {
    map<ll, Account>:: iterator itr = accounts.find(accountNumber);
    return itr->second;
}

Account Bank::Deposit(ll accountNumber, float amount) {
    map<ll, Account>:: iterator itr = accounts.find(accountNumber);
    itr->second.Deposit(amount);
    return itr->second;
}

Account Bank::Withdraw(ll accountNumber, float amount) {
    map<ll, Account>:: iterator itr = accounts.find(accountNumber);
    itr->second.Withdraw(amount);
    return itr->second;
}

void Bank::CloseAccount(ll accountNumber) {
    map<ll, Account>::iterator itr = accounts.find(accountNumber);
    cout<<"Account Deleted"<<itr->second;
    accounts.erase(accountNumber);
}

void Bank::ShowAllAccounts() {
    map<ll, Account>::iterator itr;
    if(itr == accounts.end()) {
        cout<<"No accounts!!"<<endl;
    }
    for(itr = accounts.begin(); itr != accounts.end(); itr++) {
        cout<<"Account "<<itr->first<<endl<<itr->second<<endl;
    }
}

Bank::~Bank() {
    ofstream outfile;
    outfile.open("Bank.data", ios::trunc);
    map<ll, Account>::iterator itr;
    for(itr = accounts.begin(); itr != accounts.end(); itr++) {
        outfile<<itr->second;
    }
    outfile.close();
}

