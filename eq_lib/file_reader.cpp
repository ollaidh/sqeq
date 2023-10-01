#include "file_reader.h"
#include "utils.h"

FileReader::FileReader(const std::string& filepath) :
    m_file(filepath)
{

}

std::vector<std::string> FileReader::getCoeffs() {
    std::string line;
    while (std::getline(m_file, line)) {
        return splitString(line, ' ');
    }
    return {};
};

