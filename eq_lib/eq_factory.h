#pragma once

#include <iostream>
#include <memory>

#include "eq.h"

// create object of type LinearEquation, QuadraticEquation,
// CubicEquation depending on number of provided coefficients:
std::unique_ptr<Equation> createEquation(std::vector<int>&& coeffs);


