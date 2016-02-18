#pragma once
#include "Mouse.h"
#include "Cell.h"
#include "Cheese.h"
#include "Utility.h"

namespace Maze 
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		//Instance variables
		Mouse^ myMouse;
		Cheese^ myCheese;
		array <Cell^, 2>^ maze;
		char direction;

		//Drawing objects
		Graphics^ g;
		Brush^ grayBrush;
		Brush^ whiteBrush;
		Brush^ burlyBrush;
		Brush^ newBrush;

		Pen^ blackPen;
		//Drawing::Icon^ cheese;

		//Static constants
		static const int NUMROWS = 16;
		static const int NUMCOLS = 20;
		static const int CELLSIZE = 25;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Label^  label1;
	private: System::ComponentModel::IContainer^  components;

			 System::Void MyForm::MyForm_Load(System::Object^  sender, System::EventArgs^  e);
			 System::Void button1_Click(System::Object^  sender, System::EventArgs^  e);
			 System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e);
			 System::Void button2_Click(System::Object^  sender, System::EventArgs^  e);
			 void drawMaze();
			 bool edge();
			 char pickupADirection();

			 /// <summary>
			 /// Required designer variable.
			 /// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
			 void InitializeComponent(void)
			 {
				 this->components = (gcnew System::ComponentModel::Container());
				 this->panel1 = (gcnew System::Windows::Forms::Panel());
				 this->button1 = (gcnew System::Windows::Forms::Button());
				 this->button2 = (gcnew System::Windows::Forms::Button());
				 this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
				 this->label1 = (gcnew System::Windows::Forms::Label());
				 this->SuspendLayout();
				 // 
				 // panel1
				 // 
				 this->panel1->Location = System::Drawing::Point(25, 35);
				 this->panel1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
				 this->panel1->Name = L"panel1";
				 this->panel1->Size = System::Drawing::Size(1120, 802);
				 this->panel1->TabIndex = 0;
				 this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel1_Paint);
				 // 
				 // button1
				 // 
				 this->button1->Location = System::Drawing::Point(814, 869);
				 this->button1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
				 this->button1->Name = L"button1";
				 this->button1->Size = System::Drawing::Size(126, 51);
				 this->button1->TabIndex = 1;
				 this->button1->Text = L"Start";
				 this->button1->UseVisualStyleBackColor = true;
				 this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
				 // 
				 // button2
				 // 
				 this->button2->Location = System::Drawing::Point(980, 869);
				 this->button2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
				 this->button2->Name = L"button2";
				 this->button2->Size = System::Drawing::Size(116, 51);
				 this->button2->TabIndex = 2;
				 this->button2->Text = L"Stop";
				 this->button2->UseVisualStyleBackColor = true;
				 this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
				 // 
				 // timer1
				 // 
				 this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
				 // 
				 // label1
				 // 
				 this->label1->AutoSize = true;
				 this->label1->Location = System::Drawing::Point(109, 881);
				 this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
				 this->label1->Name = L"label1";
				 this->label1->Size = System::Drawing::Size(70, 25);
				 this->label1->TabIndex = 3;
				 this->label1->Text = L"label1";
				 // 
				 // MyForm
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->AutoSize = true;
				 this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
				 this->ClientSize = System::Drawing::Size(1185, 950);
				 this->Controls->Add(this->label1);
				 this->Controls->Add(this->panel1);
				 this->Controls->Add(this->button2);
				 this->Controls->Add(this->button1);
				 this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
				 this->Name = L"MyForm";
				 this->Text = L"Maze";
				 this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion


private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
}
};
}

