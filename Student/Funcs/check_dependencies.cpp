#include "student.h"

bool hasDependencies(const string& dependency, const string& type) {
    return any_of(students.begin(), students.end(), [&dependency, &type](const Student& s) {
        if (type == "program") {
            return s.getProgram() == dependency;
        } else if (type == "department") {
            return s.getDepartment() == dependency;
        } else if (type == "status") {
            return s.getStatus() == dependency;
        }
        return false;
    });
}