#include <gtest/gtest.h>
#include "factory.h"
#include "lneq.h"
#include "queq.h"
#include "cbeq.h"
#include "utils.h"

TEST(factory, basic) {
    std::vector<int> input{1, 2, 3};
    auto result = createEquation(input);
    ASSERT_NE(dynamic_cast<QuadraticEquation*>(result.get()), nullptr);
}
