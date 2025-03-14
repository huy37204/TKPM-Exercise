#include "status.h"
#include "student.h"
#include "student_exporter.h"


using namespace std;

vector <string> validStatuses;

// Save statuses to CSV
void saveStatusToCSV(const string &filename) {
    ofstream file(filename);
    for (size_t i = 0; i < validStatuses.size(); ++i) {
        file << validStatuses[i];
        if (i != validStatuses.size() - 1) {
            file << ", ";
        }
    }
    file.close();
    logEvent("Statuses saved to " + filename);
}

// Load statuses from CSV
void loadStatusFromCSV(const string &filename) {
    ifstream file(filename);
    string line;
    validStatuses.clear();
    
    if (getline(file, line)) {
        stringstream ss(line);
        string status;
        while (getline(ss, status, ',')) {
            status.erase(0, status.find_first_not_of(" "));
            validStatuses.push_back(status);
        }
    }
    
    file.close();
    logEvent("Statuses loaded from " + filename);
}

// Export status to JSON
void exportStatusToJSON(const string &filename) {
    json j = validStatuses;
    
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file for writing: " << filename << endl;
        return;
    }
    file << j.dump(4);
    file.close();
    logEvent("Exported status to JSON");
}

// Import status from JSON
void importStatusFromJSON(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file for reading: " << filename << endl;
        return;
    }
    
    json j;
    file >> j;
    file.close();
    
    validStatuses.clear();
    validStatuses = j.get<vector<string>>();
    logEvent("Imported status from JSON");
}

// Add status
void addStatus() {
    string status;
    cout << "Enter new status: ";
    getline(cin, status);
    validStatuses.push_back(status);
    saveStatusToCSV("status.csv");
    exportStatusToJSON("status.json");
    cout << "Status is saved. \n";
    logEvent("Added new status: " + status);
}

// Change status' name
void updateStatusName() {
    string oldStatus, newStatus;
    cout << "Enter the status name to update: ";
    getline(cin, oldStatus);
    
    auto it = find(validStatuses.begin(), validStatuses.end(), oldStatus);
    if (it != validStatuses.end()) {
        cout << "Enter new status name: ";
        getline(cin, newStatus);
        *it = newStatus;
        saveStatusToCSV("status.csv");
        exportStatusToJSON("status.json");
        
        // Update status name for students
        for (auto &s : students) {
            if (s.getStatus() == oldStatus) {
                s.setStatus(newStatus);
            }
        }
        StudentExporter::saveStudentToCSV("students.csv");
        StudentExporter::exportStudentToJSON("student.json");
        
        cout << "Status updated successfully!\n";
        logEvent("Updated status: " + oldStatus + " -> " + newStatus);
    } else {
        cout << "Status not found!\n";
        logEvent("Failed to update status: " + oldStatus + " (Not Found)");
    }
}

void deleteStatus() {
    string status;
    cout << "Enter Status to delete: ";
    getline(cin, status);

    if (hasDependencies(status, "status")) {
        cout << "Cannot delete status. There are students associated with this status.\n";
        return;
    }

    auto it = find(validStatuses.begin(), validStatuses.end(), status);
    if (it != validStatuses.end()) {
        validStatuses.erase(it);
        saveStatusToCSV("status.csv");
        exportStatusToJSON("status.json");
        cout << "Status deleted successfully!\n";
        logEvent("Deleted status: " + status);
    } else {
        cout << "Status not found.\n";
    }
}

