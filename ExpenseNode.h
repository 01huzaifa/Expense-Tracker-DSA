// ExpenseNode.h
#pragma once

using namespace System;

ref class ExpenseNode {
public:
    System::String^ expenseName;
    System::String^ amount;
    System::String^ category;
    System::String^ date;
    ExpenseNode^ next;

    ExpenseNode(System::String^ name, System::String^ amt, System::String^ cat, System::String^ dt) {
        expenseName = name;
        amount = amt;
        category = cat;
        date = dt;
        next = nullptr;
    }
};

