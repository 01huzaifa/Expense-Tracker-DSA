#pragma once

namespace ExpenseTracker {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::Drawing::Drawing2D;

    /// <summary>
    /// Summary for LoginForm
    /// </summary>
    public ref class LoginForm : public System::Windows::Forms::Form
    {
    public:
        LoginForm(void)
        {
            InitializeComponent();
            // Set the rounded corners for PictureBox1
            SetRoundedCornersForPictureBox1();
            SetRoundedCornersforButton1();
        }

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~LoginForm()
        {
            if (components)
            {
                delete components;
            }
        }


    private: System::Windows::Forms::PictureBox^ pictureBox2;
    private: System::Windows::Forms::PictureBox^ pictureBox3;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::CheckBox^ checkBox1;
    private: System::Windows::Forms::PictureBox^ pictureBox5;
    private: System::Windows::Forms::TextBox^ textBox3;
    private: System::Windows::Forms::Button^ button1;
           void onLoginButtonClick(System::Object^ sender, System::EventArgs^ e);
    private: System::Windows::Forms::Panel^ panel1;
    private: System::Windows::Forms::Panel^ panel2;
    private: System::Windows::Forms::TextBox^ textBox1;
    private: System::Windows::Forms::TextBox^ textBox2;
    private: System::Windows::Forms::PictureBox^ pictureBox1;
           void SetRoundedCornersForPictureBox1();
           void SetRoundedCornersforButton1();// Declaration for the helper method

    protected:

    private:
        /// <summary>
        /// Required designer variable.
        /// </summary>
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(LoginForm::typeid));
            this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->panel1 = (gcnew System::Windows::Forms::Panel());
            this->panel2 = (gcnew System::Windows::Forms::Panel());
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
            this->textBox2 = (gcnew System::Windows::Forms::TextBox());
            this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
            this->textBox3 = (gcnew System::Windows::Forms::TextBox());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
            this->SuspendLayout();
            // 
            // pictureBox2
            // 
            this->pictureBox2->Dock = System::Windows::Forms::DockStyle::Fill;
            this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
            this->pictureBox2->Location = System::Drawing::Point(0, 0);
            this->pictureBox2->Name = L"pictureBox2";
            this->pictureBox2->Size = System::Drawing::Size(1924, 1050);
            this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox2->TabIndex = 2;
            this->pictureBox2->TabStop = false;
            this->pictureBox2->Click += gcnew System::EventHandler(this, &LoginForm::pictureBox2_Click);
            // 
            // pictureBox1
            // 
            this->pictureBox1->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->pictureBox1->Location = System::Drawing::Point(443, 203);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(1033, 615);
            this->pictureBox1->TabIndex = 3;
            this->pictureBox1->TabStop = false;
            this->pictureBox1->Click += gcnew System::EventHandler(this, &LoginForm::pictureBox1_Click);
            // 
            // pictureBox3
            // 
            this->pictureBox3->BackColor = System::Drawing::SystemColors::Control;
            this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
            this->pictureBox3->Location = System::Drawing::Point(1030, 402);
            this->pictureBox3->Name = L"pictureBox3";
            this->pictureBox3->Size = System::Drawing::Size(406, 379);
            this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox3->TabIndex = 4;
            this->pictureBox3->TabStop = false;
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(192)));
            this->label1->Location = System::Drawing::Point(482, 366);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(169, 45);
            this->label1->TabIndex = 9;
            this->label1->Text = L"Username";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(192)));
            this->label2->Location = System::Drawing::Point(482, 504);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(163, 45);
            this->label2->TabIndex = 10;
            this->label2->Text = L"Password";
            this->label2->Click += gcnew System::EventHandler(this, &LoginForm::label2_Click);
            // 
            // checkBox1
            // 
            this->checkBox1->AutoSize = true;
            this->checkBox1->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->checkBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->checkBox1->ForeColor = System::Drawing::Color::Purple;
            this->checkBox1->Location = System::Drawing::Point(706, 621);
            this->checkBox1->Name = L"checkBox1";
            this->checkBox1->Size = System::Drawing::Size(200, 34);
            this->checkBox1->TabIndex = 13;
            this->checkBox1->Text = L"Show Password";
            this->checkBox1->UseVisualStyleBackColor = false;
            this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &LoginForm::checkBox1_CheckedChanged);
            // 
            // button1
            // 
            this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
            this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button1->ForeColor = System::Drawing::SystemColors::HighlightText;
            this->button1->Location = System::Drawing::Point(577, 677);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(188, 73);
            this->button1->TabIndex = 15;
            this->button1->Text = L"login";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &LoginForm::onLoginButtonClick);
            // 
            // panel1
            // 
            this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(192)));
            this->panel1->Location = System::Drawing::Point(490, 466);
            this->panel1->Name = L"panel1";
            this->panel1->Size = System::Drawing::Size(443, 5);
            this->panel1->TabIndex = 18;
            this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &LoginForm::panel1_Paint);
            // 
            // panel2
            // 
            this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(192)));
            this->panel2->Location = System::Drawing::Point(486, 605);
            this->panel2->Name = L"panel2";
            this->panel2->Size = System::Drawing::Size(447, 5);
            this->panel2->TabIndex = 19;
            // 
            // textBox1
            // 
            this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->textBox1->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 11, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->textBox1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(64)));
            this->textBox1->Location = System::Drawing::Point(490, 435);
            this->textBox1->Name = L"textBox1";
            this->textBox1->Size = System::Drawing::Size(365, 25);
            this->textBox1->TabIndex = 20;
            this->textBox1->TextChanged += gcnew System::EventHandler(this, &LoginForm::textBox1_TextChanged_1);
            // 
            // textBox2
            // 
            this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->textBox2->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 11, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->textBox2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(64)));
            this->textBox2->Location = System::Drawing::Point(490, 574);
            this->textBox2->Name = L"textBox2";
            this->textBox2->PasswordChar = '*';
            this->textBox2->Size = System::Drawing::Size(365, 25);
            this->textBox2->TabIndex = 21;
            // 
            // pictureBox5
            // 
            this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.Image")));
            this->pictureBox5->Location = System::Drawing::Point(1304, 237);
            this->pictureBox5->Name = L"pictureBox5";
            this->pictureBox5->Size = System::Drawing::Size(132, 124);
            this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox5->TabIndex = 22;
            this->pictureBox5->TabStop = false;
            // 
            // textBox3
            // 
            this->textBox3->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->textBox3->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 26, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->textBox3->ForeColor = System::Drawing::Color::Purple;
            this->textBox3->Location = System::Drawing::Point(486, 265);
            this->textBox3->Name = L"textBox3";
            this->textBox3->Size = System::Drawing::Size(779, 61);
            this->textBox3->TabIndex = 23;
            this->textBox3->Text = L"Welcome to Expense Tracker";
            // 
            // LoginForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1924, 1050);
            this->Controls->Add(this->textBox3);
            this->Controls->Add(this->pictureBox5);
            this->Controls->Add(this->textBox2);
            this->Controls->Add(this->textBox1);
            this->Controls->Add(this->panel2);
            this->Controls->Add(this->panel1);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->checkBox1);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->pictureBox3);
            this->Controls->Add(this->pictureBox1);
            this->Controls->Add(this->pictureBox2);
            this->Name = L"LoginForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"LoginForm";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }

#pragma endregion
    private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
    }

    private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
    }
private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
    if (checkBox1->Checked) {
        // Show password
        textBox2->PasswordChar = '\0';
    }
    else {
        // Hide password with a masking character
        textBox2->PasswordChar = '*';
    }
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox1_TextChanged_1(System::Object^ sender, System::EventArgs^ e) {
}
};
}