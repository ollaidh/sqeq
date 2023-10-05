#include <gtest/gtest.h>

#include "reader_factory.h"

#include "cmd_reader.h"
#include "file_reader.h"


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
        const char *argv[] = {"path", "some_file.txt"};
        ASSERT_THROW(createReader(argc, argv), std::invalid_argument);
    }

    {
        int argc = 2;
        const char *argv[] = {"path", "coeffs.txt"};
        auto reader = createReader(argc, argv);
        ASSERT_NE(reader, nullptr);
        ASSERT_NE(dynamic_cast<FileReader*>(reader.get()), nullptr);
    }
}