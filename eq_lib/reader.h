#pragma once
#include <iostream>

class Reader {
public:
    virtual ~Reader() = default;
    virtual std::vector<std::string> getCoeffs() = 0;
};