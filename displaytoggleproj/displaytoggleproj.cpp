#include <windows.h>
#include <iostream>
#include <vector>

bool isExtendMode() {
    // Check how many active displays are detected
    DISPLAY_DEVICE dd;
    dd.cb = sizeof(dd);
    int activeDisplays = 0;

    for (DWORD i = 0; EnumDisplayDevices(nullptr, i, &dd, 0); i++) {
        if (dd.StateFlags & DISPLAY_DEVICE_ACTIVE) {
            activeDisplays++;
        }
    }

    // If more than one display is active, assume it's in Extend Mode
    return activeDisplays > 1;
}

void toggleDisplayMode() {
    std::string command;

    if (isExtendMode()) {
        std::cout << "Switching to Duplicate Mode..." << std::endl;
        command = "DisplaySwitch.exe /clone";
    }
    else {
        std::cout << "Switching to Extend Mode..." << std::endl;
        command = "DisplaySwitch.exe /extend";
    }

    // Execute DisplaySwitch command
    system(command.c_str());
}

int main() {
    toggleDisplayMode();
    return 0;
}
