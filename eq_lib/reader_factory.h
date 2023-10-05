#pragma once

#include <iostream>
#include <memory>

#include "reader.h"

std::unique_ptr<Reader> createReader(int argc, const char **argv);
