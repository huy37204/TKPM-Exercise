#include "student.h"


// Menu
void menu() {
    int choice;
    do {
        loadStudentFromCSV("students.csv");
        loadDepartmentFromCSV("department.csv");
        loadStatusFromCSV("status.csv");
        loadProgramFromCSV("program.csv");

        cout << "\nStudent Management System";
        cout << "\n1. Add Student";
        cout << "\n2. Delete Student";
        cout << "\n3. Update Student";
        cout << "\n4. Search Student";
        cout << "\n5. Add Department";
        cout << "\n6. Update Department's Name";
        cout << "\n7. Add Status";
        cout << "\n8. Update Status' Name";
        cout << "\n9. Add Program";
        cout << "\n10. Update Program's Name";
        cout << "\n11. Search Student by department";
        cout << "\n12. Search Student by department and name";
        cout << "\n13. Show version";
        cout << "\n14. Exit";
        cout << "\nChoose an option: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1: addStudent(); break;
            case 2: deleteStudent(); break;
            case 3: updateStudent(); break;
            case 4: searchStudent(); break;
            case 5: addDepartment(); break;
            case 6: updateDepartmentName(); break;
            case 7: addStatus(); break;
            case 8: updateStatusName(); break;
            case 9: addProgram(); break;
            case 10: updateProgramName(); break;
            case 11: searchStudentByDepartment(); break;
            case 12: searchStudentByDepartmentAndName(); break;
            case 13: showVersion(); break;
            case 14: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 14);
}