#pragma once

using namespace System;

// Define a simple class to represent actions for undo/redo
ref class ExpenseAction {
public:
    String^ actionType;  // "add" or "delete"
    String^ name;
    String^ amount;
    String^ category;
    String^ date;

    // Constructor
    ExpenseAction(String^ action, String^ name, String^ amt, String^ cat, String^ dt) {
        this->actionType = action;
        this->name = name;
        this->amount = amt;
        this->category = cat;
        this->date = dt;
    }
};
