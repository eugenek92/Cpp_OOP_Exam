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

void Admin::setComponent()
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

void Admin::AddComponent()
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
		if (hd_machine->AddComponent(name, cm))
		{
			cout << "Component successfully add!" << endl;
		}
		else
		{
			cout << "There no this components!" << endl;
		}
	}
	else
	{
		cout << "Attach to vending machine please!" << endl;
	}
}

void Admin::DeleteComponent()
{
	if (hd_machine)
	{
		string name;
		cout << "Delete component\nName: ";
		getline(cin, name);
		if (!hd_machine->DeleteComponent(name))
		{
			cout << "There no this components!" << endl;
		}
		else
		{
			cout << "Component successfully deleted!" << endl;
		}
	}
	else
	{
		cout << "Attach to vending machine please!" << endl;
	}
}

void Admin::AddDrink()
{
	if (hd_machine)
	{
		cout << "Select, what drink you want to add:\n"<<
			"1.Americano\n2.Capuccino\n3.Espresso\n4.Classic Tea\n5.Green Tea" << endl;
		int choice;
		cin >> choice;
		cin.ignore();
		Drink* d = nullptr;
		switch (choice)
		{
		case 1:
			d = new Americano(70);
			break;
		case 2:
			d = new Capuccino(70);
			break;
		case 3:
			d = new Espresso(70);
			break;
		case 4:
			d = new ClassicTea(70);
			break;
		case 5:
			d = new GreenTea(70);
			break;
		default:
			cout << "Something wrong!" << endl;
			break;
		}
		if (d)
		{
			if (hd_machine->AddDrink(d))
			{
				cout << "Succes!" << endl;
			}
			else
			{
				cout << "Fail! Drink already presents!" << endl;
				delete d;
			}
		}
	}
	else
	{
		cout << "Attach to vending machine please!" << endl;
	}
}

void Admin::DeleteDrink()
{
	if (hd_machine) {
		string title;
		cout << "Enter name drink you want remove: ";
		getline(cin, title);
		if (hd_machine->DeleteDrink(title))
		{
			cout << "Drink successfully deleted" << endl;
		}
		else
		{
			cout << "Drink was not deleted" << endl;
		}
	}
	else
	{
		cout << "Attach to vending machine please!" << endl;
	}
}
