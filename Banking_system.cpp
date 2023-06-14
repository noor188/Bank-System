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

public:
	Account();
	Account(string firtsName, string lastName, float balance);
	void Deposit(float amount);
	void Withdraw(float amount);
};

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
	cout << "*** Welcome to our Banking System ***" << endl;
	cout << "Please enter your first name ___";
	cin >> fName;
	cout << "Welcome " << fName << endl;
}