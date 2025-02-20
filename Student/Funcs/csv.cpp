#include "student.h"

// Save students to CSV
void saveStudentToCSV(const string &filename) {
    ofstream file(filename);
    for (const auto &s : students) {
        file << s.toCSV() << endl;
    }
    file.close();
}

// Load students from CSV
void loadStudentFromCSV(const string &filename) {
    ifstream file(filename);
    string line;
    students.clear();
    while (getline(file, line)) {
        students.push_back(Student::fromCSV(line));
    }
    file.close();
}
