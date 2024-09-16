#include <stdio.h>
#include <sys/utsname.h>

int main() {
    return 0;
}

struct system_freedom {
    char os_name[128];         // Operating system name
    char architecture[32];     // CPU architecture
    char firmware_type[64];    // Type of firmware (e.g., BIOS, UEFI, Coreboot)
    int proprietary_drivers;   // Number of proprietary_drivers
};

struct system_freedom get_hardware_freedom() {
    struct system_freedom system_freedom_struct;

    struct utsname hardwareinfo;

    if (uname(&hardwareinfo) == 0) {
        snprintf(system_freedom_struct.os_name, sizeof(system_freedom_struct.os_name), "%s", hardwareinfo.sysname);
        snprintf(system_freedom_struct.architecture, sizeof(system_freedom_struct.architecture), "%s", hardwareinfo.machine);
    } else {
        perror("Hardware detection failure: utsname failed");
    }

    return system_freedom_struct;
}
