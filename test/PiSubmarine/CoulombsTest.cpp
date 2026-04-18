#include <gtest/gtest.h>

#include "PiSubmarine/Coulombs.h"

namespace PiSubmarine
{
    TEST(CoulombsTest, Literals)
    {
        EXPECT_DOUBLE_EQ(1_C.Value, 1.0);
        EXPECT_DOUBLE_EQ(1.5_C.Value, 1.5);
    }

    TEST(CoulombsTest, ConvertsToAmpereHours)
    {
        EXPECT_DOUBLE_EQ(Coulombs(2_Ah).Value, 7200.0);
        EXPECT_NEAR(1_C.ToAmpereHours().Value, 1.0 / 3600.0, 1e-15);
    }
}
