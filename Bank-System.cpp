#include <iostream>
#include <map>
using namespace std;

Class Account
{
	int accountNumber;
	string firstName;
	string lastName;
	float balance;

	Account();
};

CLass Bank
{
	map<long, Account> accounts;
	Bank();
}

int main()
{
	Bank bank;
}