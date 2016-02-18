#pragma once
ref class Item abstract
{
	protected:
		int row; //row location in maze
		int col; //column location in maze
		int icon; //icon

		static System::Drawing::Icon^ myIcon;
	private:
		Item(void) {};
	public:

		//Initializing Constructor
		Item(int row, int col) {
			this->row = row; this->col = col;
		};

		//Accessor Methods
		int getRow() { return row; }
		int getCol() { return col; }
		System::Drawing::Icon^ getIcon() {	return myIcon;};
		

		//Mutator Methods
		void setRow(int newRow) { row = newRow; }
		void setCol(int newCol) { col = newCol; }
		virtual void setIcon() = 0;
};
