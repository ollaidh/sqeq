#include <gtest/gtest.h>
#include "queq.h"
#include "utils.h"

TEST(Utils, strviewToInt) {
    ASSERT_EQ(-1, stringviewToInt("-1"));
}
