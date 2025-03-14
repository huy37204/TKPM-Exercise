#include "department.h"
#include "student.h"
#include "student_exporter.h"

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
    logEvent("Departments saved to " + filename);
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
    logEvent("Departments loaded from " + filename);
}

// Export departments to JSON
void exportDepartmentToJSON(const string &filename) {
    json j = validDepartments;
    
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file for writing: " << filename << endl;
        return;
    }
    file << j.dump(4);
    file.close();
    logEvent("Exported departments to JSON");
}

// Import departments from JSON
void importDepartmentFromJSON(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file for reading: " << filename << endl;
        return;
    }
    
    json j;
    file >> j;
    file.close();
    
    validDepartments.clear();
    validDepartments = j.get<vector<string>>();
    logEvent("Imported departments from JSON");
}

// Add department
void addDepartment() {
    string department;
    cout << "Enter new department: ";
    getline(cin, department);
    validDepartments.push_back(department);
    saveDepartmentToCSV("department.csv");
    exportDepartmentToJSON("department.json");
    cout << "Department is saved. \n";
    logEvent("Added new department: " + department);
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
        exportDepartmentToJSON("department.json");

        // Update department name for students
        for (auto &s : students) {
            if (s.getDepartment() == oldDepartment) {
                s.setDepartment(newDepartment);
            }
        }
        StudentExporter::saveStudentToCSV("students.csv");
        StudentExporter::exportStudentToJSON("student.json");
        
        cout << "Department updated successfully!\n";
        logEvent("Updated department: " + oldDepartment + " -> " + newDepartment);
    } else {
        cout << "Department not found!\n";
        logEvent("Failed to update department: " + oldDepartment + " (Not Found)");
    }
}

void deleteDepartment() {
    string department;
    cout << "Enter Department to delete: ";
    getline(cin, department);

    if (hasDependencies(department, "department")) {
        cout << "Cannot delete department. There are students associated with this department.\n";
        return;
    }

    auto it = find(validDepartments.begin(), validDepartments.end(), department);
    cout << department << endl;
    if (it != validDepartments.end()) {
        validDepartments.erase(it);
        saveDepartmentToCSV("department.csv");
        exportDepartmentToJSON("department.json");
        cout << "Department deleted successfully!\n";
        logEvent("Deleted department: " + department);
    } else {
        cout << "Department not found.\n";
    }
}

