//#pragma once
#include "utils.h"
#include <iostream>
#include <charconv>
#include <sstream>

// Convert string_view to int:
int stringviewToInt(std::string_view strv) {
    int result;
    auto conv = std::from_chars(strv.data(), strv.data() + strv.size(), result);
    if (conv.ec == std::errc::invalid_argument || conv.ptr != strv.data() + strv.size()) {
        throw std::invalid_argument("");
    }
    return result;
}

int stringToInt(const std::string& str) {
    std::string::const_iterator it = str.begin();
    while (it != str.end() && std::isdigit(*it)) ++it;
    if (str.empty() || it != str.end()) {
        throw std::invalid_argument("");
    }
    return std::stoi(str);
}

// Split string by given separator:
std::vector<std::string> splitString(const std::string& word, const char& separator) {
    std::vector<std::string> result;
    std::string  s;
    std::istringstream ss(word);
    while (getline(ss, s, separator)) {
        if (!s.empty()) {
            result.push_back(s);
        }
    }
    return result;
}

int sign(double x) {
    if (x < 0) {
        return -1;
    } else if (x > 0) {
        return 1;
    } else {
        return 0;
    }
}
