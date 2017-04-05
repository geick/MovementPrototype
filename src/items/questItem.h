#pragma once
#include "item.h"
class questItem : public item
{
public:
	questItem(string name_, typeOfItem itemType_, int quantity = 1);
	~questItem();
	void use();
};

