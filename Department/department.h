#ifndef DEPARTMENT_H
#define DEPARTMENT_H


#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include "../LogEvent/log_event.h"
#include "../../json.hpp"
using namespace std;
using json = nlohmann::json;

extern vector <string> validDepartments;

void saveDepartmentToCSV(const string &filename);
void loadDepartmentFromCSV(const string &filename);
void addDepartment();
void updateDepartmentName();

void exportDepartmentToJSON(const string &filename);
void importDepartmentFromJSON(const string &filename);

#endif // DEPARTMENT_H