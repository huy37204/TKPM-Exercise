#include "config.h"

Config config;

void adjustRules() {
    int choice;
    do {
        cout << "\nAdjust Rules:";
        cout << "\n1. Toggle Rule 01 (MSSV la duy nhat)";
        cout << "\n2. Toggle Rule 02 (Email phai thuoc ten mien nhat dinh)";
        cout << "\n3. Toggle Rule 03 (So dien thoai phai co dinh dang hop le theo quoc gia)";
        cout << "\n4. Toggle Rule 04 (Tinh trang sinh vien co the thay doi theo mot so quy tac)";
        cout << "\n5. Toggle Rule 05 (Chi duoc phep xoa sinh vien co creation date/creation time < 30 phut)";
        cout << "\n6. Toggle Rule 06 (Ten khoa gioi han danh muc hop le)";
        cout << "\n7. Toggle Rule 07 (Tinh trang sinh vien gioi han danh muc hop le)";
        cout << "\n8. Toggle Rule 08 (Chuong trinh dao tao gioi han danh muc hop le)";
        cout << "\n9. Exit";
        cout << "\nChoose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                config.rule01_enabled = !config.rule01_enabled;
                cout << "Rule 01 is now " << (config.rule01_enabled ? "enabled" : "disabled") << endl;
                saveConfigToCSV("config.csv");
                saveConfigToJSON("config.json");
                break;
            case 2:
                config.rule02_enabled = !config.rule02_enabled;
                cout << "Rule 02 is now " << (config.rule02_enabled ? "enabled" : "disabled") << endl;
                saveConfigToCSV("config.csv");
                saveConfigToJSON("config.json");
                break;
            case 3:
                config.rule03_enabled = !config.rule03_enabled;
                cout << "Rule 03 is now " << (config.rule03_enabled ? "enabled" : "disabled") << endl;
                saveConfigToCSV("config.csv");
                saveConfigToJSON("config.json");
                break;
            case 4:
                config.rule04_enabled = !config.rule04_enabled;
                cout << "Rule 04 is now " << (config.rule04_enabled ? "enabled" : "disabled") << endl;
                saveConfigToCSV("config.csv");
                saveConfigToJSON("config.json");
                break;
            case 5:
                config.rule05_enabled = !config.rule05_enabled;
                cout << "Rule 05 is now " << (config.rule05_enabled ? "enabled" : "disabled") << endl;
                saveConfigToCSV("config.csv");
                saveConfigToJSON("config.json");
                break;
            case 6:
                config.rule06_enabled = !config.rule06_enabled;
                cout << "Rule 06 is now " << (config.rule06_enabled ? "enabled" : "disabled") << endl;
                saveConfigToCSV("config.csv");
                saveConfigToJSON("config.json");
                break;
            case 7:
                config.rule07_enabled = !config.rule07_enabled;
                cout << "Rule 07 is now " << (config.rule07_enabled ? "enabled" : "disabled") << endl;
                saveConfigToCSV("config.csv");
                saveConfigToJSON("config.json");
                break;
            case 8:
                config.rule08_enabled = !config.rule08_enabled;
                cout << "Rule 08 is now " << (config.rule08_enabled ? "enabled" : "disabled") << endl;
                saveConfigToCSV("config.csv");
                saveConfigToJSON("config.json");
                break;
            case 9:
                cout << "Exiting rule adjustment...\n";
                break;
            default:
                cout << "Invalid choice!\n";
                break;
        }
    } while (choice != 9);
}

void saveConfigToCSV(const string &filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file for writing: " << filename << endl;
        return;
    }
    file << config.rule01_enabled << ","
         << config.rule02_enabled << ","
         << config.rule03_enabled << ","
         << config.rule04_enabled << ","
         << config.rule05_enabled << ","
         << config.rule06_enabled << ","
         << config.rule07_enabled << ","
         << config.rule08_enabled << endl;
    file.close();
}

void loadConfigFromCSV(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file for reading: " << filename << endl;
        return;
    }
    char delimiter;
    file >> config.rule01_enabled >> delimiter
         >> config.rule02_enabled >> delimiter
         >> config.rule03_enabled >> delimiter
         >> config.rule04_enabled >> delimiter
         >> config.rule05_enabled >> delimiter
         >> config.rule06_enabled >> delimiter
         >> config.rule07_enabled >> delimiter
         >> config.rule08_enabled;
    file.close();
}

void saveConfigToJSON(const string &filename) {
    json j;
    j["rule01_enabled"] = config.rule01_enabled;
    j["rule02_enabled"] = config.rule02_enabled;
    j["rule03_enabled"] = config.rule03_enabled;
    j["rule04_enabled"] = config.rule04_enabled;
    j["rule05_enabled"] = config.rule05_enabled;
    j["rule06_enabled"] = config.rule06_enabled;
    j["rule07_enabled"] = config.rule07_enabled;
    j["rule08_enabled"] = config.rule08_enabled;

    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file for writing: " << filename << endl;
        return;
    }
    file << j.dump(4);
    file.close();
}

void loadConfigFromJSON(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file for reading: " << filename << endl;
        return;
    }
    json j;
    file >> j;
    file.close();

    config.rule01_enabled = j["rule01_enabled"];
    config.rule02_enabled = j["rule02_enabled"];
    config.rule03_enabled = j["rule03_enabled"];
    config.rule04_enabled = j["rule04_enabled"];
    config.rule05_enabled = j["rule05_enabled"];
    config.rule06_enabled = j["rule06_enabled"];
    config.rule07_enabled = j["rule07_enabled"];
    config.rule08_enabled = j["rule08_enabled"];
}