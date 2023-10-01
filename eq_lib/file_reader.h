#include <iostream>
#include <fstream>

class FileReader {
public:
    FileReader(const std::string& filepath);
    std::vector<std::string> getCoeffs();
private:
    std::ifstream m_file;
};