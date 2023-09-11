#include <iostream>
#include <fstream>
#include "solve.h"
#include "utils.h"

// Read coeffs input sequence from file:
void solveFromFile(std::string &filepath) {
    std::vector<std::string> result;
    std::ifstream file(filepath);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::vector<std::string> coeffs;
            coeffs = splitString(line, ' ');
        }
    }
}
