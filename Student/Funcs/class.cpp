#include "student.h"
#include <fstream>
#include <sstream>
#include <algorithm>

vector<Student> students;

// Constructors
Student::Student() {}

Student::Student(string id, string name, string dob, string gender, string department, string course,
                 string program, string address, string email, string phone, string status)
        : id(id), name(name), dob(dob), gender(gender), department(department),
          course(course), program(program), address(address), email(email), phone(phone), status(status) {}


    // Getters
    string Student::getId() const { return id; }
    string Student::getName() const { return name; }
    string Student::getDob() const { return dob; }
    string Student::getGender() const { return gender; }
    string Student::getDepartment() const { return department; }
    string Student::getCourse() const { return course; }
    string Student::getProgram() const { return program; }
    string Student::getAddress() const { return address; }
    string Student::getEmail() const { return email; }
    string Student::getPhone() const { return phone; }
    string Student::getStatus() const { return status; }

    // Setters
    void Student::setId(const string &newId) { id = newId; }
    void Student::setName(const string &newName) { name = newName; }
    void Student::setDob(const string &newDob) { dob = newDob; }
    void Student::setGender(const string &newGender) { gender = newGender; }
    void Student::setDepartment(const string &newDepartment) { department = newDepartment; }
    void Student::setCourse(const string &newCourse) { course = newCourse; }
    void Student::setProgram(const string &newProgram) { program = newProgram; }
    void Student::setAddress(const string &newAddress) { address = newAddress; }
    void Student::setEmail(const string &newEmail) { email = newEmail; }
    void Student::setPhone(const string &newPhone) { phone = newPhone; }
    void Student::setStatus(const string &newStatus) { status = newStatus; }

// Display student info
void Student::display() const {
    cout << "ID: " << id << ", Name: " << name << ", DOB: " << dob
         << ", Gender: " << gender << ", Department: " << department
         << ", Course: " << course << ", Program: " << program
         << ", Address: " << address << ", Email: " << email
         << ", Phone: " << phone << ", Status: " << status << endl;

        logEvent("Display student");
}

// Convert student info to CSV format
string Student::toCSV() const {
    // Add * because address has ","
    return id + "," + name + "," + dob + "," + gender + "," + department + "," +
           course + "," + program + "," + address + "*"  + email + "," + phone + "," + status;
}

// Load student from CSV
Student Student::fromCSV(const string &csvLine) {
    stringstream ss(csvLine);
    string id, name, dob, gender, department, course, program, address, email, phone, status;
    getline(ss, id, ',');
    getline(ss, name, ',');
    getline(ss, dob, ',');
    getline(ss, gender, ',');
    getline(ss, department, ',');
    getline(ss, course, ',');
    getline(ss, program, ',');
    getline(ss, address, '*');
    getline(ss, email, ',');
    getline(ss, phone, ',');
    getline(ss, status, ',');
    return Student(id, name, dob, gender, department, course, program, address, email, phone, status);
}


// Validation


