#include "student.h"


using json = nlohmann::json;

// Save students to CSV
void saveStudentToCSV(const string &filename) {
    ofstream file(filename);
    for (const auto &s : students) {
        file << s.toCSV() << endl;
    }
    file.close();
    logEvent("Save student to CSV");
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
    logEvent("Load student from CSV");
}

// Export students to JSON
void exportStudentToJSON(const string &filename) {
    json j;
    for (const auto &s : students) {
        j.push_back({
            {"id", s.getId()},
            {"name", s.getName()},
            {"dob", s.getDob()},
            {"gender", s.getGender()},
            {"department", s.getDepartment()},
            {"course", s.getCourse()},
            {"program", s.getProgram()},
            {"address", s.getAddress()},
            {"email", s.getEmail()},
            {"phone", s.getPhone()},
            {"status", s.getStatus()},
            {"creationTime", Student::timePointToString(s.getCreationTime())}
        });
    }
    
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file for writing: " << filename << endl;
        return;
    }
    file << j.dump(4);
    file.close();
    logEvent("Exported students to JSON");
}

// Import students from JSON
void importStudentFromJSON(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file for reading: " << filename << endl;
        return;
    }
    
    json j;
    file >> j;
    file.close();
    
    students.clear();
    for (const auto &s : j) {
        Student student(
            s["id"], s["name"], s["dob"], s["gender"], s["department"],
            s["course"], s["program"], s["address"], s["email"], s["phone"], s["status"]
        );
        student.setCreationTime(Student::stringToTimePoint(s["creationTime"]));
        students.push_back(student);
    }
    logEvent("Imported students from JSON");
}