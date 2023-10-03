#include <gtest/gtest.h>
#include <filesystem>
#include "file_reader.h"


TEST(fileReader, getCoeffs) {
    FileReader reader(std::make_unique<std::stringstream>("1 2 3\n2 3\n1 2 3 4"));

    auto resultCall_1 = reader.getCoeffs();
    ASSERT_EQ(resultCall_1.size(), 3);
    std::vector<std::string> expectedCall_1 = {"1", "2", "3"};
    ASSERT_EQ(resultCall_1, expectedCall_1);

    auto resultCall_2 = reader.getCoeffs();
    ASSERT_EQ(resultCall_2.size(), 2);
    std::vector<std::string> expectedCall_2 = {"2", "3"};
    ASSERT_EQ(resultCall_2, expectedCall_2);

    auto resultCall_4 = reader.getCoeffs();
    ASSERT_EQ(resultCall_4.size(), 4);
    std::vector<std::string> expectedCall_4 = {"1", "2", "3", "4"};
    ASSERT_EQ(resultCall_4, expectedCall_4);

}