#ifndef VALIDATE_H
#define VALIDATE_H

#include <iostream>
#include <regex>
#include "../Student/Headers/student.h"
#include <unordered_map>


using namespace std;

extern vector<string> validStatuses;
extern string allowedDomain; 
extern string countryCode;
extern unordered_map<string, vector<string>> validTransitions;


bool isValidEmail(const string &email);
bool isValidPhone(const string &phone);
bool isValidDepartment(const string &department);
bool isValidPrograms(const string &program);
bool isValidStatus(const string &status);
bool isValidUpdateStatus(const string &oldStatus, const string &newStatus);
bool isValidStudentId(const string &id);

#endif // VALIDATE_H