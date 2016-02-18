#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Maze::MyForm form;
	Application::Run(%form);
}

using namespace Maze;
System::Void MyForm::MyForm_Load(System::Object^  sender, System::EventArgs^  e) {

	int row, col;


	g = panel1->CreateGraphics();
	grayBrush = gcnew System::Drawing::SolidBrush(Color::Gray);
	whiteBrush = gcnew System::Drawing::SolidBrush(Color::White);
	burlyBrush = gcnew System::Drawing::SolidBrush(Color::BurlyWood);
	newBrush = gcnew System::Drawing::SolidBrush(Color::Aqua);

	blackPen = gcnew System::Drawing::Pen(Color::Black);

	//Construct maze array
	maze = gcnew array<Cell^, 2>(NUMROWS, NUMCOLS);
	for (row = 0; row < NUMROWS; row++)
	{
		for (col = 0; col < NUMCOLS; col++)
		{
			maze[row, col] = gcnew Cell(row, col, true);
		}
	}
	
}


System::Void MyForm::button1_Click(System::Object^  sender, System::EventArgs^  e) {

	//Local variables
	int x, y;


	//Starting postion for mouse
	int mouseRow = 9;
	int mouseCol = 0;

	//Starting cheese location
	int cheeseRow = 11;
	int cheeseCol = 8;

	//Set initial direction
	direction = 'r';

	//Create Mouse
	myMouse = gcnew Mouse(mouseRow, mouseCol);

	//Draw the maze
	drawMaze();

	//Draw cheese
	myCheese = gcnew Cheese(cheeseRow, cheeseCol);
	x = cheeseCol * CELLSIZE;
	y = cheeseRow * CELLSIZE;
	Rectangle cheeseRect = Rectangle(x, y, CELLSIZE, CELLSIZE);
	g->DrawIcon(myCheese->getIcon(), cheeseRect);
	//maze[myCheese->getRow(), myCheese->getCol()]->setCheese(true);
	//cheeseCol = myCheese->getCol();
	maze[cheeseRow, cheeseCol]->setCheese(true);

	//Draw the mouse
	myMouse->setRow(mouseRow);
	myMouse->setCol(mouseCol);
	x = mouseCol * CELLSIZE;
	y = mouseRow * CELLSIZE;
	Rectangle mouseRect = Rectangle(x, y, CELLSIZE, CELLSIZE);
	g->DrawIcon(myMouse->getIcon(), mouseRect);

	int row, col;

	//reset the cell to init states
	for (row = 0; row < NUMROWS; row++)
	{
		for (col = 0; col < NUMCOLS; col++)
		{
			maze[row, col]->setAccess(true);
		}
	}
	//Start the timer
	timer1->Start();


}

void MyForm::drawMaze()
{
	//Declare local variables;
	int row, col;
	int x, y;

	//Refresh the panel
	panel1->Refresh();

	//Draw the empty maze
	for (row = 0; row < NUMROWS; row++)
	{
		for (col = 0; col < NUMCOLS; col++)
		{
			x = col * CELLSIZE;
			y = row * CELLSIZE;
			Rectangle gridRect = Rectangle(x, y, CELLSIZE - 1, CELLSIZE - 1);
			g->FillRectangle(whiteBrush, gridRect);
			g->DrawRectangle(blackPen, gridRect);
		}
	}
}
bool MyForm::edge()
{
	if (direction == 'r') {
		if (myMouse->getCol() < NUMCOLS - 1) return false;
	}
	else if (direction == 'l') {
		if (myMouse->getCol() > 0) return false;
	}
	else if (direction == 'u') {
		if (myMouse->getRow() > 0) return false;
	}
	else if (direction == 'd') {
		if (myMouse->getRow() < NUMROWS - 1) return false;
	}
	return true;

}
System::Void MyForm::timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	//Declare local variables;
	int x, y;
	int row, col;

	//Initializing local variables;
	row = myMouse->getRow();
	col = myMouse->getCol();
	x = myMouse->getCol() * CELLSIZE;
	y = myMouse->getRow() * CELLSIZE;

	//Create current myMouse position
	Rectangle oldRect = Rectangle(x, y, CELLSIZE, CELLSIZE);


	if (!edge())
	{
		//find if this cell has been access before and paint different color
		if (maze[row, col]->getAccess())
			//Fill old mouse position with newBrush
			g->FillRectangle(newBrush, oldRect);
		else
			//Fill old mouse position with BurlyWood
			g->FillRectangle(burlyBrush, oldRect);
		g->DrawRectangle(blackPen, oldRect);
		maze[row, col]->setAccess(false);

		//Move in the chosen direction
		//direction = pickupADirection();
		switch (direction)
		{
		case 'r':
			myMouse->goRight();
			break;
		case 'l':
			myMouse->goLeft();
			break;
		case 'u':
			myMouse->goUp();
			break;
		case 'd':
			myMouse->goDown();
			break;
		}


		//Draw mouse at new location
		row = myMouse->getRow();
		col = myMouse->getCol();

		//Check access if never access then go ahead
		if (maze[row, col]->getAccess())
		{


			x = col * CELLSIZE;
			y = row * CELLSIZE;
			Rectangle mouseRect = Rectangle(x, y, CELLSIZE, CELLSIZE);
			g->DrawIcon(myMouse->getIcon(), mouseRect);

			//if mouse moves into cell with cheese, congratulations!
			if (maze[row, col]->getCheese())
			{
				maze[row, col]->setCheese(false);
				timer1->Stop();
				MessageBox::Show("Congratulation!", "You found it");
			}
		}
		else // if have access then skip, pick up another direction
		{
			direction = pickupADirection();
		}
	}
	else // at the edge
	{
		switch (direction)
		{
		case 'r':
			direction = 'd';
			break;
		case 'l':
			direction = 'u';
			break;
		case 'u':
			direction = 'r';
			break;
		case 'd':
			direction = 'l';
			break;
		}

		//int ret = Utility::getRand();
		//label1->Text = ret.ToString();
		//
		//switch (ret) {
		//case 0:
		//	direction = 'd';
		//	break;
		//case 1:
		//	direction = 'u';
		//	break;
		//case 2:
		//	direction = 'r';
		//	break;
		//case 3:
		//	direction = 'l';
		//	break;
		//}
	}
}


System::Void MyForm::button2_Click(System::Object^  sender, System::EventArgs^  e) {
	timer1->Stop();
}

char MyForm::pickupADirection()
{
	int ret = Utility::getRand();
	label1->Text = ret.ToString();

	switch (ret) {
	case 0:
		direction = 'd';
		break;
	case 1:
		direction = 'u';
		break;
	case 2:
		direction = 'r';
		break;
	case 3:
		direction = 'l';
		break;
	}
	return direction;
}
