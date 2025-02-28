# Chuyển sang dynamic runtime library để tránh xung đột trên Windows
set(CMAKE_CXX_FLAGS_DEBUG "/MDd")
set(CMAKE_CXX_FLAGS_RELEASE "/MD")

# Tạo executable cho unit test
add_executable(runTests test_add_student.cpp test_update_student.cpp)

# Thêm đường dẫn chứa "student.h"
target_include_directories(runTests PRIVATE ${CMAKE_SOURCE_DIR}/Student/Headers)

# Liên kết với thư viện chính của chương trình
target_link_libraries(runTests StudentLib gtest gtest_main)
