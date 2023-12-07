#include "HotDrinksMachine.h"
#include<iostream>
#include<iomanip>
#include <fstream>
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


bool HotDrinksMachine::AddDrink(Drink* d)
{

	if (FindDrink(d->getTitle()))
	{
		return false;
	}
	else
	{
		drinks.insert(d).second;
		return true;
	}
}

bool HotDrinksMachine::DeleteDrink(const string& title)
{
	auto tmp = find_if(drinks.begin(), drinks.end(), FindDrinkFunctor(title));
	if (tmp != drinks.end())
	{
		delete* tmp;
		drinks.erase(tmp);
		return true;
	}
	else
	{
		return false;
	}
}

Drink* HotDrinksMachine::FindDrink(const string& title)
{
	auto tmp = find_if(drinks.begin(), drinks.end(), FindDrinkFunctor(title));
	if (tmp != drinks.end())
	{
		return *tmp;
	}
	else
	{
		return nullptr;
	}
}

void HotDrinksMachine::setComponent(const string& name, int n)
{
	components[name] = n;
}

bool HotDrinksMachine::AddComponent(const string& name, int cm)
{
	if (components.find(name) == components.end())
	{
		return false;
	}
	else
	{
		components[name] += cm;
		return true;
	}
}

bool HotDrinksMachine::DeleteComponent(const string& name)
{
	auto tmp = components.find(name);
	if (tmp == components.end())
	{
		return false;
	}
	else
	{
		components.erase(tmp);
		return true;
	}
}

void HotDrinksMachine::ShowComponents() const
{
	cout << "Components: " << endl;
	if (components.empty())
	{
		cout << "Components are missing!" << endl;
	}
	else
	{
		for (auto& cm : components)
		{
			cout << left << setw(40) << cm.first << setw(10) << cm.second << endl;
		}
	}
}

void HotDrinksMachine::SellDrink(const string& title, int& money)
{
	Drink* d = FindDrink(title);
	if (!d)
	{
		cout << "Illegal drink!" << endl;
	}
	int price = d->getPrice();
	if (price > money)
	{
		cout << "Not enough money!" << endl;
	}
	const Components& cm = d->getComponents();
	for (auto& p : cm)
	{
		auto tmp = this->components.find(p.first);
		if (tmp == this->components.end())
		{
			cout << "Absent ingredient!" << endl;
		}
		if (tmp->second < p.second)
		{
			cout << "Not enough ingredient!" << endl;
		}
	}
	for (auto& p : cm)
	{
		auto tmp = this->components.find(p.first);
		tmp->second -= p.second;
	}
	money -= price;
	this->cache += price;
	cout << "Action is succesfull!" << endl;
}

void HotDrinksMachine::WriteToFile(HotDrinksMachine& read)
{
	ofstream out("HDMachine.txt");
	out << read;
	out.close();
}

/*void HotDrinksMachine::ReadFromFile(HotDrinksMachine& read)
{
	ifstream in("HDMachine.txt");
	in >> read;
	in.close();
}*/


ostream& operator << (ostream& out, const HotDrinksMachine& d)
{
	for (auto& cm : d.components)
	{
		out <<  cm.first <<" : " << cm.second << endl;
	}
	//out << "|" << endl;
	return out;
}

/*istream& operator >> (istream& in, HotDrinksMachine& d)
{
	string end = "|";
	
	return in;
}*/

