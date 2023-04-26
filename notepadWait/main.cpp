#include <windows.h>
#include <cstdio>

int main() {
    STARTUPINFOW si = { 0 };
    PROCESS_INFORMATION pi = { nullptr };
if(!CreateProcessW(
            L"C:\\Windows\\System32\\notepad.exe",
            nullptr,
            nullptr,
            nullptr,
            FALSE,
            BELOW_NORMAL_PRIORITY_CLASS,
            nullptr,
            nullptr,
            &si,
            &pi
        )){
        printf("(-) failed to create process, error: %ld", GetLastError());
        return EXIT_FAILURE;
    }

    printf("(+) process started! pid: %ld\n", pi.dwProcessId);

    if (WaitForSingleObject(
        pi.hProcess,
        INFINITE
            ) != WAIT_OBJECT_0) {
        printf("Unable to wait??");
    } else {
        printf("Quit bro");
    }

    return EXIT_SUCCESS;
}
