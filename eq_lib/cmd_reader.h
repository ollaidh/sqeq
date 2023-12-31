#include <iostream>
#include <vector>

#include "reader.h"

class CommandlineReader : public Reader{
public:
    CommandlineReader(int argc, const char **arguments);
    std::vector<std::string> getCoeffs() override;
    [[nodiscard]] bool atEnd() const override;
private:
    const char ** m_argv;
    int m_argc;
    int m_currInd;
    bool m_atEnd;
};
