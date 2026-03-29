#include <gtest/gtest.h>
#include "PiSubmarine/NormalizedFraction.h"

namespace PiSubmarine
{
    TEST(NormalizedFractionTest, ConstructAndCompare)
    {
        constexpr NormalizedFraction fraction1 = 0.95;
        constexpr NormalizedFraction fraction2 = 0.99;
        static_assert(fraction1 < fraction2, "Fraction1 must be greater than Fraction2");
    }

    TEST(NormalizedFractionTest, ToDouble)
    {
        constexpr NormalizedFraction fraction1 = 0.95;
        constexpr double d = fraction1;
        static_assert(d == fraction1);
    }
}