#include "validate.h"

string allowedDomain = "@clc.fitus.edu.vn";
string countryCode = "VN";


bool isValidEmail(const string &email) {
    string domainPattern = R"(^[\w.-]+)" + allowedDomain + R"($)";
    regex emailPattern(domainPattern);

    return regex_match(email, emailPattern);
}

bool isValidPhone(const string &phone) {
    regex phonePattern;

    if (countryCode == "VN") { 
        phonePattern = regex(R"(^(\+84|0[35789])\d{8}$)");
    } else if (countryCode == "US") {
        phonePattern = regex(R"(^(\+1\s?)?(\(\d{3}\)\s?|\d{3}[-\s]?)\d{3}[-\s]?\d{4}$)");
    } else if (countryCode == "UK") {
        phonePattern = regex(R"(^(\+44|07)\d{9,10}$)");
    } else if (countryCode == "JP") { 
        phonePattern = regex(R"(^(\+81|0)\d{9,10}$)");
    } else {
        return false; 
    }

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