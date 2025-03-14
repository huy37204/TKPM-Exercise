#include "student_exporter.h"
#include <fstream>
#include <sstream>
#include <ctime>
#include "../../json.hpp"

using namespace std;

string StudentExporter::toCSV(const Student &student) {
    stringstream ss;
    ss << student.getId() << "," << student.getName() << "," << student.getDob() << ","
       << student.getGender() << "," << student.getDepartment() << "," << student.getCourse() << ","
       << student.getProgram() << "," << student.getAddress() << "," << student.getEmail() << ","
       << student.getPhone() << "," << student.getStatus() << "," << student.getPurpose() << ","
       << Student::timePointToString(student.getCreationTime());
    return ss.str();
}

Student StudentExporter::fromCSV(const string &csvLine) {
    stringstream ss(csvLine);
    string id, name, dob, gender, department, course, program, address, email, phone, status, purpose, creationTimeStr;
    getline(ss, id, ',');
    getline(ss, name, ',');
    getline(ss, dob, ',');
    getline(ss, gender, ',');
    getline(ss, department, ',');
    getline(ss, course, ',');
    getline(ss, program, ',');
    getline(ss, address, ',');
    getline(ss, email, ',');
    getline(ss, phone, ',');
    getline(ss, status, ',');
    getline(ss, purpose, ',');
    getline(ss, creationTimeStr, ',');

    Student student(id, name, dob, gender, department, course, program, address, email, phone, status);
    student.setPurpose(purpose);
    student.setCreationTime(Student::stringToTimePoint(creationTimeStr));
    return student;
}

void StudentExporter::saveStudentToCSV(const string &filename) {
    ofstream file(filename);
    for (const auto &student : students) {
        file << StudentExporter::toCSV(student) << endl;
    }
    file.close();
    logEvent("Save student to CSV");
}

void StudentExporter::loadStudentFromCSV(const string &filename) {
    ifstream file(filename);
    string line;
    students.clear();
    while (getline(file, line)) {
        students.push_back(StudentExporter::fromCSV(line));
    }
    file.close();
    logEvent("Load student from CSV");
}

void StudentExporter::exportStudentToJSON(const string &filename) {
    nlohmann::json j;
    for (const auto &student : students) {
        j.push_back({
            {"id", student.getId()},
            {"name", student.getName()},
            {"dob", student.getDob()},
            {"gender", student.getGender()},
            {"department", student.getDepartment()},
            {"course", student.getCourse()},
            {"program", student.getProgram()},
            {"address", student.getAddress()},
            {"email", student.getEmail()},
            {"phone", student.getPhone()},
            {"status", student.getStatus()},
            {"purpose", student.getPurpose()},
            {"creationTime", Student::timePointToString(student.getCreationTime())}
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

void StudentExporter::importStudentFromJSON(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file for reading: " << filename << endl;
        return;
    }
    
    nlohmann::json j;
    file >> j;
    file.close();
    
    students.clear();
    for (const auto &item : j) {
        Student student(
            item["id"], item["name"], item["dob"], item["gender"],
            item["department"], item["course"], item["program"],
            item["address"], item["email"], item["phone"], item["status"]
        );
        student.setPurpose(item["purpose"]);
        student.setCreationTime(Student::stringToTimePoint(item["creationTime"]));
        students.push_back(student);
    }
    logEvent("Imported students from JSON");
}