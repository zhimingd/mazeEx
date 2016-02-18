#include "Mouse.h"
Mouse::Mouse(int newRow, int newCol)
{
	//Default assignments
	row = 0;
	col = 0;
	icon = 0;

	//Verify and set to initialization parameters
	if (newRow >= 0) row = newRow;
	if (newCol >= 0) col = newCol;
}

System::Drawing::Icon^ Mouse::getIcon()
{
	if (icon == 0)
		return mouseRight;
	else if (icon == 1)
		return mouseLeft;
	else if (icon == 2)
		return mouseUp;
	else
		return mouseDown;
}