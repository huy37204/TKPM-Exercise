#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include "../../Validation/validate.h"
#include "../../Department/department.h"
#include "../../Status/status.h"
#include "../../Program/program.h"
#include "../../LogEvent/log_event.h"
#include "../../ShowVersion/show_version.h"
#include "../../json.hpp"

using namespace std;


class Student {
private:
    string id, name, dob, gender, department, course, program, address, email, phone, status;

public:
    Student();
    Student(string id, string name, string dob, string gender, string department, string course,
            string program, string address, string email, string phone, string status);

    // Getters
    string getId() const;
    string getName() const;
    string getDob() const;
    string getGender() const;
    string getDepartment() const;
    string getCourse() const;
    string getProgram() const;
    string getAddress() const;
    string getEmail() const;
    string getPhone() const;
    string getStatus() const;

    // Setters
    void setId(const string &newId);
    void setName(const string &newName);
    void setDob(const string &newDob);
    void setGender(const string &newGender);
    void setDepartment(const string &newDepartment);
    void setCourse(const string &newCourse);
    void setProgram(const string &newProgram);
    void setAddress(const string &newAddress);
    void setEmail(const string &newEmail);
    void setPhone(const string &newPhone);
    void setStatus(const string &newStatus);
    void display() const;
    string toCSV() const;
    static Student fromCSV(const string &csvLine);
};

extern vector<Student> students;

void saveStudentToCSV(const string &filename);
void loadStudentFromCSV(const string &filename);
void addStudent();
void deleteStudent();
void updateStudent();
void searchStudent();
void searchStudentByDepartment();
void searchStudentByDepartmentAndName();
void menu();

void exportStudentToJSON(const string &filename);
void importStudentFromJSON(const string &filename);


#endif // STUDENT_H
