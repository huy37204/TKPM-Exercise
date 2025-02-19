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


