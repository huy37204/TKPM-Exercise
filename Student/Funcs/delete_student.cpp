#include "student.h"

// Delete student
void deleteStudent() {
    string id;
    cout << "Enter Student ID to delete: "; cin >> id;
    cout << id << endl;
    students.erase(remove_if(students.begin(), students.end(),
                             [&id](const Student &s) { return s.getId() == id; }),
                   students.end());
    saveStudentToCSV("students.csv");
    exportStudentToJSON("student.json");
    cout << "Student deleted successfully!\n";
    logEvent("Delete student");
}
