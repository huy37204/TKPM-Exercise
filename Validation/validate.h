#ifndef VALIDATE_H
#define VALIDATE_H

#include <iostream>
#include <regex>

using namespace std;

extern vector<string> validDepartments;
extern vector<string> validStatuses;

bool isValidEmail(const string &email);
bool isValidPhone(const string &phone);
bool isValidDepartment(const string &department);
bool isValidStatus(const string &status);

#endif // VALIDATE_H