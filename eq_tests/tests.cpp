#include <gtest/gtest.h>

#include "utils.h"

TEST(Utils, strviewToInt) {
    ASSERT_EQ(-1, stringviewToInt("-1"));
}
