#include "student.h"
#include "student_exporter.h"


void exportStudentStatusInteractive() {
    string studentId;
    int choice;
    int purposeChoice;
    string purpose;

    cout << "Enter Student ID: ";
    cin >> studentId;

    auto it = find_if(students.begin(), students.end(), [&studentId](const Student& s) {
        return s.getId() == studentId;
    });

    if (it == students.end()) {
        cout << "Student not found.\n";
        return;
    }

    cout << "Choose export format:\n";
    cout << "1. HTML\n";
    cout << "2. Markdown (MD)\n";
    cout << "Choose an option: ";
    cin >> choice;

    cout << "Choose purpose of confirmation:\n";
    cout << "1. Xac nhan dang hoc de vay von ngan hang\n";
    cout << "2. Xac nhan lam thu tuc tam hoan nghia vu quan su\n";
    cout << "3. Xac nhan lam ho so xin viec / thuc tap\n";
    cout << "4. Xac nhan ly do khac\n";
    cout << "Choose an option: ";
    cin >> purposeChoice;
    cin.ignore(); // Ignore the newline character left in the buffer

    switch (purposeChoice) {
        case 1:
            purpose = "Xác nhận đang học để vay vốn ngân hàng";
            break;
        case 2:
            purpose = "Xác nhận làm thủ tục tạm hoãn nghĩa vụ quân sự";
            break;
        case 3:
            purpose = "Xác nhận làm hồ sơ xin việc / thực tập";
            break;
        case 4:
            cout << "Enter the specific reason: ";
            getline(cin, purpose);
            break;
        default:
            cout << "Invalid choice!\n";
            return;
    }

    it->setPurpose(purpose);

    switch (choice) {
        case 1:
            exportStudentStatusToHTML(*it, "student_status.html");
            cout << "Exported to HTML successfully!\n";
            break;
        case 2:
            exportStudentStatusToMD(*it, "student_status.md");
            cout << "Exported to Markdown successfully!\n";
            break;
        default:
            cout << "Invalid choice!\n";
            break;
    }
}