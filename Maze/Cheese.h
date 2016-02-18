#pragma once
#include "Item.h"

ref class Cheese :public Item
{
public:
	Cheese(int row, int col) :Item(row, col) {
		setIcon();
	};
	void setIcon() override
	{
		myIcon = gcnew System::Drawing::Icon("cheese.ico");
		
	}
};
