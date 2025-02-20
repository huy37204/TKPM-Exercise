#include "validate.h"
#include "../Department/department.h"


vector<string> validStatuses = {"Dang hoc", "Da tot nghiep", "Da thoi hoc", "Tam dung hoc"};
vector<string> validPrograms = {"Chinh quy", "Lien thong", "CLC", "Tien tien"};

bool isValidEmail(const string &email) {
    regex emailPattern(R"(^[\w.-]+@[a-zA-Z_]+?\.[a-zA-Z]{2,3}$)");
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