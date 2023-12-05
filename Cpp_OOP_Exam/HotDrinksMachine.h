#pragma once
#include <string>
#include<set>
#include "Drink.h"
using namespace std;

typedef set<Drink*>Drinks;
string& title;


class HotDrinksMachine
{
	Drinks drinks;
	Components components;
	int cache;
public:
	HotDrinksMachine();
	~HotDrinksMachine();
	void ShowDrinks() const;
	//bool operator()(Drink* d);
	void AddDrink(Drink* d);
	void DeleteDrink(Drink* d);
	Drink* FindDrink(string& title);
	void setComponent(string& name, int n);
	void AddComponent(string& name, int cm);
	void DeleteComponent(string& name);
	void ShowComponents()const;
	void SellDrink(string& title, int& money);

};

