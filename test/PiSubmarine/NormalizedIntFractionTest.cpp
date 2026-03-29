#include <gtest/gtest.h>
#include "PiSubmarine/NormalizedIntFraction.h"

namespace PiSubmarine
{
    // Test for an 8-bit register (common for PWM)
    TEST(NormalizedIntFractionTest, Bit8Basic)
    {
        using NF8 = NormalizedIntFraction<8>;
        EXPECT_EQ(NF8::GetMaxRawValue(), 255);

        // Integer construction
        EXPECT_EQ(NF8(100).Get(), 100);
        EXPECT_THROW(NF8(300), std::overflow_error);

        // Double construction
        EXPECT_EQ(NF8(0.0).Get(), 0);
        EXPECT_EQ(NF8(1.0).Get(), 255);

        // Rounding check: 0.5 * 255 = 127.5 -> std::round -> 128
        EXPECT_EQ(NF8(0.5).Get(), 128);

        // Factor check
        EXPECT_DOUBLE_EQ(NF8(255).ToFactor(), 1.0);
        EXPECT_DOUBLE_EQ(NF8(0).ToFactor(), 0.0);
    }

    // Test for a 12-bit register (common for DACs)
    TEST(NormalizedIntFractionTest, 12BitPrecision)
    {
        using NF12 = NormalizedIntFraction<12>;
        EXPECT_EQ(NF12::GetMaxRawValue(), 4095);

        // 0.25 * 4095 = 1023.75 -> std::round -> 1024
        EXPECT_EQ(NF12(0.25).Get(), 1024);
    }

    // Test clamping behavior for out-of-bounds doubles
    TEST(NormalizedIntFractionTest, OutOfRange)
    {
        using NF10 = NormalizedIntFraction<10>; // Max 1023

        EXPECT_THROW(NF10(-0.5), std::overflow_error);
        EXPECT_THROW(NF10(1.5), std::overflow_error);
        EXPECT_THROW(NF10(100.0), std::overflow_error);
    }

    // Test the 64-bit edge case to ensure no bit-shift overflow (UB)
    TEST(NormalizedIntFractionTest, Bit64EdgeCase)
    {
        using NF64 = NormalizedIntFraction<64>;
        static_assert(NF64::GetMaxRawValue() == std::numeric_limits<uint64_t>::max());

        auto max64 = NF64(1.0);
        EXPECT_EQ(max64.Get(), std::numeric_limits<uint64_t>::max());
        EXPECT_DOUBLE_EQ(max64.ToFactor(), 1.0);

        constexpr auto max64Const = NF64(1.0);
        static_assert(max64Const.Get() == std::numeric_limits<uint64_t>::max());
        EXPECT_DOUBLE_EQ(max64Const.ToFactor(), 1.0);
    }

    // Since we are using C++23, ensure constexpr works as expected
    TEST(NormalizedIntFractionTest, ConstexprVerification)
    {
        static constexpr NormalizedIntFraction<16> const_nf(0.75);

        // 0.75 * 65535 = 49151.25 -> round -> 49151
        static_assert(const_nf.Get() == 49151);
        EXPECT_EQ(const_nf.Get(), 49151);
    }

    // Testing the ToFactor precision back and forth
    TEST(NormalizedIntFractionTest, RoundTrip)
    {
        using NF16 = NormalizedIntFraction<16>;
        double original = 0.333;
        NF16 nf(original);

        // Should be reasonably close within the 16-bit resolution
        EXPECT_NEAR(nf.ToFactor(), original, 1.0 / 65535.0);
    }

    TEST(NormalizedIntFractionTest, RoundingCorrectness)
    {
        // Using 8-bit (Max = 255) for easy manual calculation
        using NF8 = NormalizedIntFraction<8>;
        constexpr uint64_t Max8 = 255;

        // 1. Test "Round Down" (< 0.5)
        // 127.4 / 255.0 is approx 0.4996. Result should be 127.
        EXPECT_EQ(NF8(127.4 / static_cast<double>(Max8)).Get(), 127);

        // 2. Test "Round Up" (>= 0.5)
        // 127.5 / 255.0 is exactly 0.5. Result should be 128.
        EXPECT_EQ(NF8(127.5 / static_cast<double>(Max8)).Get(), 128);

        // 3. Test "Slightly Above" (> 0.5)
        // 127.6 / 255.0 is approx 0.5004. Result should be 128.
        EXPECT_EQ(NF8(127.6 / static_cast<double>(Max8)).Get(), 128);

        // 4. Test exact integers
        EXPECT_EQ(NF8(100.0 / static_cast<double>(Max8)).Get(), 100);
    }

    TEST(NormalizedIntFractionTest, HighBitDepthRounding)
    {
        // 16-bit (Max = 65535)
        using NF16 = NormalizedIntFraction<16>;
        constexpr uint64_t Max16 = 65535;

        // Midpoint check: 32767.5 should round to 32768
        double midpoint = 32767.5 / static_cast<double>(Max16);
        EXPECT_EQ(NF16(midpoint).Get(), 32768);

        // Just below midpoint: 32767.49... should round to 32767
        double justBelow = 32767.499 / static_cast<double>(Max16);
        EXPECT_EQ(NF16(justBelow).Get(), 32767);
    }

    TEST(NormalizedIntFractionTest, ConstexprRoundingCheck)
    {
        // This test ensures that the rounding works correctly at COMPILE TIME.
        // 0.5 * 1023 (10-bit) = 511.5 -> 512
        static constexpr NormalizedIntFraction<10> ConstVal(0.5);
        static_assert(ConstVal.Get() == 512, "Compile-time rounding failed!");

        EXPECT_EQ(ConstVal.Get(), 512);
    }

    TEST(NormalizedIntFractionTest, ExtremeClamping)
    {
        using NF8 = NormalizedIntFraction<8>;

        // Ensure negative doubles don't cause underflow/wrap-around
        EXPECT_THROW(NF8(-0.00001), std::overflow_error);
        EXPECT_THROW(NF8(-100.0), std::overflow_error);

        // Ensure doubles > 1.0 don't cause overflow
        EXPECT_THROW(NF8(1.00001), std::overflow_error);
        EXPECT_THROW(NF8(999.9), std::overflow_error);
    }
}