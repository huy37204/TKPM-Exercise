#include "student.h"

// Search student
void searchStudent() {
    string keyword;
    cout << "Enter Name or ID to search: ";
    getline(cin, keyword);
    for (const auto &s : students) {
        if (s.getId() == keyword || s.getName().find(keyword) != string::npos) {
            s.display();
        }
    }
}

