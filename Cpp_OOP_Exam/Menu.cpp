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
	bool exit = false;

	do {

		cout << "1.Admin;\n2.Client;\n0.Exit"<<endl;
		cin >> choice;
		cin.ignore();

		switch (choice)
		{
		case 1:
			do 
			{
				cout << "\n1.Show drink list;\n2.Show components;\n3.Add drink;"<<
					"\n4.Remove drink;\n5.Set components;\n6.Add components;"<<
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
					jack.AddDrink();
					break;
				case 4:
					jack.DeleteDrink();
					break;
				case 5:
					jack.setComponent();
					break;
				case 6:
					jack.AddComponent();
					break;
				case 7:
					jack.DeleteComponent();
					break;
				case 0:
					exit = true;
					break;
				}
			} while (exit != true);
			break;
		case 2:
			do
			{
				cout << "\n1.Show drink list;\n2.Buy drink;\n0.Exit\0" << endl;
				cin >> choice;
				cin.ignore();
				switch (choice)
				{
				case 1:
					jane.ShowDrinks();
					break;
				case 2:
					jane.BuyDrink();
					break;
				case 0:
					exit = true;
					break;
				}
			} while (exit != true);
			break;
		case 0:
			exit = true;
			break;
		}
	} while (exit != true);



}