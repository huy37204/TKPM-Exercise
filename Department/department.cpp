#include "department.h"

using namespace std;

vector<string> validDepartments;

// Save departments to CSV
void saveDepartmentToCSV(const string &filename) {
    ofstream file(filename);
    for (size_t i = 0; i < validDepartments.size(); ++i) {
        file << validDepartments[i];
        if (i != validDepartments.size() - 1) {
            file << ", ";
        }
    }
    file.close();
}

// Load departments from CSV
void loadDepartmentFromCSV(const string &filename) {
    ifstream file(filename);
    string line;
    validDepartments.clear();
    
    if (getline(file, line)) {
        stringstream ss(line);
        string department;
        while (getline(ss, department, ',')) {
            department.erase(0, department.find_first_not_of(" "));
            validDepartments.push_back(department);
        }
    }
    
    file.close();
}

// Add department
void addDepartment() {
    string department;
    cout << "Enter new department: ";
    getline(cin, department);
    validDepartments.push_back(department);
    saveDepartmentToCSV("department.csv");
    cout << "Department is saved. \n";
}

// Change department's name
void updateDepartmentName() {
    string oldDepartment, newDepartment;
    cout << "Enter the department name to update: ";
    getline(cin, oldDepartment);
    
    auto it = find(validDepartments.begin(), validDepartments.end(), oldDepartment);
    if (it != validDepartments.end()) {
        cout << "Enter new department name: ";
        getline(cin, newDepartment);
        *it = newDepartment;
        saveDepartmentToCSV("department.csv");
        cout << "Department updated successfully!\n";
    } else {
        cout << "Department not found!\n";
    }
}
