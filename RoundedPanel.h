#pragma once
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Drawing::Drawing2D;

ref class RoundedPanel {
public:
    // Constructor with customizable radius
    RoundedPanel(int cornerRadius);

    // Method to apply rounded corners to a given panel
    void ApplyRoundedCorners(Panel^ panel);

private:
    int radius;  // Corner radius
    GraphicsPath^ GetRoundedPath(Rectangle bounds);
};
