#include "cmd_reader.h"
#include <map>


CommandlineReader::CommandlineReader(int argc, const char **argv) {
    m_argc = argc;
    m_argv = argv;
    m_currInd = 1;
}

std::vector<std::string> CommandlineReader::getCoeffs() {
    std::vector<std::string> result;

    int len = 0;
    if (m_argv[m_currInd][0] == 'L') {
        len = 2;
    } else if (m_argv[m_currInd][0] == 'Q') {
        len = 3;
    } else if (m_argv[m_currInd][0] == 'C') {
        len = 4;
    }
    m_atEnd = m_currInd + len + 1 >= m_argc;
    for (int i = 0; i < len; i++) {
        int j = m_currInd + i + 1;
        if (j >= m_argc) {
            return {};
        }
        result.emplace_back(m_argv[j]);
    }
    m_currInd += len + 1;
    return result;
}

bool CommandlineReader::atEnd() const {
    return m_atEnd;
}



