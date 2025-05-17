#include "MyForm2.h"
#using <System.dll>
#using <System.Windows.Forms.dll>
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Windows::Forms::DataVisualization::Charting;
using namespace System::IO; // For StreamReader
using namespace System::Collections::Generic; // For List and KeyValuePair

// Function to load data from a CSV file (Category, Total Cost)
Dictionary<String^, double>^ LoadExpenseData() {
    Dictionary<String^, double>^ expenses = gcnew Dictionary<String^, double>();
    try {
        StreamReader^ file = gcnew StreamReader("C:\\Users\\Huzaifa\\Desktop\\fornow.txt");

        String^ line;
        while ((line = file->ReadLine()) != nullptr) {
            array<String^>^ parts = line->Split(',');
            if (parts->Length == 2) { // Ensure there are exactly 2 parts: Category and Cost
                String^ category = parts[0]; // Category
                double cost;

                // Validate cost
                if (Double::TryParse(parts[1], cost)) {
                    expenses[category] = cost;
                }
                else {
                    MessageBox::Show("Invalid cost format in line: " + line);
                }
            }
            else {
                MessageBox::Show("Invalid line format: " + line);
            }
        }
        file->Close();
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error loading data: " + ex->Message);
    }
    return expenses;
}

// Event handler for button1 (Pie Chart)
System::Void ExpenseTracker::MyForm2::button1_Click(System::Object^ sender, System::EventArgs^ e) {
    try {
        DisplayPieChart();
        chart1->Invalidate(); // Force the chart to redraw
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error displaying pie chart: " + ex->Message);
    }
}

// Event handler for button2 (Bar Chart)
System::Void ExpenseTracker::MyForm2::button2_Click(System::Object^ sender, System::EventArgs^ e) {
    try {
        DisplayBarChart();
        chart1->Invalidate(); // Force the chart to redraw
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error displaying bar chart: " + ex->Message);
    }
}

// Event handler for button3 (Line Chart)
System::Void ExpenseTracker::MyForm2::button3_Click(System::Object^ sender, System::EventArgs^ e) {
    try {
        DisplayLineChart();
        chart1->Invalidate(); // Force the chart to redraw
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error displaying line chart: " + ex->Message);
    }
}

// Function to display Pie Chart
void ExpenseTracker::MyForm2::DisplayPieChart() {
    auto expenses = LoadExpenseData();

    if (expenses->Count == 0) {
        MessageBox::Show("No data loaded for Pie Chart.");
        return;
    }

    chart1->Series->Clear();
    chart1->ChartAreas->Clear();
    chart1->ChartAreas->Add("ChartArea1");

    Series^ series = gcnew Series();
    series->ChartType = SeriesChartType::Pie;

    for each (auto expense in expenses) {
        series->Points->AddXY(expense.Key, expense.Value); // Use category as label
    }

    chart1->Series->Add(series);
}

// Function to display Bar Chart
void ExpenseTracker::MyForm2::DisplayBarChart() {
    auto expenses = LoadExpenseData();

    if (expenses->Count == 0) {
        MessageBox::Show("No data loaded for Bar Chart.");
        return;
    }

    chart1->Series->Clear();
    chart1->ChartAreas->Clear();
    chart1->ChartAreas->Add("ChartArea1");

    Series^ series = gcnew Series();
    series->ChartType = SeriesChartType::Bar;

    for each (auto expense in expenses) {
        series->Points->AddXY(expense.Key, expense.Value); // Use category as label
    }

    chart1->Series->Add(series);
}

// Function to display Line Chart
void ExpenseTracker::MyForm2::DisplayLineChart() {
    auto expenses = LoadExpenseData();

    if (expenses->Count == 0) {
        MessageBox::Show("No data loaded for Line Chart.");
        return;
    }

    chart1->Series->Clear();
    chart1->ChartAreas->Clear();
    chart1->ChartAreas->Add("ChartArea1");

    Series^ series = gcnew Series();
    series->ChartType = SeriesChartType::Line;

    for each (auto expense in expenses) {
        series->Points->AddXY(expense.Key, expense.Value); // Use category as label
    }

    chart1->Series->Add(series);
}
