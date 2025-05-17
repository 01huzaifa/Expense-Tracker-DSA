#include "ExpenseForm.h"
#include "ExpenseList.h"
#include "ExpenseAction.h"



using namespace System;
using namespace System::IO;
using namespace System::Windows::Forms;
using namespace ExpenseTracker;


void ExpenseForm::LoadExpenses()
{
    dataGridView1->Rows->Clear(); // Clear existing data
    expenses->Clear();  // Clear the linked list

    // Open and read user-specific file
    if (System::IO::File::Exists("C:\\Users\\Huzaifa\\Desktop\\ExpenseTracker - Copy\\ExpenseTracker\\UserData\\" + username + "_expenses.txt")) {
        System::IO::StreamReader^ sr = gcnew System::IO::StreamReader("C:\\Users\\Huzaifa\\Desktop\\ExpenseTracker - Copy\\ExpenseTracker\\UserData\\" + username + "_expenses.txt");

        while (!sr->EndOfStream) {
            System::String^ line = sr->ReadLine();
            cli::array<System::String^>^ expenseDetails = line->Split(',');

            // Populate DataGridView row
            if (expenseDetails->Length == 4) {
                // Add expense to the linked list as well
                expenses->AddExpense(expenseDetails[0], expenseDetails[1], expenseDetails[2], expenseDetails[3]);
                dataGridView1->Rows->Add(expenseDetails[0], expenseDetails[1], expenseDetails[2], expenseDetails[3]);
            }
        }
        sr->Close();
    }
}

void ExpenseForm::AddExpense() {
    // Get the input values
    String^ expenseName = textBox1->Text;
    String^ amount = textBox3->Text;
    String^ category = comboBox1->Text;

    // Validate the input fields
    if (IsInputValid(expenseName, amount, category)) {
        String^ date = dateTimePicker1->Value.ToString("yyyy-MM-dd");

        // Save the action to the undo stack
        ExpenseAction^ action = gcnew ExpenseAction("add", expenseName, amount, category, date);
        undoStack->Push(action);

        // Add the expense to the list and update DataGridView
        expenses->AddExpense(expenseName, amount, category, date);
        RefreshDataGrid();  // Refresh grid after adding to keep it in sync

        // Save the new expense to the user-specific text file
        SaveExpenseToFile(expenseName, amount, category, date);

        // Clear the redo stack since a new action was performed
        redoStack->Clear();
    }
}


void ExpenseForm::SaveExpenseToFile(String^ expenseName, String^ amount, String^ category, String^ date)
{
    // Construct the file path for the user-specific expenses file
    String^ filePath = "C:\\Users\\Huzaifa\\Desktop\\ExpenseTracker - Copy\\ExpenseTracker\\UserData\\" + username + "_expenses.txt";

    // Create a StreamWriter to overwrite the file with the updated expenses
    StreamWriter^ sw = gcnew StreamWriter(filePath, false);  // 'false' ensures we overwrite the file

    // First, write the new expense at the top
    sw->WriteLine(expenseName + "," + amount + "," + category + "," + date);

    // Now, write the rest of the expenses (if any) in order from head to tail
    ExpenseNode^ current = expenses->head;
    while (current != nullptr) {
        sw->WriteLine(current->expenseName + "," + current->amount + "," + current->category + "," + current->date);
        current = current->next;
    }

    // Close the file after writing
    sw->Close();
}



// Helper method for validating input
bool ExpenseForm::IsInputValid(String^ expenseName, String^ amount, String^ category)
{
    // Check if any field is empty
    if (String::IsNullOrEmpty(expenseName) || String::IsNullOrEmpty(amount) || String::IsNullOrEmpty(category)) {
        ShowError("Please fill in all the fields.");
        return false;
    }

    // Validate that amount is a valid positive number
    double parsedAmount;
    if (!Double::TryParse(amount, parsedAmount) || parsedAmount <= 0) {
        ShowError("Please enter a valid positive number for the amount.");
        return false;
    }

    return true;
}

// Helper method to show error messages
void ExpenseForm::ShowError(String^ message)
{
    MessageBox::Show(message, "Input Error", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
}
void ExpenseForm::OnSearchButtonClick(System::Object^ sender, System::EventArgs^ e) {
    // Get the search term from the TextBox
    String^ searchTerm = textBox2->Text;

    // If the search term is empty, refresh the DataGridView with all expenses
    if (searchTerm->Trim()->Length == 0) {
        RefreshDataGrid();  // Refresh the grid with all expenses
        return;  // Exit the method early
    }

    // Use the search function from the ExpenseList class
    System::Collections::Generic::List<ExpenseNode^>^ results = expenses->SearchExpenses(searchTerm);

    // Clear the DataGridView to prepare for displaying the search results
    dataGridView1->Rows->Clear();

    if (results->Count > 0) {
        // Populate DataGridView with the search results
        for each (ExpenseNode ^ node in results) {
            dataGridView1->Rows->Add(node->expenseName, node->amount, node->category, node->date);
        }
    }
    else {
        // Show a message if no matching expenses were found
        MessageBox::Show("No matching expenses found.");
    }
}


void ExpenseForm::DeleteSelectedExpense() {
    if (dataGridView1->SelectedRows->Count > 0) {
        DataGridViewRow^ selectedRow = dataGridView1->SelectedRows[0];

        if (selectedRow->Cells[0]->Value != nullptr) {
            String^ expenseName = selectedRow->Cells[0]->Value->ToString();
            String^ amount = selectedRow->Cells[1]->Value->ToString();
            String^ category = selectedRow->Cells[2]->Value->ToString();
            String^ date = selectedRow->Cells[3]->Value->ToString();

            // Save the action to the undo stack (for redo purposes)
            ExpenseAction^ action = gcnew ExpenseAction("delete", expenseName, amount, category, date);
            undoStack->Push(action);

            // Delete the expense from the list
            expenses->DeleteExpense(expenseName, amount, category, date);

            // Update the file to reflect the deletion
            SaveAllExpensesToFile();

            // Refresh the DataGridView to show updated data
            RefreshDataGrid();

            // Clear the redo stack since a new action was performed
            redoStack->Clear();
        }
    }
}

void ExpenseForm::RefreshDataGrid() {
    dataGridView1->Rows->Clear();
    ExpenseNode^ current = expenses->head;
    while (current != nullptr) {
        dataGridView1->Rows->Add(current->expenseName, current->amount, current->category, current->date);
        current = current->next;
    }
}
void ExpenseForm::Undo() {
    if (undoStack->Count > 0) {
        ExpenseAction^ lastAction = undoStack->Pop();

        // Undo the action based on the actionType
        if (lastAction->actionType == "add") {
            expenses->DeleteExpense(lastAction->name, lastAction->amount, lastAction->category, lastAction->date);

            // Update the file to remove the expense
            SaveAllExpensesToFile();
            RefreshDataGrid();  // Refresh the grid to reflect the change
        }
        else if (lastAction->actionType == "delete") {
            expenses->AddExpense(lastAction->name, lastAction->amount, lastAction->category, lastAction->date);

            // Update the file to add back the expense
            SaveAllExpensesToFile();
            RefreshDataGrid();  // Refresh the grid to reflect the change
        }

        // Save the undone action in the redo stack
        redoStack->Push(lastAction);
    }
    else {
        MessageBox::Show("No actions to undo.");
    }
}

void ExpenseForm::Redo() {
    if (redoStack->Count > 0) {
        ExpenseAction^ lastAction = redoStack->Pop();

        // Redo the action based on the actionType
        if (lastAction->actionType == "add") {
            expenses->AddExpense(lastAction->name, lastAction->amount, lastAction->category, lastAction->date);

            // Update the file to add the expense
            SaveAllExpensesToFile();
            RefreshDataGrid();  // Refresh the grid to reflect the change
        }
        else if (lastAction->actionType == "delete") {
            expenses->DeleteExpense(lastAction->name, lastAction->amount, lastAction->category, lastAction->date);

            // Update the file to remove the expense
            SaveAllExpensesToFile();
            RefreshDataGrid();  // Refresh the grid to reflect the change
        }

        // Save the redone action in the undo stack
        undoStack->Push(lastAction);
    }
    else {
        MessageBox::Show("No actions to redo.");
    }
}
void ExpenseForm::SaveAllExpensesToFile() {
    // Construct the file path for the user-specific expenses file
    String^ filePath = "C:\\Users\\Huzaifa\\Desktop\\ExpenseTracker - Copy\\ExpenseTracker\\UserData\\" + username + "_expenses.txt";

    // Create a StreamWriter to overwrite the file with the updated expenses
    StreamWriter^ sw = gcnew StreamWriter(filePath, false);  // 'false' ensures we overwrite the file

    // Write the rest of the expenses in order from head to tail
    ExpenseNode^ current = expenses->head;
    while (current != nullptr) {
        sw->WriteLine(current->expenseName + "," + current->amount + "," + current->category + "," + current->date);
        current = current->next;
    }

    // Close the file after writing
    sw->Close();
}

void ExpenseForm::FilterByCategory(System::String^ category) {
    // Clear DataGridView to prepare for filtered display
    dataGridView1->Rows->Clear();

    // If "All" is selected, show all expenses
    if (category == "All") {
        // Reload all expenses
        LoadExpenses();
        return;
    }

    // Iterate through the linked list to find matching expenses
    ExpenseNode^ current = expenses->head;
    while (current != nullptr) {
        // Check if the expense's category matches the selected category
        if (current->category->Equals(category)) {
            // Add matching expense to DataGridView
            dataGridView1->Rows->Add(current->expenseName, current->amount, current->category, current->date);
        }
        current = current->next;
    }
}
