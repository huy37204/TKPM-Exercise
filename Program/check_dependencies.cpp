#include "program.h"
#include "student.h"

bool hasProgramDependencies(const string& program) {
    return any_of(students.begin(), students.end(), [&program](const Student& s) {
        return s.getProgram() == program;
    });
}