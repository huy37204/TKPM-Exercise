#include "student.h"
#include <iostream>
#include <vector>

using namespace std;


// Hàm xử lý logic thêm sinh viên, không có cin/cout (dễ test)
bool addStudent(const string& id, const string& name, const string& dob, const string& gender, 
                const string& department, const string& course, const string& program, 
                const string& address, const string& email, const string& phone, 
                const string& status) {
    
    if (!isValidStudentId(id)) return false;
    if (!isValidDepartment(department)) return false;
    if (!isValidPrograms(program)) return false;
    if (!isValidEmail(email)) return false;
    if (!isValidPhone(phone)) return false;
    if (!isValidStatus(status)) return false;

    students.emplace_back(id, name, dob, gender, department, course, program, address, email, phone, status);
    
    saveStudentToCSV("students.csv");
    exportStudentToJSON("student.json");

    // Log event
    logEvent("Added new student: ID = " + id + ", Name = " + name);
    return true;
}

// Hàm tương tác với người dùng, giữ lại cin/cout
void addStudentInteractive() {
    string id, name, dob, gender, department, course, program, address, email, phone, status;
    
    do {
        cout << "Enter Student ID: "; cin >> id;
        if (!isValidStudentId(id)) {
            cout << "Student ID has already existed! Please enter again.\n";
        }
    } while (!isValidStudentId(id));

    cin.ignore();
    cout << "Enter Name: "; getline(cin, name);
    cout << "Enter Date of Birth (dd/mm/yyyy): "; getline(cin, dob);
    cout << "Enter Gender (Male/Female): "; getline(cin, gender);
    // Department   
    string departmentRequest =  "Enter Department (";
    for (int i = 0; i < validDepartments.size(); i++){
        if (i == (validDepartments.size() - 1))
            departmentRequest += (validDepartments[i] + "): ");
        else departmentRequest += (validDepartments[i] + ", ");
    }

    do {
      cout << departmentRequest;  getline(cin, department);
        if (!isValidDepartment(department)) {
            cout << "Invalid department! Please enter again.\n";
        }
    } while (!isValidDepartment(department));
    // Course
    cout << "Enter Course: "; getline(cin, course);
    // Program
    string programRequest =  "Enter program (";
    for (int i = 0; i < validPrograms.size(); i++){
        if (i == (validPrograms.size() - 1))
        programRequest += (validPrograms[i] + "): ");
        else programRequest += (validPrograms[i] + ", ");
    }
    do {
        cout << programRequest; getline(cin, program);
        if (!isValidPrograms(program)) {
            cout << "Invalid program! Please enter again.\n";
        }
    } while (!isValidPrograms(program));
    // Address 
    cout << "Enter Address: "; getline(cin, address);

    do {
        cout << "Enter Email (must be with type " + allowedDomain +"): "; getline(cin, email);
        if (!isValidEmail(email)) {
            cout << "Invalid email! Try again.\n";
        }
    } while (!isValidEmail(email));

    // Phone
    do {
        cout << "Enter Phone (10 digits), must be in Vietnam: "; getline(cin, phone);
        if (!isValidPhone(phone)) {
            cout << "Invalid phone number! Try again.\n";
        }
    } while (!isValidPhone(phone));
    //Status
    string statusRequest =  "Enter Status (";
    for (int i = 0; i < validStatuses.size(); i++){
        if (i == (validStatuses.size() - 1))
        statusRequest += (validStatuses[i] + "): ");
        else statusRequest += (validStatuses[i] + ", ");
    }
    do {
      cout << statusRequest; getline(cin, status);
        if (!isValidStatus(status)) {
            cout << "Invalid status! Please enter again.\n";
        }
    } while (!isValidStatus(status));

    if (addStudent(id, name, dob, gender, department, course, program, address, email, phone, status)) {
        cout << "Student added successfully!\n";
    } else {
        cout << "Failed to add student. Please check input values.\n";
    }
}
