#pragma once

#include <cstddef>
#include <cstdint>
#include <cmath>
#include <algorithm>
#include <concepts>
#include <version>
#include <limits>
#include "PiSubmarine/Exceptions.h"

#ifndef __cpp_concepts
static_assert(false, "This compiler does not support Concepts.");
#endif

namespace PiSubmarine
{
    template<size_t Base>
    struct NormalizedIntFraction
    {
        static_assert(Base > 0 && Base <= 64, "Base must be in the range [1, 64].");

        // MSVC C4293 fix: Use % 64 to avoid warning on unreachable branch
        static constexpr uint64_t MaxValue = (Base >= 64) ? ~0ULL : ((1ULL << (Base % 64)) - 1);

    public:
        using ValueType = uint64_t;

        constexpr NormalizedIntFraction() noexcept : Value(0) {}

        template<std::integral T>
        explicit constexpr NormalizedIntFraction(T value)
            : Value(static_cast<uint64_t>(value) > MaxValue ? MaxValue : static_cast<uint64_t>(value))
        {
            if (0 > value || value > MaxValue)
            {
                Exceptions::Throw(std::overflow_error("Value (double) must be in range [0, 1]"));
            }
        }

        template<std::floating_point T>
        explicit constexpr NormalizedIntFraction(T value)
        {
            if (0 > value || value > 1.0)
            {
                Exceptions::Throw(std::overflow_error("Value (double) must be in range [0, 1]"));
            }

            // Cannot be less than 0
            double delta1 = 1.0 - value;
            if (delta1 < 1E-10)
            {
                Value = MaxValue;
            }
            else
            {
                Value = ConstexprRound(static_cast<double>(value));
            }
        }

        [[nodiscard]] constexpr ValueType Get() const noexcept { return Value; }

        [[nodiscard]] constexpr double ToFactor() const noexcept
        {
            return static_cast<double>(Value) / static_cast<double>(MaxValue);
        }

        [[nodiscard]] static constexpr ValueType GetMaxRawValue() noexcept { return MaxValue; }

    private:
        static constexpr uint64_t ConstexprRound(double factor) noexcept
        {
            // Multiplying factor * MaxValue
            double scaled = factor * static_cast<double>(MaxValue);

#if defined(__cpp_lib_constexpr_cmath) && __cpp_lib_constexpr_cmath >= 202202L
            double rounded = std::round(scaled);
#else
            const auto integerPart = static_cast<uint64_t>(scaled);
            const double fractionalPart = scaled - static_cast<double>(integerPart);
            double rounded = (fractionalPart >= 0.5) ? static_cast<double>(integerPart + 1) : static_cast<double>(integerPart);
#endif
            // Final safety check: If precision error pushed us to (Max+1), clamp it.
            if (rounded >= static_cast<double>(MaxValue))
            {
                return MaxValue;
            }
            return static_cast<uint64_t>(rounded);
        }

        ValueType Value;
    };
}
