#include "department.h"
#include "student.h"

bool hasDepartmentDependencies(const string& department) {
    return any_of(students.begin(), students.end(), [&department](const Student& s) {
        return s.getDepartment() == department;
    });
}