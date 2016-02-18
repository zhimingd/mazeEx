#pragma once
ref class Mouse
{
private:
	int row; //row location in maze
	int col; //column location in maze
	int icon; //icon indicator(0-right, 1=left, 2=up, 3=down)

	//Class variables
	static System::Drawing::Icon^ mouseRight = gcnew System::Drawing::Icon("mouseRight.ico");
	static System::Drawing::Icon^ mouseLeft = gcnew System::Drawing::Icon("mouseLeft.ico");
	static System::Drawing::Icon^ mouseUp = gcnew System::Drawing::Icon("mouseUp.ico");
	static System::Drawing::Icon^ mouseDown = gcnew System::Drawing::Icon("mouseDown.ico");
private:	
	Mouse(void) {};
public:

	//Initializing Constructor
	Mouse(int row, int col);

	//Accessor Methods
	int getRow() { return row; }
	int getCol() { return col; }
	System::Drawing::Icon^ Mouse::getIcon();

	//Mutator Methods
	void setRow(int newRow) { row = newRow; }
	void setCol(int newCol) { col = newCol; }

	//Utility methods
	void goRight() { col++; icon = 0; }
	void goLeft() { col--; icon = 1; }
	void goUp() { row--; icon = 2; }
	void goDown() { row++; icon = 3; }
};
