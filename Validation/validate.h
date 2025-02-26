#ifndef VALIDATE_H
#define VALIDATE_H

#include <iostream>
#include <regex>
#include "../Student/Headers/student.h"

using namespace std;

extern vector<string> validStatuses;
extern string allowedDomain; 
extern string countryCode;


bool isValidEmail(const string &email);
bool isValidPhone(const string &phone);
bool isValidDepartment(const string &department);
bool isValidPrograms(const string &program);
bool isValidStatus(const string &status);
bool isValidStudentId(const string &id);

#endif // VALIDATE_H