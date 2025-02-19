#include "student.h"

// Menu
void menu() {
    int choice;
    loadFromCSV("students.csv");
    do {
        cout << "\nStudent Management System";
        cout << "\n1. Add Student";
        cout << "\n2. Delete Student";
        cout << "\n3. Update Student";
        cout << "\n4. Search Student";
        cout << "\n5. Exit";
        cout << "\nChoose an option: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1: addStudent(); break;
            case 2: deleteStudent(); break;
            case 3: updateStudent(); break;
            case 4: searchStudent(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 7);
}