#ifndef STATUS_H
#define STATUS_H


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

extern vector <string> validStatuses;

void saveStatusToCSV(const string &filename);
void loadStatusFromCSV(const string &filename);
void addStatus();
void updateStatusName();
void deleteStatus();
void exportStatusToJSON(const string &filename);
void importStatusFromJSON(const string &filename);

#endif // STATUS_H