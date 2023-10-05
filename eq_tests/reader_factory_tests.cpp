#include <gtest/gtest.h>

#include "reader_factory.h"

#include "cmd_reader.h"


TEST(readerFactory, basic) {
    {
        int argc = 1;
        const char *argv[] = {"path"};
        ASSERT_THROW(createReader(argc, argv), std::invalid_argument);
    }

    {
        int argc = 5;
        const char *argv[] = {"path", "Q", "1", "2", "3"};

        auto reader = createReader(argc, argv);
        ASSERT_NE(reader, nullptr);
        ASSERT_NE(dynamic_cast<CommandlineReader *>(reader.get()), nullptr);
    }

    {
        int argc = 2;
        const char *argv[] = {"path", "coeffs.txt"};
        ASSERT_THROW(createReader(argc, argv), std::invalid_argument);
    }
    // Here we're not testing reader creation with non-valid file as we test it in integration tests
}