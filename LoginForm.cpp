#include "LoginForm.h"
#include "ExpenseForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace ExpenseTracker;

bool validateCredentials(System::String^ username, System::String^ password) {
    array<System::String^, 2>^ credentials = gcnew array<System::String^, 2>(3, 2) {
        { "user1", "pass1" },
        { "user2", "pass2" },
        { "user3", "pass3" }
    };

    for (int i = 0; i < credentials->GetLength(0); ++i) {
        if (credentials[i, 0] == username) {
            if (credentials[i, 1] == password) {
                return true;  // Correct username and password
            }
            else {
                return false;  // Correct username, but incorrect password
            }
        }
    }

    return false;  // Username not found
}

void LoginForm::onLoginButtonClick(System::Object^ sender, System::EventArgs^ e) {
    System::String^ username = this->textBox1->Text;
    System::String^ password = this->textBox2->Text;

    // Check if any fields are empty
    if (String::IsNullOrEmpty(username) || String::IsNullOrEmpty(password)) {
        MessageBox::Show("Please fill in both username and password.", "Input Error", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
        return;
    }

    // Validate credentials
    if (validateCredentials(username, password)) {
        ExpenseForm^ expenseForm = gcnew ExpenseForm(username);
        expenseForm->ShowDialog();
        this->Close();
    }
    else {
        MessageBox::Show("Please enter the correct username and password.", "Login Failed", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}

void LoginForm::SetRoundedCornersForPictureBox1() {
    System::Drawing::Drawing2D::GraphicsPath^ roundedRect = gcnew System::Drawing::Drawing2D::GraphicsPath();
    int radius = 30;
    System::Drawing::Rectangle bounds = this->pictureBox1->ClientRectangle;

    roundedRect->AddArc(bounds.X, bounds.Y, radius, radius, 180, 90);
    roundedRect->AddArc(bounds.X + bounds.Width - radius, bounds.Y, radius, radius, 270, 90);
    roundedRect->AddArc(bounds.X + bounds.Width - radius, bounds.Y + bounds.Height - radius, radius, radius, 0, 90);
    roundedRect->AddArc(bounds.X, bounds.Y + bounds.Height - radius, radius, radius, 90, 90);
    roundedRect->CloseFigure();

    this->pictureBox1->Region = gcnew System::Drawing::Region(roundedRect);
}

void LoginForm::SetRoundedCornersforButton1() {
    System::Drawing::Drawing2D::GraphicsPath^ roundedRect = gcnew System::Drawing::Drawing2D::GraphicsPath();
    int radius = 15;
    System::Drawing::Rectangle bounds = this->button1->ClientRectangle;

    roundedRect->AddArc(bounds.X, bounds.Y, radius, radius, 180, 90);
    roundedRect->AddArc(bounds.X + bounds.Width - radius, bounds.Y, radius, radius, 270, 90);
    roundedRect->AddArc(bounds.X + bounds.Width - radius, bounds.Y + bounds.Height - radius, radius, radius, 0, 90);
    roundedRect->AddArc(bounds.X, bounds.Y + bounds.Height - radius, radius, radius, 90, 90);
    roundedRect->CloseFigure();

    this->button1->Region = gcnew System::Drawing::Region(roundedRect);
}

[STAThreadAttribute]
int main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    LoginForm form;
    form.StartPosition = FormStartPosition::CenterScreen;
    form.WindowState = FormWindowState::Maximized;
    form.Show();

    Application::Run(% form);

    return 0;
}
