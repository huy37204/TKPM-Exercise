#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student {
private:
    string id, name, dob, gender, department, course, program, address, email, phone, status;

public:
    Student();
    Student(string id, string name, string dob, string gender, string department, string course,
            string program, string address, string email, string phone, string status);

    string getId() const;
    string getName() const;
    void setName(const string &newName);
    void display() const;
    string toCSV() const;
    static Student fromCSV(const string &csvLine);
};

extern vector<Student> students;

void saveToCSV(const string &filename);
void loadFromCSV(const string &filename);
void addStudent();

#endif // STUDENT_H
