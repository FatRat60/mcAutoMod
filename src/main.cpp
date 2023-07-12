#include "osMethods.h"
#include "methods.h"
#include <iostream>
#include <lmcons.h>
#include <string>
#include <vector>

using namespace std;

int main() {
    char username[UNLEN + 1];
    size_t username_len;
    if (defPathFound(username)) {
        string user(username);
        string path = "C:/Users/";
        path.append(user);
        path.append("/AppData/Roaming/");
        cout << path << endl;
        vector<string> installationList;
        (void) discover_installations(path, installationList);
    }
    return 0;
}
