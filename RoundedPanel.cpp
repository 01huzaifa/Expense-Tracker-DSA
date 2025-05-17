#include "RoundedPanel.h"

// Constructor to set the corner radius
RoundedPanel::RoundedPanel(int cornerRadius) {
    this->radius = cornerRadius;
}

// Creates a rounded path for a rectangle with the specified corner radius
GraphicsPath^ RoundedPanel::GetRoundedPath(Rectangle bounds) {
    GraphicsPath^ path = gcnew GraphicsPath();
    int diameter = radius * 2;

    // Add arcs for each corner
    path->AddArc(bounds.X, bounds.Y, diameter, diameter, 180, 90);  // Top-left corner
    path->AddArc(bounds.X + bounds.Width - diameter, bounds.Y, diameter, diameter, 270, 90);  // Top-right corner
    path->AddArc(bounds.X + bounds.Width - diameter, bounds.Y + bounds.Height - diameter, diameter, diameter, 0, 90);  // Bottom-right corner
    path->AddArc(bounds.X, bounds.Y + bounds.Height - diameter, diameter, diameter, 90, 90);  // Bottom-left corner
    path->CloseFigure();

    return path;
}

// Method to apply the rounded corners to a panel
void RoundedPanel::ApplyRoundedCorners(Panel^ panel) {
    panel->Region = gcnew Region(GetRoundedPath(panel->ClientRectangle));
}
