#include <gtest/gtest.h>
#include <filesystem>
#include "file_reader.h"


TEST(fileReader, getCoeffs) {
    std::string fileName = "coeffs.txt";
    {
        {
            std::ofstream stream(fileName);
            stream << "1 2 3\n";
            stream << "2 3\n";
            stream << "\n";
            stream << "1 2 3 4\n";
        }

        FileReader reader(fileName);

        auto resultCall_1 = reader.getCoeffs();
        ASSERT_EQ(resultCall_1.size(), 3);
        std::vector<std::string> expectedCall_1 = {"1", "2", "3"};
        ASSERT_EQ(resultCall_1, expectedCall_1);

        auto resultCall_2 = reader.getCoeffs();
        ASSERT_EQ(resultCall_2.size(), 2);
        std::vector<std::string> expectedCall_2 = {"2", "3"};
        ASSERT_EQ(resultCall_2, expectedCall_2);

        auto resultCall_3 = reader.getCoeffs();
        ASSERT_TRUE(resultCall_3.empty());
        std::vector<std::string> expectedCall_3 = {};
        ASSERT_EQ(resultCall_3, expectedCall_3);

        auto resultCall_4 = reader.getCoeffs();
        ASSERT_EQ(resultCall_4.size(), 4);
        std::vector<std::string> expectedCall_4 = {"1", "2", "3", "4"};
        ASSERT_EQ(resultCall_4, expectedCall_4);

        std::filesystem::remove(fileName);
    }


}