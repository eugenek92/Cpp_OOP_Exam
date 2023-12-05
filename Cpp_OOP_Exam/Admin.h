#pragma once
#include <string>
#include<set>
#include "Client.h"

class Admin:public Client
{
public:
	void ShowComponents();
	void setComponents();
	void AddComponents();
};

