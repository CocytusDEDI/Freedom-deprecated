#include <libfreedom.h>
#include <stdio.h>
#include <wchar.h>
#include <locale.h>

wchar_t bool_to_mark(int freedom_int) {
    switch (freedom_int) {
        case 0:
            return L'✗';
        case 1:
            return L'✓';
        default:
            return L'-';
    }
}

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "");

    SystemDataResult system_data_result = get_system_data();
    if (system_data_result.status != 0) {
        fprintf(stderr, "failed to get system data: %s\n", system_data_result.error);
        return 1;
    }

    SystemFreedomResult system_freedom_result = get_system_freedom(&system_data_result.system_data);

    if (system_freedom_result.status != 0) {
        fprintf(stderr, "failed to get system freedom: %s\n", system_freedom_result.error);
        return 1;
    }

    wprintf(L"os: %s %lc\n", system_data_result.system_data.os_name,
            bool_to_mark(system_freedom_result.system_freedom.os));
    wprintf(L"architecture: %s %lc\n", system_data_result.system_data.architecture,
            bool_to_mark(system_freedom_result.system_freedom.architecture));
    wprintf(L"firmware: %s %lc\n", system_data_result.system_data.firmware,
            bool_to_mark(system_freedom_result.system_freedom.firmware));
}
