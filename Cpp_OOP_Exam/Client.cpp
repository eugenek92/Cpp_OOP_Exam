#include "Client.h"
#include<iostream>
#include<iomanip>

using namespace std;

Client::Client():hd_machine(nullptr) {}

void Client::attach(HotDrinksMachine* m)
{
	hd_machine = m;
}

void Client::ShowDrinks()
{
	if (hd_machine)
	{
		hd_machine->ShowDrinks();
	}
	else
	{
		cout << "Drinks missing" << endl;
	}
}

void Client::BuyDrink()
{
	string title;
	int money;
	cout << "Buy drink\nName: ";
	getline(cin, title);
	cout << "\nMoney: ";
	cin >> money;
	cin.ignore();

	if (hd_machine)
	{
		hd_machine->SellDrink(title, money);
	}
	else
	{
		cout << "Attach to vending machine please!" << endl;
	}
}
