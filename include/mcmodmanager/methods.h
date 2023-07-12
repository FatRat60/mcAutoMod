#include <string>
#include <vector>

#ifndef METHODS_H
#define METHODS_H

#define THRESHOLD 8
#define INSTALL_FILES "../installationFiles.txt"

int discover_installations(std::string dirPath, std::vector<std::string> & installationList);
int isInstallation(std::string pathToCheck, char (*fileList)[261], int rows);
int countFiles();
int fileListInit(char (*fileList)[261], int rows);

#endif
