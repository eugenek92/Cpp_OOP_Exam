#include "Drink.h"
#include<string>

Drink::Drink(string title, int price):title(title), price(price) {}

int Drink::getPrice() const
{
	return price;
}

void Drink::setPrice(int price)
{
	this->price = price;
}

const string& Drink::getTitle() const
{
	return title;
}

Components Drink::getComponents() const
{
	return components;
}

//Coffee and tea

Americano::Americano(int price):Drink("Americano",price)
{
	components["Water"] = 200;
	components["Coffee"] = 5;
}

Capuccino::Capuccino(int price) :Drink("Capuccino", price)
{
	components["Water"] = 150;
	components["Coffee"] = 5;
	components["Milk"] = 20;
}

Espresso::Espresso(int price) :Drink("Espresso", price)
{
	components["Water"] = 50;
	components["Coffee"] = 5;
}

ClassicTea::ClassicTea(int price):Drink("Classic Tea", price)
{
	components["Water"] = 200;
	components["Black Tea"] = 10;
}

GreenTea::GreenTea(int price) :Drink("Green Tea", price)
{
	components["Water"] = 200;
	components["Green Tea"] = 5;
}
