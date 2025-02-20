#ifndef DEPARTMENT_H
#define DEPARTMENT_H


#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

extern vector <string> validDepartments;

void saveDepartmentToCSV(const string &filename);
void loadDepartmentFromCSV(const string &filename);
void addDepartment();
void updateDepartmentName();

#endif // DEPARTMENT_H