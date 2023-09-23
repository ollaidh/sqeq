#include "eq.h"
#include "lneq.h"
#include "queq.h"
#include "cbeq.h"
#include "utils.h"

std::vector<int> verifyCoeffsPack(const std::vector<std::string>& input) {
    std::vector<int> result;
    try {
        for (const std::string& coeff : input) {
            int c = stringToInt(coeff);
            if (!result.empty() || (result.empty() && c != 0)) {
                result.push_back(c);
            }
        }
        return result;
    } catch (const std::invalid_argument&)  {
        throw std::invalid_argument("Wrong input: Non-INT coefficients.");
    };
}

std::unique_ptr<Equation> createEquation(const std::vector<int>& coeffs) {
    std::size_t coeffsAmount = coeffs.size();

    if (coeffsAmount == 2) {
        return std::make_unique<LinearEquation>(coeffs);
    } else if (coeffsAmount == 3) {
        return std::make_unique<QuadraticEquation>(coeffs);
    } else if (coeffsAmount == 4) {
        return std::make_unique<CubicEquation>(coeffs);
    } else {
        // TODO change into Raise Error:
        std::cout << "Wrong amount of coeffs: " << coeffsAmount << "\n";
        return nullptr;
    }
}
