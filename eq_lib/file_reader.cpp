#include "file_reader.h"
#include "utils.h"

FileReader::FileReader(std::unique_ptr<std::istream> stream) :
        m_stream(std::move(stream))
{
    if (m_stream->bad()) {
        throw std::invalid_argument("Unable to open input stream!");
    }
}

std::vector<std::string> FileReader::getCoeffs() {
    std::string line;
    if (std::getline(*m_stream, line)) {
        return splitString(line, ' ');
    }
    return {};
};

