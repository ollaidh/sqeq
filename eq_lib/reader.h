#pragma once

#include <iostream>
#include <vector>

class Reader {
public:
    virtual ~Reader() = default;
    virtual std::vector<std::string> getCoeffs() = 0;  //get coeffs of one equation as vector of strings
    [[nodiscard]] virtual bool atEnd() const = 0;  //get state - if end of file or end of command line arguments is reached
};