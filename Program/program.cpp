#include "program.h"

using namespace std;

vector<string> validPrograms;

// Save programs to CSV
void saveProgramToCSV(const string &filename) {
    ofstream file(filename);
    for (size_t i = 0; i < validPrograms.size(); ++i) {
        file << validPrograms[i];
        if (i != validPrograms.size() - 1) {
            file << ", ";
        }
    }
    file.close();
    logEvent("Programs saved to " + filename);
}

// Load programs from CSV
void loadProgramFromCSV(const string &filename) {
    ifstream file(filename);
    string line;
    validPrograms.clear();
    
    if (getline(file, line)) {
        stringstream ss(line);
        string program;
        while (getline(ss, program, ',')) {
            program.erase(0, program.find_first_not_of(" "));
            validPrograms.push_back(program);
        }
    }
    
    file.close();
    logEvent("Programs loaded from " + filename);
}

// Add program
void addProgram() {
    string program;
    cout << "Enter new Program: ";
    getline(cin, program);
    validPrograms.push_back(program);
    saveProgramToCSV("program.csv");
    cout << "Program is saved. \n";
    logEvent("Added new program: " + program);
}

// Change program's name
void updateProgramName() {
    string oldProgram, newProgram;
    cout << "Enter the Program's name to update: ";
    getline(cin, oldProgram);
    
    auto it = find(validPrograms.begin(), validPrograms.end(), oldProgram);
    if (it != validPrograms.end()) {
        cout << "Enter new Program name: ";
        getline(cin, newProgram);
        *it = newProgram;
        saveProgramToCSV("program.csv");
        cout << "Program updated successfully!\n";
        logEvent("Updated program: " + oldProgram + " -> " + newProgram);

    } else {
        cout << "Program not found!\n";
        logEvent("Failed to update program: " + oldProgram + " (Not Found)");

    }
}
