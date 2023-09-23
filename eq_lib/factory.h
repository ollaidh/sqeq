#pragma once
#include <iostream>
#include "eq.h"

std::unique_ptr<Equation> createEquation(const std::vector<int>& coeffs);


