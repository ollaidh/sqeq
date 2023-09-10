#pragma once
#include "utils.h"
#include <iostream>
#include <charconv>
#include <sstream>

// Convert string_view to int:
int stringviewToInt(std::string_view& strv) {
    int result;
    auto conv = std::from_chars(strv.data(), strv.data() + strv.size(), result);
    if (conv.ec == std::errc::invalid_argument || conv.ptr != strv.data() + strv.size()) {
        throw std::invalid_argument("");
    }
    return result;
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
