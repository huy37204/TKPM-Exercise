#include "Student.h"
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

// Setters
void Student::setName(const string &newName) { name = newName; }

// Display student info
void Student::display() const {
    cout << "ID: " << id << ", Name: " << name << ", DOB: " << dob
         << ", Gender: " << gender << ", Department: " << department
         << ", Course: " << course << ", Program: " << program
         << ", Address: " << address << ", Email: " << email
         << ", Phone: " << phone << ", Status: " << status << endl;
}

// Convert student info to CSV format
string Student::toCSV() const {
    return id + "," + name + "," + dob + "," + gender + "," + department + "," +
           course + "," + program + "," + address + "," + email + "," + phone + "," + status;
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
    getline(ss, address, ',');
    getline(ss, email, ',');
    getline(ss, phone, ',');
    getline(ss, status, ',');
    return Student(id, name, dob, gender, department, course, program, address, email, phone, status);
}

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

// Add new student
void addStudent() {
    string id, name, dob, gender, department, course, program, address, email, phone, status;
    cout << "Enter Student ID: "; cin >> id;
    cin.ignore();
    cout << "Enter Name: "; getline(cin, name);
    cout << "Enter Date of Birth (dd/mm/yyyy): "; getline(cin, dob);
    cout << "Enter Gender: "; getline(cin, gender);
    cout << "Enter Department: "; getline(cin, department);
    cout << "Enter Course: "; getline(cin, course);
    cout << "Enter Program: "; getline(cin, program);
    cout << "Enter Address: "; getline(cin, address);
    cout << "Enter Email: "; getline(cin, email);
    cout << "Enter Phone: "; getline(cin, phone);
    cout << "Enter Status: "; getline(cin, status);
    students.emplace_back(id, name, dob, gender, department, course, program, address, email, phone, status);
    cout << "Student added successfully!\n";
    saveToCSV("students.csv");
}



