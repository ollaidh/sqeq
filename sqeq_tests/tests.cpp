#include <gtest/gtest.h>
#include "sqeq.h"

TEST(Utils, transformParameters) {
    // number of input coeffs is not a multiple of 3, assuming that missing coeffs are zeros in the end of the pack
    char *input[] = {"path/to/app", "1", "12", "3", "24"};
    std::vector<int> expected = {1, 12, 3, 24, 0, 0};
    ASSERT_EQ(expected, transformParams(5, input));
}

TEST(Utils, transformParametersErrNumber) {
    // no coefficients provided
    char *input[] = {"path/to/app"};
    ASSERT_THROW(transformParams(1, input), std::invalid_argument);
}

TEST(Utils, transformParametersErrType) {
    // one or more provided coefficients can't be converted to int
    char *input[] = {"path/to/app", "1", "aaa", "3"};
    ASSERT_THROW(transformParams(1, input), std::invalid_argument);
}

TEST(Utils, collecttParams) {
    char *input[] = {"path/to/app", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    std::vector<QueqParam> expected = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };
    ASSERT_EQ(expected, collectParameters(10, input));
}

TEST(QE, qeSolveOk) {
    // has solution: 2 different roots
    QueqParam coeffs{1, -2, -3};
    QuadraticEquation equation(coeffs);
    equation.solve();
    ASSERT_TRUE(equation.isSolved());
    ASSERT_EQ(3, equation.x1());
    ASSERT_EQ(-1, equation.x2());

    // has solution: 2 identical roots
    QueqParam coeffs2{1, 2, 1};
    QuadraticEquation equation2(coeffs2);
    equation2.solve();
    ASSERT_TRUE(equation2.isSolved());
    ASSERT_EQ(-1, equation2.x1());
    ASSERT_EQ(-1, equation2.x2());

}

TEST(QE, qeSolveNoSolution) {
    // has no real roots
    QueqParam coeffs3{1, 4, 5};
    QuadraticEquation equation3(coeffs3);
    equation3.solve();
    ASSERT_TRUE(equation3.isSolved());
    ASSERT_FALSE(equation3.isSolved().value());
}

TEST(QE, qeExtremums) {
    QueqParam coeffs{1, -2, -3};
    QuadraticEquation equation(coeffs);
    equation.findExtremums();
    ASSERT_EQ(1, equation.xExtr());
    ASSERT_EQ(-4, equation.yExtr());

    QueqParam coeffs2{1, 4, 5};
    QuadraticEquation equation2(coeffs2);
    equation2.findExtremums();
    ASSERT_EQ(-2, equation2.xExtr());
    ASSERT_EQ(1, equation2.yExtr());
}