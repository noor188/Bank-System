#include <iostream>
#include <map>
using namespace std;

class Account
{
private:
	long accountNumber;
	string firstName;
	string lastName;
	float balance;
	static long NextAccountNumber;

public:
	Account();
	Account(string firtsName, string lastName, float balance);
	long getAccountNumber();
	string getFirstName();
	string getLastName();
	float getBalance();
	void Deposit(float amount);
	void Withdraw(float amount);
};

long Account ::NextAccountNumber = 0;

class Bank
{
private:
	map<long, Account> accounts;

public:
	Bank();
	Account openAccount(string firstName, string lastName, float balance);
	void closeAccount(long accountNumber);
	void Deposit(long accountNumber, float amount);
	void Withdraw(long accountNumber, float amount);
	Account balanceEnquiry(long accountNumber);
};

int main()
{
	string fName;
	string lName;
	float balance;
	float deposit;

	cout << "*** Welcome to our Banking System ***" << endl;
	cout << "Please enter your first name ___  ";
	cin >> fName;
	cout << "Please enter your last name ___  ";
	cin >> lName;
	cout << "Please enter your balance  ___  ";
	cin >> balance;
	cout << "Welcome " << fName << endl;
	Account acc(fName, lName, balance);
	cout << "Account number " << acc.getAccountNumber() << endl;
	cout << "First name " << acc.getFirstName() << endl;
	cout << "Last name " << acc.getLastName() << endl;
	cout << "Balance " << acc.getBalance() << endl;
	cout << "Please enter deposit amount ___  ";
	cin >> deposit;
	acc.Deposit(deposit);
	cout << "Balance after deposit " << acc.getBalance() << endl;
}

Account ::Account(string fName, string lName, float balance)
{
	firstName = fName;
	lastName = lName;
	NextAccountNumber++;
	accountNumber = NextAccountNumber;
	this->balance = balance;
}

long Account::getAccountNumber() { return accountNumber; }

string Account::getFirstName() { return firstName; }

string Account::getLastName() { return lastName; }

float Account::getBalance() { return balance; }

void Account::Deposit(float amount) { balance += amount; }