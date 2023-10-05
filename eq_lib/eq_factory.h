#pragma once

#include <iostream>

#include "eq.h"

// create object of type LinearEquation, QuadraticEquation,
// CubicEquation depending on number of provided coefficients:
std::unique_ptr<Equation> createEquation(const std::vector<int>& coeffs);


