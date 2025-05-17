#include "RoundButtons.h"

void SetRoundedButtons(System::Windows::Forms::Button ^ button, int radius) {
    // Create a GraphicsPath for rounded corners
    System::Drawing::Drawing2D::GraphicsPath^ path = gcnew System::Drawing::Drawing2D::GraphicsPath();
    path->AddArc(0, 0, radius, radius, 180, 90);
    path->AddArc(button->Width - radius, 0, radius, radius, 270, 90);
    path->AddArc(button->Width - radius, button->Height - radius, radius, radius, 0, 90);
    path->AddArc(0, button->Height - radius, radius, radius, 90, 90);
    path->CloseFigure();

    // Apply the rounded shape to the button
    button->Region = gcnew System::Drawing::Region(path);
}