#include <iostream>
#include <fstream>
#include "reader.h"

class FileReader : Reader {
public:
    explicit FileReader(std::istream* stream);
    std::vector<std::string> getCoeffs() override;
private:
    std::istream* m_stream;
};