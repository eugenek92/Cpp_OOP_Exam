#pragma once
#include <string>
#include<set>
#include "HotDrinksMachine.h"

using namespace std;

class Client
{
protected:
	HotDrinksMachine* hd_machine;
public:
	Client();
	void attach(HotDrinksMachine* m);
	void ShowDrinks();
	void BuyDrink();
	
};

