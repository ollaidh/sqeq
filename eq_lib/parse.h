#pragma once

#include <vector>
#include <string>
#include <charconv>

template <typename S>
std::vector<int> parseCoeffs(const std::vector<S>& input)
{
    std::vector<int> result;
    result.reserve(input.size());
    for (const auto& coeff : input)
    {
        int converted;
        auto conv = std::from_chars(coeff.data(), coeff.data() + coeff.size(), converted);
        if (conv.ec == std::errc::invalid_argument || conv.ptr != coeff.data() + coeff.size()) {
            return {};
        }
        if (result.empty() && converted == 0)
            continue;
        result.push_back(converted);
    }
    return result;
}
