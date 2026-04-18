#include <gtest/gtest.h>

#include "PiSubmarine/AmpereHours.h"

namespace PiSubmarine
{
    TEST(AmpereHoursTest, Literals)
    {
        EXPECT_DOUBLE_EQ(1_Ah.Value, 1.0);
        EXPECT_DOUBLE_EQ(2.5_Ah.Value, 2.5);
    }

    TEST(AmpereHoursTest, ConvertsToCoulombs)
    {
        EXPECT_NEAR(AmpereHours(1_C).Value, 1.0 / 3600.0, 1e-15);
        EXPECT_DOUBLE_EQ(2_Ah.ToCoulombs().Value, 7200.0);
    }
}
