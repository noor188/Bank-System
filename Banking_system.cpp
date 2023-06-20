#include <iostream>
#include <map>
using namespace std;

#define MIN_BALANCE 100;
class InsufficientFunds
{
};
class Account
{
private:
	long accountNumber;
	string firstName;
	string lastName;
	float balance;
	static long NextAccountNumber;

public:
	Account(){};
	Account(string firtsName, string lastName, float balance);
	long getAccountNumber();
	string getFirstName();
	string getLastName();
	float getBalance();
	static long getLastAccountNumber();
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
	/* here */
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
	float withdraw;
	Bank bank;
	Account acc2;

	cout << "*** Welcome to our Banking System ***" << endl;
	cout << "Please enter your first name ____ ";
	cin >> fName;
	cout << "Please enter your last name _____  ";
	cin >> lName;
	cout << "Please enter your balance  _____  ";
	cin >> balance;
	cout << "Welcome " << fName << endl;
	Account acc(fName, lName, balance);
	/*cout << "Account number " << acc.getAccountNumber() << endl;
	cout << "First name " << acc.getFirstName() << endl;
	cout << "Last name " << acc.getLastName() << endl;
	cout << "Balance " << acc.getBalance() << endl;
	cout << "Please enter deposit amount ___  ";
	cin >> deposit;
	acc.Deposit(deposit);
	cout << "Balance after deposit " << acc.getBalance() << endl;
	cout << "please enter withdraw amount ___";
	cin >> withdraw;
	acc.Withdraw(withdraw);
	cout << "balance after" << acc.getBalance() << endl;
	cout << "next account number is " << acc.getLastAccountNumber() << endl;*/
	acc2 = bank.openAccount(fName, lName, balance);
	cout << "first name : " << acc2.getFirstName();
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

void Account::Withdraw(float amount)
{
	/*if(balance-amount<MIN_BALANCE )
  {throw InsufficientFunds();}*/

	balance -= amount;
}

long Account::getLastAccountNumber() { return NextAccountNumber; }

Bank::Bank()
{
}

Account Bank::openAccount(string firstName, string lastName, float balance)
{
	Account account(firstName, lastName, balance);
	accounts.insert(pair<long, Account>(account.getAccountNumber(), account));
	return account;
}