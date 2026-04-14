#include <gtest/gtest.h>

#include "PiSubmarine/Radians.h"

namespace PiSubmarine
{
    TEST(RadiansTest, Literals)
    {
        EXPECT_DOUBLE_EQ(3.14_rad.Value, 3.14);
        EXPECT_DOUBLE_EQ(1_rad.Value, 1.0);
    }

    TEST(RadiansTest, Arithmetic)
    {
        EXPECT_DOUBLE_EQ((1.5_rad + 0.5_rad).Value, 2.0);
        EXPECT_DOUBLE_EQ((1.5_rad - 0.5_rad).Value, 1.0);
        EXPECT_DOUBLE_EQ((-1.5_rad).Value, -1.5);
        EXPECT_DOUBLE_EQ((2_rad * 0.5).Value, 1.0);
        EXPECT_DOUBLE_EQ((2.0 * 2_rad).Value, 4.0);
        EXPECT_DOUBLE_EQ((3_rad / 2.0).Value, 1.5);
    }

    TEST(RadiansTest, NormalizePositiveWrapsAngles)
    {
        EXPECT_DOUBLE_EQ(NormalizePositive(0.5_rad).Value, 0.5);
        EXPECT_DOUBLE_EQ(NormalizePositive(Tau() + 0.5_rad).Value, 0.5);
        EXPECT_DOUBLE_EQ(NormalizePositive(-0.5_rad).Value, Tau().Value - 0.5);
    }

    TEST(RadiansTest, ConvertsToDegrees)
    {
        EXPECT_NEAR(Pi().ToDegrees().Value, 180.0, 1e-12);
        EXPECT_NEAR(Degrees(Pi()).Value, 180.0, 1e-12);
    }
}
