#include <iostream>

class CommandlineReader {
public:
    CommandlineReader(int argc, const char ** arguments);
    std::vector<std::string> getCoeffs();
private:
    const char ** m_argv;
    int m_argc;
    int m_currInd;
};
