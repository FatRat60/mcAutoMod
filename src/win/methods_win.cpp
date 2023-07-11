#include "osMethods.h"
#include <windows.h>
#include <lmcons.h>

int defPathFound(char * username) {
    DWORD usernamelen = UNLEN + 1;
    if (GetUserNameA(username, &usernamelen)) {
        return 1;
    }
    else {
        return 0;
    }
    return 1;
}
