#ifndef PROGRAM_H
#define PROGRAM_H


#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include "../LogEvent/log_event.h"
using namespace std;

extern vector <string> validPrograms;

void saveProgramToCSV(const string &filename);
void loadProgramFromCSV(const string &filename);
void addProgram();
void updateProgramName();

#endif // PROGRAM_H