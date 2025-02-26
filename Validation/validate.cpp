#include "validate.h"

string allowedDomain = "@clc.fitus.edu.vn";


bool isValidEmail(const string &email) {
    string domainPattern = R"(^[\w.-]+)" + allowedDomain + R"($)";
    regex emailPattern(domainPattern);

    return regex_match(email, emailPattern);
}

bool isValidPhone(const string &phone) {
    regex phonePattern(R"(^\d{10}$)");
    return regex_match(phone, phonePattern);
}

bool isValidDepartment(const string &department) {
    return find(validDepartments.begin(), validDepartments.end(), department) != validDepartments.end();
}

bool isValidPrograms(const string &program) {
    return find(validPrograms.begin(), validPrograms.end(), program) != validPrograms.end();
}

bool isValidStatus(const string &status) {
    return find(validStatuses.begin(), validStatuses.end(), status) != validStatuses.end();
}

bool isValidStudentId(const string &id) {
    return find_if(students.begin(), students.end(), 
                   [&](const Student &s) { return s.getId() == id; }) == students.end();
}