#include "file_reader.h"
#include "utils.h"

FileReader::FileReader(std::istream* stream) :
        m_stream(stream)
{

}

std::vector<std::string> FileReader::getCoeffs() {
    std::string line;
    if (std::getline(*m_stream, line)) {
        return splitString(line, ' ');
    }
    return {};
};

