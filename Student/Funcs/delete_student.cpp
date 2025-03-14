#include "student.h"
#include "student_exporter.h"
#include <chrono>
#include "config.h"


void deleteStudent() {
    string id = deleteStudentInteractive();
    if (deleteStudentById(id)) {
        StudentExporter::saveStudentToCSV("students.csv");
        StudentExporter::exportStudentToJSON("student.json");
        cout << "Student deleted successfully!\n";
        logEvent("Delete student");
    } else {
        cout << "Failed to delete student.\n";
    }
}

string deleteStudentInteractive() {
    string id;
    cout << "Enter Student ID to delete: ";
    cin >> id;
    return id;
}

bool deleteStudentById(const string &id) {
    auto it = find_if(students.begin(), students.end(), [&id](const Student &s) {
        return s.getId() == id;
    });

    if (it != students.end()) {
        auto now = chrono::system_clock::now();
        auto creationTime = it->getCreationTime();
        auto duration = chrono::duration_cast<chrono::minutes>(now - creationTime);

        if (!config.rule05_enabled || duration.count() <= 30) { 
            students.erase(it);
            return true;
        } else {
            cout << "Cannot delete student. The allowed time frame for deletion has passed." << endl;
            return false;
        }
    } else {
        cout << "Student not found." << endl;
        return false;
    }
}