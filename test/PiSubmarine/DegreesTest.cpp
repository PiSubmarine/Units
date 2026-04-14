#include <gtest/gtest.h>

#include "PiSubmarine/Degrees.h"

namespace PiSubmarine
{
    TEST(DegreesTest, Literals)
    {
        EXPECT_DOUBLE_EQ(180_deg.Value, 180.0);
        EXPECT_DOUBLE_EQ(12.5_deg.Value, 12.5);
    }

    TEST(DegreesTest, Arithmetic)
    {
        EXPECT_DOUBLE_EQ((180_deg + 45_deg).Value, 225.0);
        EXPECT_DOUBLE_EQ((180_deg - 45_deg).Value, 135.0);
        EXPECT_DOUBLE_EQ((-45_deg).Value, -45.0);
        EXPECT_DOUBLE_EQ((90_deg * 2.0).Value, 180.0);
        EXPECT_DOUBLE_EQ((0.5 * 90_deg).Value, 45.0);
        EXPECT_DOUBLE_EQ((180_deg / 2.0).Value, 90.0);
    }

    TEST(DegreesTest, ConvertsToRadians)
    {
        EXPECT_NEAR(180_deg.ToRadians().Value, Pi().Value, 1e-12);
        EXPECT_NEAR(Radians(90_deg).Value, Pi().Value / 2.0, 1e-12);
    }
}
