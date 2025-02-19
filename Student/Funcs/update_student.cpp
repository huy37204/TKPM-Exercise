#include "student.h"

// Update student
void updateStudent() {
    string id;
    cout << "Enter Student ID to update: "; cin >> id;
    cin.ignore();
    for (auto &s : students) {
        if (s.getId() == id) {
            string newValue;
            int select;
            cout << "1. Change ID\n";
            cout << "2. Change Name\n";
            cout << "3. Change DOB\n";
            cout << "4. Change Gender\n";
            cout << "5. Change Department\n";
            cout << "6. Change Course\n";
            cout << "7. Change Program\n";
            cout << "8. Change Address\n";
            cout << "9. Change Email\n";
            cout << "10. Change Phone number\n";
            cout << "11. Change Status\n";
            cout << "Select option: "; cin >> select;
            cin.ignore();
            do {
                cout << "Enter new value: "; getline(cin, newValue);
                switch (select) {
                    case 1: s.setId(newValue); break;
                    case 2: s.setName(newValue); break;
                    case 3: s.setDob(newValue); break;
                    case 4: s.setGender(newValue); break;
                    case 5:
                        if (!isValidDepartment(newValue)) {
                            cout << "Invalid department! Try again.\n";
                            continue;
                        }
                        s.setDepartment(newValue);
                        break;
                    case 6: s.setCourse(newValue); break;
                    case 7: s.setProgram(newValue); break;
                    case 8: s.setAddress(newValue); break;
                    case 9:
                        if (!isValidEmail(newValue)) {
                            cout << "Invalid email format! Try again.\n";
                            continue;
                        }
                        s.setEmail(newValue);
                        break;
                    case 10:
                        if (!isValidPhone(newValue)) {
                            cout << "Invalid phone number! Try again.\n";
                            continue;
                        }
                        s.setPhone(newValue);
                        break;
                    case 11:
                        if (!isValidStatus(newValue)) {
                            cout << "Invalid student status! Try again.\n";
                            continue;
                        }
                        s.setStatus(newValue);
                        break;
                    default: cout << "Invalid option!\n"; return;
                }
                break;
            } while (true);
            saveToCSV("students.csv");
            cout << "Student updated successfully!\n";
            return;
        }
    }
    cout << "Student not found!\n";
}
