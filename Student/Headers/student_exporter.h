#ifndef STUDENT_EXPORTER_H
#define STUDENT_EXPORTER_H

#include "student.h"
#include <string>

using namespace std;

class StudentExporter {
public:
    static string toCSV(const Student &student);
    static Student fromCSV(const string &csvLine);
    static void saveStudentToCSV(const string &filename);
    static void loadStudentFromCSV(const string &filename);
    static void exportStudentToJSON(const string &filename);
    static void importStudentFromJSON(const string &filename);
};

void exportStudentStatusToHTML(const Student& student, const string& filename);
void exportStudentStatusToMD(const Student& student, const std::string& filename);
void exportStudentStatusInteractive();

#endif // STUDENT_EXPORTER_H