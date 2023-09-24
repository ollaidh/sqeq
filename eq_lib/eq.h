#pragma once
#include <iostream>

class Equation {
public:
    virtual ~Equation() = default;
    virtual void solve() = 0;
    [[nodiscard]] virtual std::vector<int> getRoots() const = 0;
    bool operator==(const Equation& other) const;
protected:
    std::vector<int> m_coeffs;
    std::vector<int> m_roots;
    bool m_isSolved{};
};

std::unique_ptr<Equation> createEquation(const std::vector<int>& coeffs);

