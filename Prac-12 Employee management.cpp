#include <iostream>
#include <string>
#define MAX 20
using namespace std;

struct Employee {
    string name;
    long int code;
    string designation;
    int sal;
};

Employee emp[MAX];
int num = 0;

void showMenu();
void insert();
void deleteIndex(int i);
void deleteRecord();
void searchRecord();
void build();

void build() {
    cout << "Maximum Entries allowed: " << MAX << "\n";
    cout << "Enter the number of entries required: ";
    cin >> num;
    if (num > MAX) {
        cout << "Maximum number of entries are " << MAX << ".\n";
        num = MAX;
    }

    cout << "Enter the following data:\n";
    for (int i = 0; i < num; i++) {
        cout << "Name: ";
        cin >> emp[i].name;
        cout << "Employee ID: ";
        cin >> emp[i].code;
        cout << "Designation: ";
        cin >> emp[i].designation;
        cout << "Salary: ";
        cin >> emp[i].sal;
    }
    showMenu();
}

void insert() {
    if (num < MAX) {
        cout << "Enter information for new employee:\n";
        cout << "Name: ";
        cin >> emp[num].name;
        cout << "Employee ID: ";
        cin >> emp[num].code;
        cout << "Designation: ";
        cin >> emp[num].designation;
        cout << "Salary: ";
        cin >> emp[num].sal;
        num++;
    } else {
        cout << "Employee record limit reached.\n";
    }
    showMenu();
}

void deleteIndex(int i) {
    for (int j = i; j < num - 1; j++) {
        emp[j] = emp[j + 1];
    }
    num--;
}

void deleteRecord() {
    cout << "Enter the Employee ID to delete record: ";
    int code;
    cin >> code;
    for (int i = 0; i < num; i++) {
        if (emp[i].code == code) {
            deleteIndex(i);
            break;
        }
    }
    showMenu();
}

void searchRecord() {
    cout << "Enter the Employee ID to search record: ";
    int code;
    cin >> code;
    for (int i = 0; i < num; i++) {
        if (emp[i].code == code) {
            cout << "Name: " << emp[i].name << "\n";
            cout << "Employee ID: " << emp[i].code << "\n";
            cout << "Designation: " << emp[i].designation << "\n";
            cout << "Salary: " << emp[i].sal << "\n";
            break;
        }
    }
    showMenu();
}

void showMenu() {
    cout << "----------------- Employee Management System -----------------\n";
    cout << "1. Insert New Entry\n";
    cout << "2. Delete Entry\n";
    cout << "3. Search a Record\n";
    cout << "4. Exit\n";
    int option;
    cin >> option;

    switch (option) {
        case 1: insert(); break;
        case 2: deleteRecord(); break;
        case 3: searchRecord(); break;
        case 4: return;
        default: 
            cout << "Invalid option! Please choose between 1 to 4.\n";
            showMenu();
    }
}

int main() {
    build();
    return 0;
}
