#include "status.h"
#include "student.h"

bool hasStatusDependencies(const string& status) {
    return any_of(students.begin(), students.end(), [&status](const Student& s) {
        return s.getStatus() == status;
    });
}