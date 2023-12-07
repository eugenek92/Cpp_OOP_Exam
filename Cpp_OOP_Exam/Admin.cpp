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
	system("cls");
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
	system("cls");
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
			cout << "There no components!" << endl;
		}
	}
	else
	{
		cout << "Attach to vending machine please!" << endl;
	}
}

void Admin::DeleteComponent()
{
	system("cls");
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
		cout << "\nSelect, what drink you want to add:\n"<<
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
			d = new Capuccino(50);
			break;
		case 3:
			d = new Espresso(80);
			break;
		case 4:
			d = new ClassicTea(35);
			break;
		case 5:
			d = new GreenTea(40);
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
	system("cls");
	if (hd_machine) {
		string title;
		cout << "Enter name drink you want remove: ";
		getline(cin, title);
		if (hd_machine->DeleteDrink(title))
		{
			cout << "\nDrink successfully deleted" << endl;
		}
		else
		{
			cout << "\nDrink was not deleted" << endl;
		}
	}
	else
	{
		cout << "Attach to vending machine please!" << endl;
	}
}

void Admin::ShowRequirements()
{
	system("cls");

	cout << "Americano  | Water: 200  Coffee:5          |" << endl;
	cout << "Capuccino  | Water: 150  Coffee:5  Milk:20 |" << endl;
	cout << "Espresso   | Water: 50   Coffee:5          |" << endl;
	cout << "Classic Tea| Water: 200  Black Tea:10      |" << endl;
	cout << "Green Tea  | Water: 200  Green Tea:5       |" << endl;
}
