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
#include <chrono>

using namespace std;


class Student {
private:
    string id, name, dob, gender, department, course, program, address, email, phone, status, purpose;
    chrono::system_clock::time_point creationTime;
    

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
    chrono::system_clock::time_point getCreationTime() const;
    string getPurpose() const;


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
    void setPurpose(const std::string& purpose);
    void setCreationTime(const std::chrono::system_clock::time_point &newCreationTime);
    void display() const;
    static string timePointToString(const chrono::system_clock::time_point &tp);
    static chrono::system_clock::time_point stringToTimePoint(const string &str);
};

extern vector<Student> students;

// void saveStudentToCSV(const string &filename);
// void loadStudentFromCSV(const string &filename);
void addStudentInteractive();
bool addStudent(const string& id, const string& name, const string& dob, const string& gender, 
    const string& department, const string& course, const string& program, 
    const string& address, const string& email, const string& phone, 
    const string& status);
void deleteStudent();
string deleteStudentInteractive();
bool deleteStudentById(const string &id);
void updateStudentInteractive();
bool updateStudentField(Student &s, int field, const string &newValue);
bool updateStudent(const string &id, int field, const string &newValue);
void searchStudent();
void searchStudentByDepartment();
void searchStudentByDepartmentAndName();
void menu();
// void exportStudentToJSON(const string &filename);
// void importStudentFromJSON(const string &filename);
// void exportStudentStatusToHTML(const Student& student, const string& filename);
// void exportStudentStatusToMD(const Student& student, const std::string& filename);
// void exportStudentStatusInteractive();


#endif // STUDENT_H
