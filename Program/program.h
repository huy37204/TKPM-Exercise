#ifndef PROGRAM_H
#define PROGRAM_H


#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include "../LogEvent/log_event.h"
#include "../json.hpp"

using namespace std;
using json = nlohmann::json;

extern vector <string> validPrograms;

void saveProgramToCSV(const string &filename);
void loadProgramFromCSV(const string &filename);
void addProgram();
void updateProgramName();

void exportProgramToJSON(const string &filename);
void importProgramFromJSON(const string &filename);

#endif // PROGRAM_H