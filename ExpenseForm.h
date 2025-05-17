#pragma once
#include "ExpenseList.h"
#include "ExpenseAction.h"
#include <stack>  
#include "RoundedPanel.h"
#include "RoundButtons.h"
#include "LoginForm.h"
#include "MyForm2.h"
using namespace System::Collections::Generic;


namespace ExpenseTracker {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Drawing2D;

	public ref class ExpenseForm : public System::Windows::Forms::Form {
	public:
		ExpenseForm(System::String^ username) {
			InitializeComponent();

			this->username = username;
			expenses = gcnew ExpenseList();
			filteredExpenses = gcnew List<ExpenseNode^>();


			// Initialize Undo/Redo Stacks for managed pointers
			undoStack = gcnew System::Collections::Generic::Stack<ExpenseAction^>();
			redoStack = gcnew System::Collections::Generic::Stack<ExpenseAction^>();

			// Create a RoundedPanel object with the desired corner radius
			RoundedPanel^ roundedCornerHelper = gcnew RoundedPanel(30);

			// Apply rounded corners to panel1
			roundedCornerHelper->ApplyRoundedCorners(panel1);

			// If you have more panels, you can apply rounded corners to them as well
			roundedCornerHelper->ApplyRoundedCorners(panel2);
			roundedCornerHelper->ApplyRoundedCorners(panel3);

			// Set rounded corners for buttons
			SetRoundedButtons(this->btnUndo, 15); // Adjust radius as needed
			SetRoundedButtons(this->btnRedo, 15);
			SetRoundedButtons(this->button1, 15);
			SetRoundedButtons(this->button3, 15);
			SetRoundedButtons(this->button4, 15);
			SetRoundedButtons(this->button6, 15);
			SetRoundedButtons(this->button7, 15);

			LoadExpenses(); // Load data specific to the logged-in user
		}

	protected:
		~ExpenseForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		ExpenseList^ expenses;  // Now fully defined since ExpenseList.h is included

		List<ExpenseNode^>^ filteredExpenses;  // Holds filtered data

		String^ username;

		// Grouped UI Controls
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;

		   // Grouped Buttons
	private: System::Windows::Forms::Button^ btnUndo;
	private: System::Windows::Forms::Button^ btnRedo;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button1;


		   // Grouped ComboBoxes
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::ComboBox^ comboBox1;

		   // Grouped TextBoxes
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;

		   // Other Controls
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Panel^ panel1;

		   // DataGridView Columns
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn4;

		   // Grouped Logic Variables
	private: System::Collections::Generic::Stack<ExpenseAction^>^ redoStack;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button9;

	private: System::Collections::Generic::Stack<ExpenseAction^>^ undoStack;

		   // Methods
		   void Undo();
		   void Redo();
		   Void SaveAllExpensesToFile();
		   void FilterByCategory(System::String^ category);
		   void RefreshDataGrid();
		   void ShowError(String^ message);
		   void OnSearchButtonClick(System::Object^ sender, System::EventArgs^ e);
		   void DeleteSelectedExpense();
		   void AddExpense();
		   void SaveExpenseToFile(String^ expenseName, String^ amount, String^ category, String^ date);
		   bool IsInputValid(String^ expenseName, String^ amount, String^ category);
		   void LoadExpenses();



	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ExpenseForm::typeid));
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->btnUndo = (gcnew System::Windows::Forms::Button());
			this->btnRedo = (gcnew System::Windows::Forms::Button());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->dateTimePicker1);
			this->panel1->Controls->Add(this->comboBox1);
			this->panel1->Controls->Add(this->textBox3);
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Location = System::Drawing::Point(25, 104);
			this->panel1->Margin = System::Windows::Forms::Padding(2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(554, 267);
			this->panel1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->button1->Location = System::Drawing::Point(217, 211);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(105, 31);
			this->button1->TabIndex = 11;
			this->button1->Text = L"Add";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ExpenseForm::button1_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::Purple;
			this->label6->Location = System::Drawing::Point(293, 75);
			this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(65, 18);
			this->label6->TabIndex = 10;
			this->label6->Text = L"Amount";
			this->label6->Click += gcnew System::EventHandler(this, &ExpenseForm::label6_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::Purple;
			this->label5->Location = System::Drawing::Point(37, 142);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(43, 18);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Date";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Purple;
			this->label4->Location = System::Drawing::Point(293, 142);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(76, 18);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Category";
			this->label4->Click += gcnew System::EventHandler(this, &ExpenseForm::label4_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Purple;
			this->label3->Location = System::Drawing::Point(37, 75);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(188, 18);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Name of Expense(Brief)";
			this->label3->Click += gcnew System::EventHandler(this, &ExpenseForm::label3_Click);
			// 
			// label2
			// 
			this->label2->BackColor = System::Drawing::Color::Thistle;
			this->label2->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Indigo;
			this->label2->ImageAlign = System::Drawing::ContentAlignment::BottomRight;
			this->label2->Location = System::Drawing::Point(0, 0);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(554, 50);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Add New Expense";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dateTimePicker1->Location = System::Drawing::Point(40, 168);
			this->dateTimePicker1->Margin = System::Windows::Forms::Padding(2);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(220, 23);
			this->dateTimePicker1->TabIndex = 5;
			this->dateTimePicker1->ValueChanged += gcnew System::EventHandler(this, &ExpenseForm::dateTimePicker1_ValueChanged);
			// 
			// comboBox1
			// 
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(14) {
				L"Groceries", L"Transportation", L"Utilities",
					L"Rent", L"Entertainment", L"Dining", L"Healthcare", L"Education", L"Travel", L"Shopping", L"Subscriptions", L"Insurance", L"Savings",
					L"Miscellaneous"
			});
			this->comboBox1->Location = System::Drawing::Point(297, 166);
			this->comboBox1->Margin = System::Windows::Forms::Padding(2);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(177, 24);
			this->comboBox1->TabIndex = 4;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &ExpenseForm::comboBox1_SelectedIndexChanged);
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox3->Location = System::Drawing::Point(297, 101);
			this->textBox3->Margin = System::Windows::Forms::Padding(2);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(177, 23);
			this->textBox3->TabIndex = 2;
			this->textBox3->Tag = L"";
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &ExpenseForm::textBox3_TextChanged);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(40, 101);
			this->textBox1->Margin = System::Windows::Forms::Padding(2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(221, 23);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &ExpenseForm::textBox1_TextChanged);
			// 
			// button3
			// 
			this->button3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.BackgroundImage")));
			this->button3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button3->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->button3->Location = System::Drawing::Point(395, 68);
			this->button3->Margin = System::Windows::Forms::Padding(2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(105, 32);
			this->button3->TabIndex = 12;
			this->button3->Text = L"Delete";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &ExpenseForm::button3_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label1->Location = System::Drawing::Point(543, 26);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(368, 37);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Expense Tracker Dashboard";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->btnUndo);
			this->panel2->Controls->Add(this->btnRedo);
			this->panel2->Controls->Add(this->label11);
			this->panel2->Controls->Add(this->dataGridView1);
			this->panel2->Location = System::Drawing::Point(610, 104);
			this->panel2->Margin = System::Windows::Forms::Padding(2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(644, 530);
			this->panel2->TabIndex = 12;
			this->panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &ExpenseForm::panel2_Paint);
			// 
			// btnUndo
			// 
			this->btnUndo->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnUndo.BackgroundImage")));
			this->btnUndo->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnUndo->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnUndo->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnUndo->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->btnUndo->Location = System::Drawing::Point(27, 10);
			this->btnUndo->Margin = System::Windows::Forms::Padding(2);
			this->btnUndo->Name = L"btnUndo";
			this->btnUndo->Size = System::Drawing::Size(91, 28);
			this->btnUndo->TabIndex = 12;
			this->btnUndo->Text = L"Undo";
			this->btnUndo->UseVisualStyleBackColor = true;
			this->btnUndo->Click += gcnew System::EventHandler(this, &ExpenseForm::btnUndo_Click);
			// 
			// btnRedo
			// 
			this->btnRedo->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnRedo.BackgroundImage")));
			this->btnRedo->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnRedo->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnRedo->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnRedo->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->btnRedo->Location = System::Drawing::Point(127, 10);
			this->btnRedo->Margin = System::Windows::Forms::Padding(2);
			this->btnRedo->Name = L"btnRedo";
			this->btnRedo->Size = System::Drawing::Size(91, 28);
			this->btnRedo->TabIndex = 13;
			this->btnRedo->Text = L"Redo";
			this->btnRedo->UseVisualStyleBackColor = true;
			this->btnRedo->Click += gcnew System::EventHandler(this, &ExpenseForm::btnRedo_Click);
			// 
			// label11
			// 
			this->label11->BackColor = System::Drawing::Color::Thistle;
			this->label11->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->ForeColor = System::Drawing::Color::Indigo;
			this->label11->ImageAlign = System::Drawing::ContentAlignment::BottomRight;
			this->label11->Location = System::Drawing::Point(0, 0);
			this->label11->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(644, 50);
			this->label11->TabIndex = 6;
			this->label11->Text = L"Display Expense";
			this->label11->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::MistyRose;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::Plum;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::Color::Thistle;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->dataGridViewTextBoxColumn1,
					this->dataGridViewTextBoxColumn2, this->dataGridViewTextBoxColumn3, this->dataGridViewTextBoxColumn4
			});
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::Color::LightPink;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView1->EnableHeadersVisualStyles = false;
			this->dataGridView1->GridColor = System::Drawing::Color::LightGray;
			this->dataGridView1->Location = System::Drawing::Point(27, 52);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(2);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 62;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->Size = System::Drawing::Size(595, 452);
			this->dataGridView1->TabIndex = 7;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &ExpenseForm::dataGridView1_CellContentClick);
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->dataGridViewTextBoxColumn1->HeaderText = L"Expense Name";
			this->dataGridViewTextBoxColumn1->MinimumWidth = 8;
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			this->dataGridViewTextBoxColumn1->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->dataGridViewTextBoxColumn1->Width = 85;
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->HeaderText = L"Amount";
			this->dataGridViewTextBoxColumn2->MinimumWidth = 8;
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			this->dataGridViewTextBoxColumn2->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// dataGridViewTextBoxColumn3
			// 
			this->dataGridViewTextBoxColumn3->HeaderText = L"Category";
			this->dataGridViewTextBoxColumn3->MinimumWidth = 8;
			this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
			this->dataGridViewTextBoxColumn3->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// dataGridViewTextBoxColumn4
			// 
			this->dataGridViewTextBoxColumn4->HeaderText = L"Date Added";
			this->dataGridViewTextBoxColumn4->MinimumWidth = 8;
			this->dataGridViewTextBoxColumn4->Name = L"dataGridViewTextBoxColumn4";
			this->dataGridViewTextBoxColumn4->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->label8);
			this->panel3->Controls->Add(this->comboBox2);
			this->panel3->Controls->Add(this->label7);
			this->panel3->Controls->Add(this->button7);
			this->panel3->Controls->Add(this->button6);
			this->panel3->Controls->Add(this->button3);
			this->panel3->Controls->Add(this->button4);
			this->panel3->Controls->Add(this->textBox2);
			this->panel3->Controls->Add(this->label12);
			this->panel3->Location = System::Drawing::Point(30, 404);
			this->panel3->Margin = System::Windows::Forms::Padding(2);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(549, 211);
			this->panel3->TabIndex = 12;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::Purple;
			this->label8->Location = System::Drawing::Point(8, 157);
			this->label8->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(176, 25);
			this->label8->TabIndex = 16;
			this->label8->Text = L"Filter By Category:";
			// 
			// comboBox2
			// 
			this->comboBox2->BackColor = System::Drawing::Color::MistyRose;
			this->comboBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(15) {
				L"All", L"Groceries", L"Transportation", L"Utilities",
					L"Rent", L"Entertainment", L"Dining", L"Healthcare", L"Education", L"Travel", L"Shopping", L"Subscriptions", L"Insurance", L"Savings",
					L"Miscellaneous"
			});
			this->comboBox2->Location = System::Drawing::Point(198, 162);
			this->comboBox2->Margin = System::Windows::Forms::Padding(2);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(177, 24);
			this->comboBox2->TabIndex = 12;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &ExpenseForm::comboBox2_SelectedIndexChanged);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::Purple;
			this->label7->Location = System::Drawing::Point(8, 112);
			this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(85, 25);
			this->label7->TabIndex = 12;
			this->label7->Text = L"Sorting:";
			// 
			// button7
			// 
			this->button7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button7.BackgroundImage")));
			this->button7->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button7->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button7->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->button7->Location = System::Drawing::Point(341, 112);
			this->button7->Margin = System::Windows::Forms::Padding(2);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(139, 34);
			this->button7->TabIndex = 15;
			this->button7->Text = L"Date: New to Old";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &ExpenseForm::button7_Click);
			// 
			// button6
			// 
			this->button6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button6.BackgroundImage")));
			this->button6->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button6->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->button6->Location = System::Drawing::Point(145, 112);
			this->button6->Margin = System::Windows::Forms::Padding(2);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(178, 34);
			this->button6->TabIndex = 14;
			this->button6->Text = L"Amount: High to Low";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &ExpenseForm::button6_Click);
			// 
			// button4
			// 
			this->button4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button4.BackgroundImage")));
			this->button4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button4->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->button4->Location = System::Drawing::Point(268, 68);
			this->button4->Margin = System::Windows::Forms::Padding(2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(105, 32);
			this->button4->TabIndex = 13;
			this->button4->Text = L"Search";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &ExpenseForm::OnSearchButtonClick);
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::MistyRose;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(13, 74);
			this->textBox2->Margin = System::Windows::Forms::Padding(2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(243, 24);
			this->textBox2->TabIndex = 13;
			// 
			// label12
			// 
			this->label12->BackColor = System::Drawing::Color::Thistle;
			this->label12->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->ForeColor = System::Drawing::Color::Indigo;
			this->label12->ImageAlign = System::Drawing::ContentAlignment::BottomRight;
			this->label12->Location = System::Drawing::Point(0, 0);
			this->label12->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(549, 44);
			this->label12->TabIndex = 6;
			this->label12->Text = L"Manage Expenses";
			this->label12->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// button2
			// 
			this->button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.BackgroundImage")));
			this->button2->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::White;
			this->button2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.Image")));
			this->button2->Location = System::Drawing::Point(43, 12);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(105, 31);
			this->button2->TabIndex = 13;
			this->button2->Text = L"Log Out";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ExpenseForm::button2_Click);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(55, 55);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(82, 24);
			this->button9->TabIndex = 14;
			this->button9->Text = L"button9\r\n";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &ExpenseForm::button9_Click_1);
			// 
			// ExpenseForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(913, 487);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->panel1);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"ExpenseForm";
			this->Text = L"ExpenseForm";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &ExpenseForm::ExpenseForm_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ExpenseForm_Load(System::Object^ sender, System::EventArgs^ e) {
		LoadExpenses();
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void dateTimePicker1_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	AddExpense();
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	DeleteSelectedExpense();
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	RefreshDataGrid();
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	expenses->SortByAmount(false);
	RefreshDataGrid();
}
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
	expenses->SortByDate(false);
	RefreshDataGrid();
}
private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
}


private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
private: System::Void btnUndo_Click(System::Object^ sender, System::EventArgs^ e) {
	Undo();
}
private: System::Void btnRedo_Click(System::Object^ sender, System::EventArgs^ e) {
	Redo();
}
private: System::Void panel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}

private: System::Void comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	// Get the selected category from the ComboBox
	System::String^ selectedCategory = comboBox2->Text;
	// Check if the "All" option is selected
	if (comboBox2->SelectedItem->ToString() == "All") {
		// Refresh the grid to show all expenses
		RefreshDataGrid();
	}
	else {
		// Filter expenses by the selected category
		FilterByCategory(comboBox2->SelectedItem->ToString());
	}
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();  // Hide the current form (ExpenseForm)

	// Create a new instance of LoginForm
	LoginForm^ obj1 = gcnew LoginForm();

	// Set the LoginForm to be maximized when opened
	obj1->WindowState = FormWindowState::Maximized;

	// Show the LoginForm as a modal dialog
	obj1->ShowDialog();

	// Optionally, show the current form again after the dialog is closed
	this->Show();
}


private: System::Void button9_Click_1(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();  // Hide the current form (ExpenseForm)

	// Create a new instance of LoginForm
	MyForm2^ obj1 = gcnew MyForm2();

	// Set the LoginForm to be maximized when opened
	obj1->WindowState = FormWindowState::Maximized;

	// Show the LoginForm as a modal dialog
	obj1->ShowDialog();

	// Optionally, show the current form again after the dialog is closed
	this->Show();
}


};
}
