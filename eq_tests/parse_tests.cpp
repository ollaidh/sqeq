#include <gtest/gtest.h>

#include "parse.h"

TEST(parse, basic) {
    {
        std::vector<std::string> input = {"1", "2", "3"};
        std::vector<int> expected = {1, 2, 3};
        ASSERT_EQ(parseCoeffs(input), expected);
    }
    {
        std::vector<std::string> input = {"42", "314", "256"};
        std::vector<int> expected = {42, 314, 256};
        ASSERT_EQ(parseCoeffs(input), expected);
    }
    {
        std::vector<std::string> input = {"-273"};
        std::vector<int> expected = {-273};
        ASSERT_EQ(parseCoeffs(input), expected);
    }
}

TEST(parse, invalid) {
    {
        std::vector<std::string> input = {"1", "2", "3", "blah"};
        std::vector<int> expected = {};
        ASSERT_EQ(parseCoeffs(input), expected);
    }
    {
        std::vector<std::string> input = {"blah", "1", "2", "3"};
        std::vector<int> expected = {};
        ASSERT_EQ(parseCoeffs(input), expected);
    }
    {
        std::vector<std::string> input = {"3.14", "2", "3"};
        std::vector<int> expected = {};
        ASSERT_EQ(parseCoeffs(input), expected);
    }
    {
        std::vector<std::string> input = {};
        std::vector<int> expected = {};
        ASSERT_EQ(parseCoeffs(input), expected);
    }
}

TEST(parse, leadingZeros) {
    {
        std::vector<std::string> input = {"0", "1", "2"};
        std::vector<int> expected = {1, 2};
        ASSERT_EQ(parseCoeffs(input), expected);
    }
    {
        std::vector<std::string> input = {"0", "0", "0", "1"};
        std::vector<int> expected = {1};
        ASSERT_EQ(parseCoeffs(input), expected);
    }
    {
        std::vector<std::string> input = {"0", "0", "0"};
        std::vector<int> expected = {};
        ASSERT_EQ(parseCoeffs(input), expected);
    }
}
