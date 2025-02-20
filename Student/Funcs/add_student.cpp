#include "student.h"


// Add new student
void addStudent() {
    string id, name, dob, gender, department, course, program, address, email, phone, status;
    cout << "Enter Student ID: "; cin >> id;
    cin.ignore();
    cout << "Enter Name: "; getline(cin, name);
    cout << "Enter Date of Birth (dd/mm/yyyy): "; getline(cin, dob);
    cout << "Enter Gender (Male/Female): "; getline(cin, gender);
    string departmentRequest =  "Enter Department (";
    for (int i = 0; i < validDepartments.size(); i++){
        if (i == (validDepartments.size() - 1))
            departmentRequest += (validDepartments[i] + "): ");
        else departmentRequest += (validDepartments[i] + ", ");
    }
    do {
        cout << departmentRequest;
        getline(cin, department);
        if (!isValidDepartment(department)) {
            cout << "Invalid department! Please enter again.\n";
        }
    } while (!isValidDepartment(department));
    
    cout << "Enter Course: "; getline(cin, course);
    do {
        cout << "Enter Program: (Chinh quy, Lien thong, CLC, Tien tien): "; getline(cin, program);
        if (!isValidPrograms(program)) {
            cout << "Invalid program! Please enter again\n";
        }
    }while(!isValidPrograms(program));
    cout << "Enter Address: "; getline(cin, address);
    
    do {
        cout << "Enter Email (must contain @): "; getline(cin, email);
        if (!isValidEmail(email)) {
            cout << "Invalid email format! Try again.\n";
        }
    } while (!isValidEmail(email));
    
    do {
        cout << "Enter Phone (10 digits): "; getline(cin, phone);
        if (!isValidPhone(phone)) {
            cout << "Invalid phone number! Try again.\n";
        }
    } while (!isValidPhone(phone));
    
    do {
        cout << "Enter Status (Dang hoc, Da tot nghiep, Da thoi hoc, Tam dung hoc): ";
        getline(cin, status);
        if (!isValidStatus(status)) {
            cout << "Invalid student status! Try again.\n";
        }
    } while (!isValidStatus(status));
    
    students.emplace_back(id, name, dob, gender, department, course, program, address, email, phone, status);
    cout << "Student added successfully!\n";
    saveStudentToCSV("students.csv");
}