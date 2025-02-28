#include <gtest/gtest.h>
#include "../Student/Funcs/update_student.cpp"



// Test cập nhật thành công
TEST(StudentTest, UpdateStudent_Success) {
    students.clear();
    students.push_back(Student("22127190", "Alice", "01/01/2000", "Female", "IT", "2024", "Software Engineering", "123 Street", "alice@clc.fitus.edu.vn", "0123456789", "Dang hoc"));
    
    bool result = updateStudent("22127190", 2, "Alice Updated");
    EXPECT_TRUE(result);
    EXPECT_EQ(students[0].getName(), "Alice Updated");
}

// Test cập nhật ID bị trùng
TEST(StudentTest, UpdateStudent_DuplicateID) {
    students.clear();
    students.push_back(Student("22127190", "Alice", "01/01/2000", "Female", "IT", "2024", "Software Engineering", "123 Street", "alice@clc.fitus.edu.vn", "0123456789", "Dang hoc"));
    
    bool result = updateStudent("22127190", 1, "22127164");
    EXPECT_FALSE(result);
}

// Test cập nhật Email sai định dạng
TEST(StudentTest, UpdateStudent_InvalidEmail) {
    students.clear();
    students.push_back(Student("22127190", "Alice", "01/01/2000", "Female", "IT", "2024", "Software Engineering", "123 Street", "alice@clc.fitus.edu.vn", "0123456789", "Dang hoc"));
    
    bool result = updateStudent("22127190", 9, "alice@gmail.com");
    EXPECT_FALSE(result);
}

// Test cập nhật số điện thoại sai định dạng
TEST(StudentTest, UpdateStudent_InvalidPhone) {
    students.clear();
    students.push_back(Student("22127190", "Alice", "01/01/2000", "Female", "IT", "2024", "Software Engineering", "123 Street", "alice@clc.fitus.edu.vn", "0123456789", "Dang hoc"));
    
    bool result = updateStudent("22127190", 10, "phone123");
    EXPECT_FALSE(result);
}

// Test cập nhật department không hợp lệ
TEST(StudentTest, UpdateStudent_InvalidDepartment) {
    students.clear();
    students.push_back(Student("22127190", "Alice", "01/01/2000", "Female", "IT", "2024", "Software Engineering", "123 Street", "alice@clc.fitus.edu.vn", "0123456789", "Dang hoc"));
    
    bool result = updateStudent("22127190", 5, "Business");
    EXPECT_FALSE(result);
}

// Test cập nhật status không hợp lệ
TEST(StudentTest, UpdateStudent_InvalidStatus) {
    students.clear();
    students.push_back(Student("22127190", "Alice", "01/01/2000", "Female", "IT", "2024", "Software Engineering", "123 Street", "alice@clc.fitus.edu.vn", "0123456789", "Dang hoc"));
    
    bool result = updateStudent("22127190", 11, "Expelled");
    EXPECT_FALSE(result);
}
