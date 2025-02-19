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
};

extern vector<Student> students;

#endif // STUDENT_H
