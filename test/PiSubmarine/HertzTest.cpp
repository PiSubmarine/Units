#include <gtest/gtest.h>
#include "PiSubmarine/Hertz.h"

namespace PiSubmarine
{
    TEST(HertzTest, Literals)
    {
        ASSERT_EQ(123_Hz.Value, 123.0);
        ASSERT_EQ(1.5_KHz.Value, 1500.0);
        ASSERT_EQ(2_MHz.Value, 2000000.0);
        ASSERT_EQ(3_GHz.Value, 3000000000.0);
    }
}
