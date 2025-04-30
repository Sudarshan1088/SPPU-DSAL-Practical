#include <iostream>
#include <fstream>
using namespace std;

struct Student {
    int roll_number;
    string name, address;
    char division;
};

void add_student() {
    Student s;
    cout << "Enter the roll number: ";
    cin >> s.roll_number;
    cout << "Enter the name: ";
    cin >> s.name;
    cout << "Enter the division: ";
    cin >> s.division;
    cout << "Enter the address: ";
    cin >> s.address;

    ofstream file("students.txt", ios::app);
    file << s.roll_number << "\n" << s.name << "\n" << s.division << "\n" << s.address << "\n";
    file.close();
}

void display_student(const Student& s) {
    cout << "Roll Number: " << s.roll_number << "\n"
         << "Name: " << s.name << "\n"
         << "Division: " << s.division << "\n"
         << "Address: " << s.address << "\n\n";
}

void read_students() {
    Student s;
    ifstream file("students.txt");
    while (file >> s.roll_number >> s.name >> s.division >> s.address) {
        display_student(s);
    }
    file.close();
}

bool search_student(int roll_number) {
    Student s;
    ifstream file("students.txt");
    while (file >> s.roll_number >> s.name >> s.division >> s.address) {
        if (s.roll_number == roll_number) {
            display_student(s);
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

void delete_student(int roll_number) {
    if (!search_student(roll_number)) {
        cout << "Record not found.\n";
        return;
    }

    Student s;
    ifstream file("students.txt");
    ofstream temp("temp.txt");
    
    while (file >> s.roll_number >> s.name >> s.division >> s.address) {
        if (s.roll_number != roll_number) {
            temp << s.roll_number << "\n" << s.name << "\n" << s.division << "\n" << s.address << "\n";
        }
    }

    file.close();
    temp.close();
    remove("students.txt");
    rename("temp.txt", "students.txt");
    cout << "Student record deleted successfully!\n";
}

int main() {
    int choice, roll_number;
    
    do {
        cout << "\n-----STUDENT RECORDS-----\n";
        cout << "1. Add record\n2. Display records\n3. Search record\n4. Delete record\n0. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                read_students();
                break;
            case 3:
                cout << "Enter roll number to search: ";
                cin >> roll_number;
                if (!search_student(roll_number)) {
                    cout << "Record not found!\n";
                }
                break;
            case 4:
                cout << "Enter roll number to delete: ";
                cin >> roll_number;
                delete_student(roll_number);
                break;
            case 0:
                break;
            default:
                cout << "Invalid option. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
