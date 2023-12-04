#include "HotDrinksMachine.h"
#include<iostream>
#include<iomanip>
using namespace std;

HotDrinksMachine::HotDrinksMachine() :cache(0) {}

HotDrinksMachine::~HotDrinksMachine()
{
	while (!drinks.empty())
	{
		auto tmp = drinks.begin();
		delete* tmp;
		drinks.erase(tmp);
	}
}

void HotDrinksMachine::ShowDrinks() const
{
	cout << "==========Available drinks==========" << endl;
	if (drinks.empty())
	{
		cout << "Sorry, drinks are not available for now!" << endl;
	}
	else
	{
		for (Drink* d : drinks)
		{
			cout << setw(40) << d->getTitle() << setw(10) << d->getPrice() << endl;
		}
	}
}

//operator () override

/*bool HotDrinksMachine::operator()(Drink* d)
{
	return d->getTitle() == title;
}*/

void HotDrinksMachine::AddDrink(Drink* d)
{
	if (d->getTitle()==title) 
	{
		cout << "Eror";
	}
	else 
	{
		drinks.insert(d).second;
	}
}

void HotDrinksMachine::DeleteDrink(Drink* d)
{
	auto tmp = find_if(drinks.begin(), drinks.end(), title);
	if (tmp != drinks.end())
	{
		delete* tmp;
		drinks.erase(tmp);
		cout << "Drink successfully deleted" << endl;
	}
	else
	{
		cout << "Drink was not deleted" << endl;
	}
}

void HotDrinksMachine::FindDrink(string& title)
{
	auto tmp = find_if(drinks.begin(), drinks.end(), title);
	if (tmp != drinks.end())
	{
		cout << "Serching drink: "<<*tmp<<endl;
	}
	else
	{
		cout << "Searching drink not found!" << endl;
	}
}

void HotDrinksMachine::setComponent(string& name, int n)
{
	components[name] = n;
}

void HotDrinksMachine::AddComponent(string& name, int cm)
{
	if (components.find(name) == components.end())
	{
		cout << "There no this components!" << endl;
	}
	else
	{
		components[name] += cm;
		cout << "Component successfully add!" << endl;
	}
}

void HotDrinksMachine::DeleteComponent(string& name)
{
	auto tmp = components.find(name);
	if (tmp == components.end())
	{
		cout << "There no this components!" << endl;
	}
	else
	{
		components.erase(tmp);
		cout << "Component successfully deleted!" << endl;
	}
}

void HotDrinksMachine::ShowComponents() const
{
	cout << "Components: " << endl;
	if (components.empty())
	{
		cout << "Ñomponents are missing!" << endl;
	}
	else
	{
		for (auto& cm : components)
		{
			cout << left << setw(40) << cm.first << setw(10) << cm.second << endl;
		}
	}
}



