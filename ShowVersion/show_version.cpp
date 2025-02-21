#include "show_version.h"

// Show version and build date
void showVersion() {
    cout << "Application Version: " << VERSION << endl;
    cout << "Build Date: " << __DATE__ << " " << __TIME__ << "\n";
    logEvent("Show version: " + VERSION + ": " + __DATE__ + " " + __TIME__);
}