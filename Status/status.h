#ifndef STATUS_H
#define STATUS_H


#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

extern vector <string> validStatuses;

void saveStatusToCSV(const string &filename);
void loadStatusFromCSV(const string &filename);
void addStatus();
void updateStatusName();

#endif // STATUS_H