#include <gtest/gtest.h>
#include "PiSubmarine/SignedNormalizedFraction.h"

namespace PiSubmarine
{
    TEST(SignedNormalizedFractionTest, ConstructAndCompare)
    {
        constexpr SignedNormalizedFraction fraction1 = -0.95;
        constexpr SignedNormalizedFraction fraction2 = 0.99;
        static_assert(fraction1 < fraction2, "Fraction1 must be greater than Fraction2");
    }

    TEST(SignedNormalizedFractionTest, ToDouble)
    {
        constexpr SignedNormalizedFraction fraction1 = -0.95;
        constexpr double d = fraction1;
        static_assert(d == fraction1);
        static_assert(fraction1 == -0.95);
    }
}