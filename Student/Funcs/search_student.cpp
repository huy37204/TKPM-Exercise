#include "student.h"

// Search student by Name or ID
void searchStudent() {
    string keyword;
    cout << "Enter Name or ID to search: ";
    getline(cin, keyword);
    for (const auto &s : students) {
        if (s.getId() == keyword || s.getName().find(keyword) != string::npos) {
            s.display();
        }
    }
    logEvent("Search student by ID and name");
}

// Search student by Department
void searchStudentByDepartment() {
    string department;
    cout << "Enter Department to search: ";
    getline(cin, department);
    for (const auto &s : students) {
        if (s.getDepartment() == department) {
            s.display();
        }
    }
    logEvent("Search student by department");
}

// Search student by Department and Name
void searchStudentByDepartmentAndName() {
    string department, name;
    cout << "Enter Department to search: ";
    getline(cin, department);
    cout << "Enter Name to search: ";
    getline(cin, name);
    for (const auto &s : students) {
        if (s.getDepartment() == department && s.getName().find(name) != string::npos) {
            s.display();
        }
    }
    logEvent("Search student by department and name");
}
