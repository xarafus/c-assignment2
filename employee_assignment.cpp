#include <iostream>
#include <string>
using namespace std;
const int capacity = 100;

string employees[capacity];
int numEmployee = 0;

void displayMenu() {
    cout << "Please enter 1 to add a new employee " <<endl;
    cout << "Please enter 2 to delete an employee " <<endl;
    cout << "Please enter 3 to edit an employee " <<endl;
    cout << "Please enter 4 to print the list of employees " <<endl;
    cout << "Please enter 5 to search for an employee " <<endl;
    cout << "Please enter 6 to exit " <<endl;
}

void addEmployee() {
    if (numEmployee < capacity) {
        cout << "name of the employee ";
        cin >> employees[numEmployee];
        cout << "employee added " <<endl;
        numEmployee++;} 
    else {
        cout << "list of employees is full " <<endl;}
}

void deleteEmployee() {
    if (numEmployee > 0) {
        string x_emp;
        cout << "which employee to delete ";
        cin >> x_emp;
        int search_emp = -1;
        for (int i = 0; i < numEmployee; i++) {
            if (employees[i] == x_emp) {
                search_emp = i;
                break;
            }
        }

        if (search_emp != -1) {
            for (int i = search_emp; i < numEmployee - 1; i++) {
                employees[i] = employees[i + 1];
            }
            numEmployee--;
            cout << "Employee is deleted " <<endl;} 
        else {
            cout << "wrong employee " <<endl;}
    } 
    else {
        cout << "there is no employee " <<endl;}
}

void editEmployee() {
    string x_emp;
    cout << "which employee to edit ? ";
    cin >> x_emp;
    int search_emp = -1;
    for (int i = 0; i < numEmployee; i++) {
        if (employees[i] == x_emp) {
            search_emp = i;
            break;}
    }
    if (search_emp != -1) {
        cout << "new name ? ";
        cin >> employees[search_emp];
        cout << "edited successfully " <<endl;} 
    else {
        cout << "there is no employee " <<endl;}
}

void printListEmployees() {
    if (numEmployee > 0) {
        cout << "list of employees " <<endl;
        for (int i = 0; i < numEmployee; i++) {
            cout << i + 1 << ". " << employees[i] <<endl;
        }
    } 
    else {
        cout << "there is no employee " <<endl;}
}

void searchEmployee() {
    string x_emp;
    cout << "which employee to search ? ";
    cin >> x_emp;

    int search_emp = -1;
    for (int i = 0; i < numEmployee; i++) {
        if (employees[i] == x_emp) {
            search_emp = i;
            break;}
        }

    if (search_emp != -1) {
        cout << "Employee is at the " << search_emp + 1 << ": " << employees[search_emp] <<endl;} 
    else {
        cout << "there is no employee " <<endl;}
}

int main() {
    int choice = -1;

    while (choice != 6) {
        displayMenu();
        cout << "your choice from 1 to 6";
        cin >> choice;

        switch (choice) {
            case 1:
                addEmployee();
            case 2:
                deleteEmployee();
            case 3:
                editEmployee();
            case 4:
                printListEmployees();
            case 5:
                searchEmployee();
            case 6:
                cout << "bye bye" << endl;
                break;
            default:
                cout << "please choose from 1 to 6" <<endl;
                break;
        }
    }
}
