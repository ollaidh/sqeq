#pragma once

#include <iostream>
#include <vector>

class Reader {
public:
    virtual ~Reader() = default;
    virtual std::vector<std::string> getCoeffs() = 0;
    [[nodiscard]] virtual bool atEnd() const = 0;
};