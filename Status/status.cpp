#include "status.h"


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

// Add status
void addStatus() {
    string status;
    cout << "Enter new status: ";
    getline(cin, status);
    validStatuses.push_back(status);
    saveStatusToCSV("status.csv");
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
        cout << "Status updated successfully!\n";
        logEvent("Updated status: " + oldStatus + " -> " + newStatus);

    } else {
        cout << "Status not found!\n";
        logEvent("Failed to update status: " + oldStatus + " (Not Found)");

    }
}
