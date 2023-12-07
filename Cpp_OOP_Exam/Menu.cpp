#include <iostream>
#include <string>
#include "Admin.h"
#include "Client.h"
#include <fstream>

using namespace std;

void Logo();

void Menu()
{
	//Logo();

	Admin jack;
	Client jane;
	HotDrinksMachine hdm;
	jack.attach(&hdm);
	jane.attach(&hdm);
	 
	int choice;
	bool exitProgram = false;
	bool exitMenu = false;
	int password;

	hdm.ReadFromFile(hdm);

	do {

		system("cls");
		cout << "\n==========Hot Drink's Machine==========" << endl;
		cout << "\t\t1.Admin;\n\t\t2.Client;\n\t\t0.Exit"<<endl;
		cin >> choice;
		cin.ignore();

		switch (choice)
		{
		case 1:
			system("cls");
			cout << "If you administrator,please enter your password: " << endl;
			cin >> password;
			switch (password) {
			case 1234:
				do
				{
					cout << "\nADMINISTRATOR MENU OPTIONS" << endl;
					cout << "1.Show drink list;\n2.Show components;\n3.Add drink;" <<
						"\n4.Remove drink;\n5.Set components;\n6.Add components;" <<
						"\n7.Remove component;\n0.Exit\0" << endl;
					cin >> choice;
					cin.ignore();
					switch (choice)
					{
					case 1:
						jack.ShowDrinks();
						break;
					case 2:
						jack.ShowComponents();
						break;
					case 3:
						jack.ShowRequirements();
						jack.AddDrink();
						break;
					case 4:
						jack.DeleteDrink();
						break;
					case 5:
						jack.setComponent();
						hdm.WriteToFile(hdm);
						break;
					case 6:
						jack.AddComponent();
						break;
					case 7:
						jack.DeleteComponent();
						break;
					case 0:
						exitMenu = true;
						break;
					}
				} while (exitMenu != true);
			}
			break;
		case 2:
			do
			{
				cout << "\nCLIENT MENU OPTIONS" << endl;
				cout << "1.Show drink list;\n2.Buy drink;\n0.Exit\0" << endl;
				cin >> choice;
				cin.ignore();
				switch (choice)
				{
				case 1:
					jack.ShowDrinks();
					break;
				case 2:
					jack.ShowDrinks();
					jane.BuyDrink();
					break;
				case 0:
					exitMenu = true;
					break;
				}
			} while (exitMenu != true);
			break;
		case 0:
			exitProgram = true;
			break;
		}
	} while (exitProgram != true);



}
