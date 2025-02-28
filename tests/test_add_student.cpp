#include <gtest/gtest.h>
#include "../Student/Funcs/add_student.cpp"

string allowedDomain;
vector<string> validStatuses;
vector<string> validDepartments ;
vector<string> validPrograms;
// Mock các hàm kiểm tra đầu vào
bool isValidStudentId(const std::string& id) { return id != "22127164";}
bool isValidDepartment(const std::string& department) { return department == "IT" || department == "CS"; }
bool isValidPrograms(const std::string& program) { return program == "Software Engineering" || program == "Data Science"; }
bool isValidEmail(const std::string& email) { return email.find("@clc.fitus.edu.vn") != std::string::npos; }
bool isValidPhone(const std::string& phone) { return phone.length() == 10 && phone.find_first_not_of("0123456789") == std::string::npos; }
bool isValidStatus(const std::string& status) { return status == "Dang hoc" || status == "Bao luu"; }
bool isValidUpdateStatus(const std::string& oldStatus, const std::string& newStatus) { return oldStatus == "Dang hoc" && newStatus == "Bao luu"; }

// Mock hàm lưu dữ liệu
void saveStudentToCSV(const std::string&) {}
void exportStudentToJSON(const std::string&) {}
void logEvent(const std::string&) {}

// Test thêm sinh viên thành công
TEST(StudentTest, AddStudent_Success) {
    students.clear();
    bool result = addStudent("22127190", "Alice", "01/01/2000", "Female",
                             "IT", "2024", "Software Engineering", 
                             "123 Street", "alice@clc.fitus.edu.vn", "0123456789", "Dang hoc");

    EXPECT_TRUE(result);
    EXPECT_EQ(students.size(), 1);
}

// Test thêm sinh viên với ID đã tồn tại
TEST(StudentTest, AddStudent_DuplicateID) {
    students.clear();
    addStudent("22127164", "Bob", "01/01/2000", "Male",
               "CS", "2024", "Data Science",
               "456 Street", "bob@clc.fitus.edu.vn", "0987654321", "Bao luu");

    bool result = addStudent("22127164", "Charlie", "01/01/2001", "Male",
                             "CS", "2025", "Data Science",
                             "789 Street", "charlie@clc.fitus.edu.vn", "0912345678", "Dang hoc");

    EXPECT_FALSE(result);
    EXPECT_EQ(students.size(), 0);
}

// Test thêm sinh viên với email không hợp lệ
TEST(StudentTest, AddStudent_InvalidEmail) {
    students.clear();
    bool result = addStudent("S56789", "David", "02/02/2002", "Male",
                             "IT", "2023", "Software Engineering", 
                             "321 Street", "invalid_email@gmail.com", "0123456789", "Dang hoc");

    EXPECT_FALSE(result);
    EXPECT_EQ(students.size(), 0);
}

// Test thêm sinh viên với số điện thoại không hợp lệ
TEST(StudentTest, AddStudent_InvalidPhone) {
    students.clear();
    bool result = addStudent("S98765", "Eve", "03/03/2003", "Female",
                             "CS", "2025", "Data Science", 
                             "654 Street", "eve@clc.fitus.edu.vn", "phone1234", "Bao luu");

    EXPECT_FALSE(result);
    EXPECT_EQ(students.size(), 0);
}

// Test thêm sinh viên với department không hợp lệ
TEST(StudentTest, AddStudent_InvalidDepartment) {
    students.clear();
    bool result = addStudent("S11223", "Frank", "04/04/2004", "Male",
                             "Business", "2024", "Software Engineering", 
                             "987 Street", "frank@clc.fitus.edu.vn", "0123456789", "Dang hoc");

    EXPECT_FALSE(result);
    EXPECT_EQ(students.size(), 0);
}

// Test thêm sinh viên với program không hợp lệ
TEST(StudentTest, AddStudent_InvalidProgram) {
    students.clear();
    bool result = addStudent("S44556", "Grace", "05/05/2005", "Female",
                             "IT", "2023", "Mechanical Engineering", 
                             "111 Street", "grace@clc.fitus.edu.vn", "0987654321", "Bao luu");

    EXPECT_FALSE(result);
    EXPECT_EQ(students.size(), 0);
}

// Test thêm sinh viên với status không hợp lệ
TEST(StudentTest, AddStudent_InvalidStatus) {
    students.clear();
    bool result = addStudent("S77889", "Hank", "06/06/2006", "Male",
                             "CS", "2026", "Data Science", 
                             "222 Street", "hank@clc.fitus.edu.vn", "0912345678", "Expelled");

    EXPECT_FALSE(result);
    EXPECT_EQ(students.size(), 0);
}

// Main chạy test
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
