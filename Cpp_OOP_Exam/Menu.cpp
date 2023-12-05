#include <iostream>
#include <string>
#include "Admin.h"
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
					"\n.7.Remove component;\n0.Exit\0" << endl;
				cin >> choice;
				cin.ignore();
				switch (choice)
				{
				case 1:
					&Admin::showDrinks;
					break;
				case 2:
					&Admin::ShowComponents;
					break;
				case 3:
					//add drinks
					break;
				case 4:
					//remove drinks
					break;
				case 5:
					&Admin::setComponents;
					break;
				case 6:
					&Admin::AddComponents;
					break;
				case 7:
					//remove components
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