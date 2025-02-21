#include "log_event.h"

// Logging mechanism
void logEvent(const string &message) {
    ofstream logFile("application.log", ios::app);
    if (!logFile.is_open()) {
        cerr << "Error opening log file." << endl;
        return;
    }
    time_t now = time(0);
    tm *ltm = localtime(&now);
    logFile << "[" << 1900 + ltm->tm_year << "-" << 1 + ltm->tm_mon << "-" << ltm->tm_mday
            << " " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << "] "
            << message << endl;
    logFile.close();
}
