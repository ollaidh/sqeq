#include <string>
#include <vector>

// Convert string_view to int if possible:
int stringviewToInt(std::string_view strv);

// Split string by given separator:
std::vector<std::string> splitString(const std::string& word, const char& separator);

// get sign of the value: returns 1 if >=0 and -1 if < 0
int sign(double x);
