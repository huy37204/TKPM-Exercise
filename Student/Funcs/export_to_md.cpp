#include <ctime>
#include "student.h"

void exportStudentStatusToMD(const Student& student, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file for writing: " << filename << std::endl;
        return;
    }

    // Get current date and effective date
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char currentDate[11];
    char effectiveDate[11];
    strftime(currentDate, sizeof(currentDate), "%d/%m/%Y", ltm);
    ltm->tm_mday += 30;
    mktime(ltm);
    strftime(effectiveDate, sizeof(effectiveDate), "%d/%m/%Y", ltm);

    file << "# GIẤY XÁC NHẬN TÌNH TRẠNG SINH VIÊN\n\n";
    file << "Trường Đại học [Tên Trường] xác nhận:\n\n";
    file << "## 1. Thông tin sinh viên:\n";
    file << "- **Họ và tên:** " << student.getName() << "\n";
    file << "- **Mã số sinh viên:** " << student.getId() << "\n";
    file << "- **Ngày sinh:** " << student.getDob() << "\n";
    file << "- **Giới tính:** " << student.getGender() << "\n";
    file << "- **Khoa:** " << student.getDepartment() << "\n";
    file << "- **Chương trình đào tạo:** " << student.getProgram() << "\n";
    file << "- **Khóa:** " << student.getCourse() << "\n\n";
    file << "## 2. Tình trạng sinh viên hiện tại:\n";
    file << student.getStatus() << "\n\n";
    file << "## 3. Mục đích xác nhận:\n";
    file << student.getPurpose() << "\n\n";
    file << "## 4. Thời gian cấp giấy:\n";
    file << "Giấy xác nhận có hiệu lực đến ngày: " << effectiveDate << "\n";
    file << "Ngày cấp: " << currentDate << "\n\n";
    file << "**Trưởng Phòng Đào Tạo**\n";
    file << "(Ký, ghi rõ họ tên, đóng dấu)\n";

    file.close();
}