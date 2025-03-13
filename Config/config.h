#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>
#include <fstream>
#include "../json.hpp"
using namespace std;
using json = nlohmann::json;

class Config {
public:
    bool rule01_enabled; // MSSV la duy nhat
    bool rule02_enabled; // Email phai thuoc ten mien nhat dinh
    bool rule03_enabled; // So dien thoai phai co dinh dang hop le theo quoc gia
    bool rule04_enabled; // Tinh trang sinh vien co the thay doi theo mot so quy tac
    bool rule05_enabled; // Chi duoc phep xoa sinh vien co creation date/creation time < 30 phut
    bool rule06_enabled; // Ten khoa gioi han danh muc hop le
    bool rule07_enabled; // Tinh trang sinh vien gioi han danh muc hop le
    bool rule08_enabled; // Chuong trinh dao tao gioi han danh muc hop le

    Config() : rule01_enabled(true), rule02_enabled(true), rule03_enabled(true), rule04_enabled(true), 
    rule05_enabled(true), rule06_enabled(true), rule07_enabled(true), rule08_enabled(true) {}
};

extern Config config;

void saveConfigToCSV(const string &filename);
void loadConfigFromCSV(const string &filename);
void saveConfigToJSON(const string &filename);
void loadConfigFromJSON(const string &filename);
void adjustRules();


#endif // CONFIG_H