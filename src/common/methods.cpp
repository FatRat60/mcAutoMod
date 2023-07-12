#include "methods.h"
#include <sys/stat.h>
#include "dirent.h"
#include <iostream>
#include <cstring>
#include <fstream>

int isInstallation(std::string pathToCheck, char (*fileList)[261], int rows) {
    DIR * dirToCheck = opendir(pathToCheck.c_str());
    struct dirent * entry;

    if (!dirToCheck) {
        // DNE or, more likely, is a file not dir
        return 0;
    }

    int score = 0;
    while ((entry = readdir(dirToCheck)) != NULL) {
        for (int i = 0; i < rows; i++) {
            if (strcmp(fileList[i], entry->d_name) == 0) {
                // match found, inc score
                score++;
                break;
            }
        }
    }

    closedir(dirToCheck);
    return score >= THRESHOLD;
}

int countFiles() {
    std::ifstream file(INSTALL_FILES);
    if (!file) {
        std::cerr << "Could not open install files list" << std::endl;
        return 0;
    }
    std::string line;
    int numFiles = 0;
    while (std::getline(file, line))
        numFiles++;
    file.close();
    return numFiles;
}

int fileListInit(char (*fileList)[261], int rows) {
    std::ifstream file(INSTALL_FILES);
    //shouldn't have to check if exists again
    std::string line;
    int lineNum = 0;
    while (std::getline(file, line)) {
        // remove \n
        if (line.back() == '\n')
            line.pop_back();
            // copy string to array
        for (int i = 0; i < line.length(); i++)
            fileList[lineNum][i] = line[i];
        // add null
        fileList[lineNum][line.length()] = '\0';
        lineNum++;
    }
    return lineNum;
}

int discover_installations(std::string dirPath, std::vector<std::string> & installationList) {
    // open dir and make sure exists
    DIR * parent = opendir(dirPath.c_str());
    struct dirent * entry;

    if (!parent) {
        // default mc directory DNE so return 0 
        std::cerr << "Directory not found" << std::endl;
        return 0;
    }

    int numFiles = countFiles();
    if (numFiles > 0){
        char compareFiles[numFiles][261];
        numFiles = fileListInit(compareFiles, numFiles);

        // read twice to skip . and ..
        readdir(parent);
        readdir(parent);
        while ((entry = readdir(parent)) != NULL) {
            std::string pathToCheck = dirPath + std::string(entry->d_name);
            if (isInstallation(pathToCheck, compareFiles, numFiles)) {
                std::cout << entry->d_name << std::endl;
                installationList.push_back(pathToCheck);
            }
        }
    }

    closedir(parent);
    return installationList.size();
}
