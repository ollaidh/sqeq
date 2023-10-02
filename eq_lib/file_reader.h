#include <iostream>
#include <fstream>

class FileReader {
public:
    FileReader(std::istream* stream);
    std::vector<std::string> getCoeffs();
private:
    std::istream* m_stream;
};