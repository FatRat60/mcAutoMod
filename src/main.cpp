#include "osMethods.h"
#include "methods.h"
#include <iostream>
#include <lmcons.h>

using namespace std;

int main() {
    char username[UNLEN + 1];
    if (defPathFound(username)) {
        cout << "Username: " << username << endl;
    }
    return 0;
}
