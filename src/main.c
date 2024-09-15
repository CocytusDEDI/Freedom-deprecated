#include <stdio.h>
#include <sys/utsname.h>
#include <string.h>

int main() {
    struct utsname hardwareinfo;

    if (uname(&hardwareinfo) == 0) {
        if (strcmp(hardwareinfo.machine, "riscv64") == 0 || strcmp(hardwareinfo.machine, "riscv32") == 0) {
            printf("Architecture: %s ✔\n", hardwareinfo.machine);
        } else {
            printf("Architecture: %s ✖\n", hardwareinfo.machine);
        }
    } else {
        perror("uname failed");
        return 1;
    }

    return 0;
}
