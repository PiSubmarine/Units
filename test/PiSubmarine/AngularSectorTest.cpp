#include <gtest/gtest.h>

#include "PiSubmarine/AngularSector.h"

namespace PiSubmarine
{
    TEST(AngularSectorTest, ContainsAnglesInsideContinuousSector)
    {
        constexpr AngularSector sector(1.0_rad, 1.5_rad);

        EXPECT_TRUE(sector.Contains(1.0_rad));
        EXPECT_TRUE(sector.Contains(2.0_rad));
        EXPECT_TRUE(sector.Contains(2.5_rad));
        EXPECT_FALSE(sector.Contains(2.5001_rad));
        EXPECT_FALSE(sector.Contains(0.9999_rad));
    }

    TEST(AngularSectorTest, ContainsAnglesAcrossWrapAround)
    {
        constexpr AngularSector sector(Tau() - 0.5_rad, 1.0_rad);

        EXPECT_TRUE(sector.Contains(Tau() - 0.25_rad));
        EXPECT_TRUE(sector.Contains(0.25_rad));
        EXPECT_FALSE(sector.Contains(0.75_rad));
    }

    TEST(AngularSectorTest, FullCircleContainsEveryEquivalentAngle)
    {
        constexpr AngularSector sector(1.0_rad, Tau());

        EXPECT_TRUE(sector.Contains(1.0_rad));
        EXPECT_TRUE(sector.Contains(Tau() + 1.0_rad));
        EXPECT_TRUE(sector.Contains(-2.0_rad));
    }

    TEST(AngularSectorTest, InvalidSectorDoesNotContainAngles)
    {
        constexpr AngularSector sector(0.0_rad, -0.1_rad);

        EXPECT_FALSE(sector.IsValid());
        EXPECT_FALSE(sector.Contains(0.0_rad));
    }
}
