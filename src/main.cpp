/*
* @file main.cpp
* @brief This file contains the main function, for now it only checks if the path exists or not.
* @version 0.0.1
* @author PhillipNoir
*/

#include <filesystem>
#include <iostream>
#include <cstdlib>

int main() {
    const char* homeDir {getenv("HOME")};
    if (homeDir == nullptr) {
        std::cout << "The Home Directory Environment Variable is not set. Add it manually. \n";
        return 1;
    }
    
    std::filesystem::path executablePath {std::filesystem::path(homeDir) / "Documents" / "GTAIV_Pruebas"};
    if (std::filesystem::exists(executablePath)) {
    std::cout << "The Path Exists \n";
    }
    else {
        std::cout << "The Path Does Not Exist \n";
    }
    return 0;
}