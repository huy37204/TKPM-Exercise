#include <ctime>
#include "student.h"

void exportStudentStatusToHTML(const Student& student, const std::string& filename) {
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

    file << "<html><head><title>Student Status Confirmation</title></head><body>";
    file << "<h1>GIẤY XÁC NHẬN TÌNH TRẠNG SINH VIÊN</h1>";
    file << "<p>Trường Đại học [Tên Trường] xác nhận:</p>";
    file << "<h2>1. Thông tin sinh viên:</h2>";
    file << "<p><strong>Họ và tên:</strong> " << student.getName() << "</p>";
    file << "<p><strong>Mã số sinh viên:</strong> " << student.getId() << "</p>";
    file << "<p><strong>Ngày sinh:</strong> " << student.getDob() << "</p>";
    file << "<p><strong>Giới tính:</strong> " << student.getGender() << "</p>";
    file << "<p><strong>Khoa:</strong> " << student.getDepartment() << "</p>";
    file << "<p><strong>Chương trình đào tạo:</strong> " << student.getProgram() << "</p>";
    file << "<p><strong>Khóa:</strong> " << student.getCourse() << "</p>";
    file << "<h2>2. Tình trạng sinh viên hiện tại:</h2>";
    file << "<p>" << student.getStatus() << "</p>";
    file << "<h2>3. Mục đích xác nhận:</h2>";
    file << "<p>" << student.getPurpose() << "</p>";
    file << "<h2>4. Thời gian cấp giấy:</h2>";
    file << "<p>Giấy xác nhận có hiệu lực đến ngày: " << effectiveDate << "</p>";
    file << "<p>Ngày cấp: " << currentDate << "</p>";
    file << "<p><strong>Trưởng Phòng Đào Tạo</strong></p>";
    file << "<p>(Ký, ghi rõ họ tên, đóng dấu)</p>";
    file << "</body></html>";

    file.close();
}