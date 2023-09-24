#include <gtest/gtest.h>
#include "factory.h"
#include "lneq.h"
#include "queq.h"
#include "cbeq.h"
#include "utils.h"

TEST(factory, basic) {
    std::vector<int> qu_input{1, 2, 3};
    auto qu_result = createEquation(qu_input);
    ASSERT_NE(dynamic_cast<QuadraticEquation*>(qu_result.get()), nullptr);
    ASSERT_EQ(QuadraticEquation(qu_input), *qu_result);

    std::vector<int> ln_input{1, 2};
    auto ln_result = createEquation(ln_input);
    ASSERT_NE(dynamic_cast<LinearEquation*>(ln_result.get()), nullptr);
    ASSERT_EQ(LinearEquation(ln_input), *ln_result);

    std::vector<int> cb_input{1, 2, 3, 4};
    auto cb_result = createEquation(cb_input);
    ASSERT_NE(dynamic_cast<CubicEquation*>(cb_result.get()), nullptr);
    ASSERT_EQ(CubicEquation(cb_input), *cb_result);

}

TEST(Equations, equalOperator) {
    LinearEquation lneq1({1, 2});
    LinearEquation lneq2({5, 6});
    ASSERT_NE(lneq1, lneq2);

    LinearEquation lneq3({1, 2});
    LinearEquation lneq4({1, 2});
    ASSERT_EQ(lneq3, lneq4);

    QuadraticEquation lneq5({1, 2, 3});
    LinearEquation lneq6({5, 6});
    ASSERT_NE(lneq5, lneq6);
}

