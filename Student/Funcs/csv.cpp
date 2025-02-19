#include "student.h"

// Save students to CSV
void saveToCSV(const string &filename) {
    ofstream file(filename);
    for (const auto &s : students) {
        file << s.toCSV() << endl;
    }
    file.close();
    cout << "Data saved to " << filename << " successfully!\n";
}

// Load students from CSV
void loadFromCSV(const string &filename) {
    ifstream file(filename);
    string line;
    students.clear();
    while (getline(file, line)) {
        students.push_back(Student::fromCSV(line));
    }
    file.close();
    cout << "Data loaded from " << filename << " successfully!\n";
}
