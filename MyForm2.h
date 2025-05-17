#pragma once

namespace ExpenseTracker {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::Windows::Forms::DataVisualization::Charting;
    using namespace System::Collections::Generic; // For List and KeyValuePair

    public ref class MyForm2 : public System::Windows::Forms::Form
    {
    public:
        MyForm2(void)
        {
            InitializeComponent();
        }

    protected:
        ~MyForm2()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;  // Chart control
        System::Windows::Forms::Button^ button1;
        System::Windows::Forms::Button^ button2;
        System::Windows::Forms::Button^ button3;
        System::Windows::Forms::Label^ label19;
    private: System::Windows::Forms::Label^ label1;

        System::ComponentModel::Container^ components;

        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm2::typeid));
            this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->button2 = (gcnew System::Windows::Forms::Button());
            this->button3 = (gcnew System::Windows::Forms::Button());
            this->label19 = (gcnew System::Windows::Forms::Label());
            this->label1 = (gcnew System::Windows::Forms::Label());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
            this->SuspendLayout();
            // 
            // chart1
            // 
            this->chart1->Location = System::Drawing::Point(300, 80);
            this->chart1->Name = L"chart1";
            this->chart1->Size = System::Drawing::Size(740, 470);
            this->chart1->TabIndex = 0;
            this->chart1->Text = L"chart1";
            // 
            // button1
            // 
            this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
            this->button1->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 11.25F, System::Drawing::FontStyle::Bold));
            this->button1->ForeColor = System::Drawing::Color::White;
            this->button1->Location = System::Drawing::Point(400, 600);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(100, 45);
            this->button1->TabIndex = 1;
            this->button1->Text = L"Pie Chart";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &MyForm2::button1_Click);
            // 
            // button2
            // 
            this->button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.BackgroundImage")));
            this->button2->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 11, System::Drawing::FontStyle::Bold));
            this->button2->ForeColor = System::Drawing::Color::White;
            this->button2->Location = System::Drawing::Point(550, 600);
            this->button2->Name = L"button2";
            this->button2->Size = System::Drawing::Size(120, 45);
            this->button2->TabIndex = 2;
            this->button2->Text = L"Bar Chart";
            this->button2->UseVisualStyleBackColor = true;
            this->button2->Click += gcnew System::EventHandler(this, &MyForm2::button2_Click);
            // 
            // button3
            // 
            this->button3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.BackgroundImage")));
            this->button3->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 11, System::Drawing::FontStyle::Bold));
            this->button3->ForeColor = System::Drawing::Color::White;
            this->button3->Location = System::Drawing::Point(720, 600);
            this->button3->Name = L"button3";
            this->button3->Size = System::Drawing::Size(120, 45);
            this->button3->TabIndex = 3;
            this->button3->Text = L"Line Chart";
            this->button3->UseVisualStyleBackColor = true;
            this->button3->Click += gcnew System::EventHandler(this, &MyForm2::button3_Click);
            // 
            // label19
            // 
            this->label19->AutoSize = true;
            this->label19->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 16, System::Drawing::FontStyle::Bold));
            this->label19->ForeColor = System::Drawing::Color::White;
            this->label19->Location = System::Drawing::Point(300, 20);
            this->label19->Name = L"label19";
            this->label19->Size = System::Drawing::Size(0, 30);
            this->label19->TabIndex = 4;
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(460, 15);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(46, 30);
            this->label1->TabIndex = 5;
            this->label1->Text = L"Expense Breakdown: A Clear Chart View";
            this->label1->Click += gcnew System::EventHandler(this, &MyForm2::label1_Click);
            // 
            // MyForm2
            // 
            this->BackColor = System::Drawing::Color::White;
            this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
            this->ClientSize = System::Drawing::Size(900, 600);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->label19);
            this->Controls->Add(this->chart1);
            this->Controls->Add(this->button3);
            this->Controls->Add(this->button2);
            this->Controls->Add(this->button1);
            this->Name = L"MyForm2";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }

        // Event Handlers for Button Clicks
    public:
        void button1_Click(System::Object^ sender, System::EventArgs^ e);
        void button2_Click(System::Object^ sender, System::EventArgs^ e);
        void button3_Click(System::Object^ sender, System::EventArgs^ e);
        void DisplayPieChart();
        void DisplayBarChart();
        void DisplayLineChart();
    private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
    }
};
}







