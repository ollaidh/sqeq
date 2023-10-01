#include "cmd_reader.h"
#include <map>


CommandlineReader::CommandlineReader(int argc, const char **argv) {
    m_argc = argc;
    m_argv = argv;
    m_currInd = 1;
}

std::vector<std::string_view> CommandlineReader::getCoeffs() {
    std::vector<std::string_view> result;

    int len = 0;
    if (m_argv[m_currInd][0] == 'L') {
        len = 2;
    } else if (m_argv[m_currInd][0] == 'Q') {
        len = 3;
    } else if (m_argv[m_currInd][0] == 'C') {
        len = 4;
    }
    for (int i = 0; i < len; i++) {
        int j = m_currInd + i + 1;
        if (i > m_argc) {
            return {};
        }
        result.emplace_back(m_argv[j]);
    }
    m_currInd += len + 1;
    return result;
}



