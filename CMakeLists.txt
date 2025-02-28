cmake_minimum_required(VERSION 3.10)
project(TKPM-Exercise)

set(CMAKE_CXX_STANDARD 17)

# 🔥 Đảm bảo tất cả module dùng /MDd
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreadedDebugDLL" CACHE STRING "MSVC Runtime Library" FORCE)

if (MSVC)
    add_compile_options(/MDd)
endif()

# Thêm thư viện GoogleTest
add_subdirectory(gtest)


# Thêm thư mục chứa Student headers
include_directories(${CMAKE_SOURCE_DIR}/Student/Headers)

# Tạo thư viện StudentLib
add_library(StudentLib 
    Student/Funcs/add_student.cpp 
    Student/Funcs/class.cpp
    Student/Funcs/csv.cpp
    Student/Funcs/delete_student.cpp
    Student/Funcs/menu.cpp
    Student/Funcs/search_student.cpp
    Student/Funcs/update_student.cpp
)

# 🔥 Đảm bảo StudentLib build với /MDd
target_compile_options(StudentLib PUBLIC /MDd)

# Thêm thư mục tests
add_subdirectory(tests)
