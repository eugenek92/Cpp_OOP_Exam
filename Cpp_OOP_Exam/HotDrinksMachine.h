#pragma once
#include <string>
#include<set>
#include "Drink.h"
using namespace std;

typedef set<Drink*>Drinks;

class HotDrinksMachine
{
	friend class Admin;
	Drinks drinks;
	Components components;
	int cache;

	class FindDrinkFunctor {
		const string& title;
	public:
		FindDrinkFunctor(const string& title):title(title){}
		bool operator()(const Drink* d)
		{
			return d->getTitle() == title;
		}
	};
	
public:
	HotDrinksMachine();
	~HotDrinksMachine();
	void ShowDrinks() const;
	bool AddDrink(Drink* d);
	bool DeleteDrink(const string& title);
	Drink* FindDrink(const string& title);
	void setComponent(const string& name, int n);
	bool AddComponent(const string& name, int cm);
	bool DeleteComponent(const string& name);
	void ShowComponents()const;
	void SellDrink(const string& title, int& money);

	void WriteToFile(HotDrinksMachine& read);
	void ReadFromFile(HotDrinksMachine& read);

	friend ostream& operator << (ostream& out, const HotDrinksMachine& d);
	friend istream& operator >> (istream& in, HotDrinksMachine& d);

};

