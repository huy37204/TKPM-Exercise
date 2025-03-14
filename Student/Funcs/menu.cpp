#include "student.h"
#include "student_exporter.h"
#include "config.h"

// Menu
void menu() {
    int choice;
    int loadRequest;
    do {
        cout << "---------- University of Science - HCMUS ----------\n";
        cout << "1: Load from CSV\n";
        cout << "2. Load from JSON\n";
        cout << "\nChoose an option: ";
        cin >> loadRequest;
    } while (loadRequest != 1 && loadRequest != 2);

    do {
        
        if (loadRequest == 1) {
            StudentExporter::loadStudentFromCSV("students.csv");
            loadDepartmentFromCSV("department.csv");
            loadStatusFromCSV("status.csv");
            loadProgramFromCSV("program.csv");
            loadConfigFromCSV("config.csv");
        }
        else if (loadRequest == 2) {
            StudentExporter::importStudentFromJSON("student.json");
            importDepartmentFromJSON("department.json");
            importStatusFromJSON("status.json");
            importProgramFromJSON("program.json");
            loadConfigFromJSON("config.json");
        }
        cout << "---------- University of Science - HCMUS ----------";
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
        cout << "\n14. Adjust Rules";
        cout << "\n15. Delete Department";
        cout << "\n16. Delete Status";
        cout << "\n17. Delete Program";
        cout << "\n18. Export Student Status";
        cout << "\n19. Exit";
        cout << "\nChoose an option: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1: addStudentInteractive(); break;
            case 2: deleteStudent(); break;
            case 3: updateStudentInteractive(); break;
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
            case 14: adjustRules(); break;
            case 15: deleteDepartment(); break;
            case 16: deleteStatus(); break;
            case 17: deleteProgram(); break;
            case 18: exportStudentStatusInteractive(); break;
            case 19: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 19);
}
