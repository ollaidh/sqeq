#pragma once
#include <iostream>
#include <fstream>
#include "reader.h"

// This class reads coeffs from file.
// This class takes ownership of an istream
// (used to read from file)
class FileReader : public Reader {
public:
    explicit FileReader(std::unique_ptr<std::istream> stream);
    std::vector<std::string> getCoeffs() override;
private:
    std::unique_ptr<std::istream> m_stream;
};