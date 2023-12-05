#include "Admin.h"
#include<iostream>
#include<iomanip>

using namespace std;

void Admin::ShowComponents()
{
	if (hd_machine)
	{
		hd_machine->ShowComponents();
	}
	else
	{
		cout << "Attach to vending machine please!" << endl;
	}
}

void Admin::setComponents()
{
	if (hd_machine)
	{
		string name;
		int cm;
		cout << "Set component\nName: ";
		getline(cin, name);
		cout << "Quantity: ";
		cin >> cm;
		cin.ignore();
		hd_machine->setComponent(name, cm);
	}
	else
	{
		cout << "Attach to vending machine please!" << endl;
	}
}

void Admin::AddComponents()
{
	if (hd_machine)
	{
		string name;
		int cm;
		cout << "Add components\nName: ";
		getline(cin, name);
		cout << "Quantity: ";
		cin >> cm;
		cin.ignore();
		/*if (hd_machine->AddComponent(name, cm)
		{
			cout << "Success!" << endl;
		}
		else
		{
			cout << "Fail!" << endl;
		}*/
	}
	else
	{
		cout << "Attach to vending machine please!" << endl;
	}
}
