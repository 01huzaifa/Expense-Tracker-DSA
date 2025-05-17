#pragma once
#include "ExpenseNode.h"
using namespace System::Collections::Generic;

ref class ExpenseList {
private:
    // MergeSort implementation for linked list based on field and direction
    ExpenseNode^ MergeSort(ExpenseNode^ head, System::String^ sortField, bool ascending) {
        if (head == nullptr || head->next == nullptr) return head;

        // Split the linked list into halves
        ExpenseNode^ middle = GetMiddle(head);
        ExpenseNode^ secondHalf = middle->next;
        middle->next = nullptr;

        // Sort each half
        ExpenseNode^ left = MergeSort(head, sortField, ascending);
        ExpenseNode^ right = MergeSort(secondHalf, sortField, ascending);

        // Merge sorted halves
        return Merge(left, right, sortField, ascending);
    }

    ExpenseNode^ Merge(ExpenseNode^ left, ExpenseNode^ right, System::String^ sortField, bool ascending) {
        ExpenseNode^ result = nullptr;

        if (left == nullptr) return right;
        if (right == nullptr) return left;

        bool comparison = false;
        if (sortField == "amount") {
            comparison = (ascending ? System::Decimal::Parse(left->amount) <= System::Decimal::Parse(right->amount)
                : System::Decimal::Parse(left->amount) > System::Decimal::Parse(right->amount));
        }
        else if (sortField == "date") {
            comparison = (ascending ? System::DateTime::Parse(left->date) <= System::DateTime::Parse(right->date)
                : System::DateTime::Parse(left->date) > System::DateTime::Parse(right->date));
        }

        if (comparison) {
            result = left;
            result->next = Merge(left->next, right, sortField, ascending);
        }
        else {
            result = right;
            result->next = Merge(left, right->next, sortField, ascending);
        }
        return result;
    }

    ExpenseNode^ GetMiddle(ExpenseNode^ node) {
        ExpenseNode^ slow = node;
        ExpenseNode^ fast = node->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

public:
    ExpenseNode^ head;

    ExpenseList() {
        head = nullptr;
    }

    // Sort expenses by amount (ascending or descending)
    void SortByAmount(bool ascending) {
        head = MergeSort(head, "amount", ascending);
    }

    // Sort expenses by date (ascending or descending)
    void SortByDate(bool ascending) {
        head = MergeSort(head, "date", ascending);
    }

    // Add new expense at the top (head) of the list
    void AddExpense(System::String^ name, System::String^ amt, System::String^ cat, System::String^ dt) {
        ExpenseNode^ newNode = gcnew ExpenseNode(name, amt, cat, dt);

        // Insert at the top of the list (head)
        newNode->next = head;
        head = newNode;
    }

    // Clear the list
    void Clear() {
        head = nullptr;
    }

    // Delete a specific expense by name
    bool DeleteExpense(System::String^ name, System::String^ amount, System::String^ category, System::String^ date) {
        ExpenseNode^ current = head;
        ExpenseNode^ previous = nullptr;

        while (current != nullptr) {
            if (current->expenseName->Equals(name)) {
                if (previous == nullptr) {
                    // Deleting head node
                    head = current->next;
                }
                else {
                    // Deleting non-head node
                    previous->next = current->next;
                }
                return true;
            }
            previous = current;
            current = current->next;
        }
        return false;  // Expense not found
    }


    List<ExpenseNode^>^ ExpenseList::SearchExpenses(System::String^ searchTerm) {
        List<ExpenseNode^>^ results = gcnew List<ExpenseNode^>();
        ExpenseNode^ current = head;

        // Convert the search term to lowercase to make it case-insensitive
        searchTerm = searchTerm->ToLower();

        while (current != nullptr) {
            // Check if the expense name contains the search term, ignoring case
            if (current->expenseName->ToLower()->Contains(searchTerm)) {
                results->Add(current);  // Add matching node to results
            }
            current = current->next;
        }
        return results;  // Return list of matching expenses
    }

};
