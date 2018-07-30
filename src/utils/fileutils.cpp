//
// Created by angus on 7/29/18.
//

#include <fstream>
#include <iostream>
#include "fileutils.h"


std::string gengine::readFile(const char *filepath) {
    std::ifstream file(filepath);
    std::string data;

    if (!file) {
        std::cout << "Failed to open file: " << filepath << std::endl;
        return "";
    }
    file.seekg(0, std::ios::end);
    data.reserve(file.tellg());
    file.seekg(0, std::ios::beg);

    data.assign((std::istreambuf_iterator<char>(file)),
                std::istreambuf_iterator<char>());
    return data;
}
