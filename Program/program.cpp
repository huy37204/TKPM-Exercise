#include "program.h"
#include "student.h"

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

// Export program to JSON
void exportProgramToJSON(const string &filename) {
    json j = validPrograms;
    
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file for writing: " << filename << endl;
        return;
    }
    file << j.dump(4);
    file.close();
    logEvent("Exported program to JSON");
}

// Import program from JSON
void importProgramFromJSON(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file for reading: " << filename << endl;
        return;
    }
    
    json j;
    file >> j;
    file.close();
    
    validPrograms.clear();
    validPrograms = j.get<vector<string>>();
    logEvent("Imported program from JSON");
}

// Add program
void addProgram() {
    string program;
    cout << "Enter new Program: ";
    getline(cin, program);
    validPrograms.push_back(program);
    saveProgramToCSV("program.csv");
    exportProgramToJSON("program.json");
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
        exportProgramToJSON("program.json");
        
        // Update program name for students
        for (auto &s : students) {
            if (s.getProgram() == oldProgram) {
                s.setProgram(newProgram);
            }
        }
        saveStudentToCSV("students.csv");
        exportStudentToJSON("student.json");
        
        cout << "Program updated successfully!\n";
        logEvent("Updated program: " + oldProgram + " -> " + newProgram);
    } else {
        cout << "Program not found!\n";
        logEvent("Failed to update program: " + oldProgram + " (Not Found)");
    }
}
