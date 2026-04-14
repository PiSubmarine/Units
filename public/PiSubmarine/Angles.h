#pragma once

#include <numbers>

namespace PiSubmarine
{
    struct Degrees;

    struct Radians
    {
        double Value = 0.0;

        constexpr Radians() = default;

        constexpr explicit Radians(const double value)
            : Value(value)
        {
        }

        constexpr explicit Radians(Degrees degrees);

        [[nodiscard]] constexpr Degrees ToDegrees() const;

        [[nodiscard]] constexpr bool operator==(const Radians&) const = default;
    };

    struct Degrees
    {
        double Value = 0.0;

        constexpr Degrees() = default;

        constexpr explicit Degrees(const double value)
            : Value(value)
        {
        }

        constexpr explicit Degrees(Radians radians);

        [[nodiscard]] constexpr Radians ToRadians() const;

        [[nodiscard]] constexpr bool operator==(const Degrees&) const = default;
    };

    constexpr Radians::Radians(const Degrees degrees)
        : Value(degrees.Value * std::numbers::pi_v<double> / 180.0)
    {
    }

    [[nodiscard]] constexpr Degrees Radians::ToDegrees() const
    {
        return Degrees(Value * 180.0 / std::numbers::pi_v<double>);
    }

    constexpr Degrees::Degrees(const Radians radians)
        : Value(radians.Value * 180.0 / std::numbers::pi_v<double>)
    {
    }

    [[nodiscard]] constexpr Radians Degrees::ToRadians() const
    {
        return Radians(Value * std::numbers::pi_v<double> / 180.0);
    }

    [[nodiscard]] constexpr Radians operator+(const Radians left, const Radians right)
    {
        return Radians(left.Value + right.Value);
    }

    [[nodiscard]] constexpr Radians operator-(const Radians left, const Radians right)
    {
        return Radians(left.Value - right.Value);
    }

    [[nodiscard]] constexpr Radians operator-(const Radians value)
    {
        return Radians(-value.Value);
    }

    [[nodiscard]] constexpr Radians operator*(const Radians radians, const double multiplier)
    {
        return Radians(radians.Value * multiplier);
    }

    [[nodiscard]] constexpr Radians operator*(const double multiplier, const Radians radians)
    {
        return radians * multiplier;
    }

    [[nodiscard]] constexpr Radians operator/(const Radians radians, const double divisor)
    {
        return Radians(radians.Value / divisor);
    }

    [[nodiscard]] constexpr Degrees operator+(const Degrees left, const Degrees right)
    {
        return Degrees(left.Value + right.Value);
    }

    [[nodiscard]] constexpr Degrees operator-(const Degrees left, const Degrees right)
    {
        return Degrees(left.Value - right.Value);
    }

    [[nodiscard]] constexpr Degrees operator-(const Degrees value)
    {
        return Degrees(-value.Value);
    }

    [[nodiscard]] constexpr Degrees operator*(const Degrees degrees, const double multiplier)
    {
        return Degrees(degrees.Value * multiplier);
    }

    [[nodiscard]] constexpr Degrees operator*(const double multiplier, const Degrees degrees)
    {
        return degrees * multiplier;
    }

    [[nodiscard]] constexpr Degrees operator/(const Degrees degrees, const double divisor)
    {
        return Degrees(degrees.Value / divisor);
    }

    [[nodiscard]] constexpr Radians Pi() noexcept
    {
        return Radians(std::numbers::pi_v<double>);
    }

    [[nodiscard]] constexpr Radians Tau() noexcept
    {
        return Radians(2.0 * std::numbers::pi_v<double>);
    }

    [[nodiscard]] constexpr Radians NormalizePositive(const Radians angle) noexcept
    {
        double normalized = angle.Value;

        while (normalized < 0.0)
        {
            normalized += Tau().Value;
        }

        while (normalized >= Tau().Value)
        {
            normalized -= Tau().Value;
        }

        return Radians(normalized);
    }

    constexpr Radians operator"" _rad(long double radians)
    {
        return Radians(static_cast<double>(radians));
    }

    constexpr Radians operator"" _rad(unsigned long long radians)
    {
        return Radians(static_cast<double>(radians));
    }

    constexpr Degrees operator"" _deg(long double degrees)
    {
        return Degrees(static_cast<double>(degrees));
    }

    constexpr Degrees operator"" _deg(unsigned long long degrees)
    {
        return Degrees(static_cast<double>(degrees));
    }
}
