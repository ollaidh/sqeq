#pragma once

#include <vector>
#include <string>

template <typename S>
std::vector<int> parseCoeffs(const std::vector<S>& input)
{
    std::vector<int> result;
    try {
        for (const auto& coeff : input) {
            int c = 0;
            if (!result.empty() || (result.empty() && c != 0)) {
                result.push_back(c);
            }
        }
        return result;
    } catch (const std::invalid_argument&)  {
        throw std::invalid_argument("Wrong input: Non-INT coefficients.");
    };
}
