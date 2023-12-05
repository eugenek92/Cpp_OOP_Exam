#pragma once
#include <string>
#include<map>
using namespace std;

typedef map<string, int>Components;

class Drink
{
	friend class Admin;
protected:
	string title;
	int price;
	Components components;
public:
	Drink(string title, int price);
	
	int getPrice() const;
	void setPrice(int price);
	const string& getTitle() const;
	Components getComponents() const;
};

//Coffee and tea

class Americano :public Drink
{
public:
	Americano(int price);
};

class Capuccino : public Drink
{
public:
	Capuccino(int price);
};

class Espresso : public Drink
{
public:
	Espresso(int price);
};

class ClassicTea : public Drink
{
public:
	ClassicTea(int price);
};

class GreenTea : public Drink
{
public:
	GreenTea(int price);
};
