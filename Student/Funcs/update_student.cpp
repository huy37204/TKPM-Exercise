#include "student.h"

// Hàm interactive cho update student
void updateStudentInteractive() {
    string id;
    cout << "Enter Student ID to update: ";
    cin >> id;
    cin.ignore();

    auto it = find_if(students.begin(), students.end(), [&](const Student &s) {
        return s.getId() == id;
    });

    if (it == students.end()) {
        cout << "Student not found!\n";
        logEvent("Failed to update student: ID = " + id + " (Not Found)");
        return;
    }

    Student &s = *it;

    int field;
    string newValue;
    bool success = false;

    do {
        cout << "\nSelect the field to update:\n";
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
        cout << "12. Cancel\n";
        cout << "Choose an option: ";
        cin >> field;
        cin.ignore();

        if (field == 12) return;  // Thoát nếu chọn 12

        cout << "Enter new value: ";
        getline(cin, newValue);

        success = updateStudent(id, field, newValue);

        if (success) {
            cout << "Student information updated successfully!\n";
            logEvent("Updated student field " + to_string(field) + " for ID: " + id);
        } else {
            cout << "Invalid input! Please try again.\n";
        }

    } while (!success);
}

// Cập nhật một trường thông tin sinh viên
bool updateStudentField(Student &s, int field, const string &newValue) {
    switch (field) {
        case 1:
            if (!isValidStudentId(newValue)) return false;
            s.setId(newValue);
            break;
        case 2:
            s.setName(newValue);
            break;
        case 3:
            s.setDob(newValue);
            break;
        case 4:
            s.setGender(newValue);
            break;
        case 5:
            if (!isValidDepartment(newValue)) return false;
            s.setDepartment(newValue);
            break;
        case 6:
            s.setCourse(newValue);
            break;
        case 7:
            if (!isValidPrograms(newValue)) return false;
            s.setProgram(newValue);
            break;
        case 8:
            s.setAddress(newValue);
            break;
        case 9:
            if (!isValidEmail(newValue)) return false;
            s.setEmail(newValue);
            break;
        case 10:
            if (!isValidPhone(newValue)) return false;
            s.setPhone(newValue);
            break;
        case 11:
            if (!isValidStatus(newValue) || !isValidUpdateStatus(s.getStatus(), newValue))
                return false;
            s.setStatus(newValue);
            break;
        default:
            return false;
    }
    return true;
}

// Cập nhật thông tin sinh viên (hỗ trợ unit test)
bool updateStudent(const string &id, int field, const string &newValue) {
    auto it = find_if(students.begin(), students.end(), [&](const Student &s) {
        return s.getId() == id;
    });

    if (it == students.end()) return false;

    Student &s = *it;
    bool success = updateStudentField(s, field, newValue);

    if (success) {
        saveStudentToCSV("students.csv");
        exportStudentToJSON("student.json");
    }

    return success;
}