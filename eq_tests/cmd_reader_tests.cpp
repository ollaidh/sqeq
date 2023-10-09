#include <gtest/gtest.h>

#include "cmd_reader.h"

TEST(cmdReader, getCoeffs) {
    const char * argv[] = {"path", "Q", "1", "2", "3", "4", "L", "4", "5", "C", "11", "12"};
    CommandlineReader reader(11, argv);

    auto resultCall_1 = reader.getCoeffs();
    ASSERT_EQ(resultCall_1.size(), 3);
    std::vector<std::string> expectedCall_1 = {"1", "2", "3"};
    ASSERT_EQ(resultCall_1, expectedCall_1);

    auto resultCall_2 = reader.getCoeffs();
    ASSERT_TRUE(resultCall_2.empty());
    std::vector<std::string> expectedCall_2 = {};
    ASSERT_EQ(resultCall_2, expectedCall_2);

    auto resultCall_3 = reader.getCoeffs();
    ASSERT_EQ(resultCall_3.size(), 2);
    std::vector<std::string> expectedCall_3 = {"4", "5"};
    ASSERT_EQ(resultCall_3, expectedCall_3);

    auto resultCall_4 = reader.getCoeffs();
    ASSERT_TRUE(resultCall_4.empty());
    std::vector<std::string> expectedCall_4 = {};
    ASSERT_EQ(resultCall_4, expectedCall_4);

    ASSERT_TRUE(reader.atEnd());

}