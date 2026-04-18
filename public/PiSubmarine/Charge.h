#pragma once

namespace PiSubmarine
{
    struct AmpereHours;

    struct Coulombs
    {
        double Value = 0.0;

        constexpr Coulombs() = default;

        constexpr explicit Coulombs(const double value)
            : Value(value)
        {
        }

        constexpr explicit Coulombs(const AmpereHours ampereHours);

        [[nodiscard]] constexpr AmpereHours ToAmpereHours() const;

        [[nodiscard]] constexpr bool operator==(const Coulombs&) const = default;
    };

    struct AmpereHours
    {
        double Value = 0.0;

        constexpr AmpereHours() = default;

        constexpr explicit AmpereHours(const double value)
            : Value(value)
        {
        }

        constexpr explicit AmpereHours(const Coulombs coulombs);

        [[nodiscard]] constexpr Coulombs ToCoulombs() const;

        [[nodiscard]] constexpr bool operator==(const AmpereHours&) const = default;
    };

    constexpr Coulombs::Coulombs(const AmpereHours ampereHours)
        : Value(ampereHours.Value * 3600.0)
    {
    }

    [[nodiscard]] constexpr AmpereHours Coulombs::ToAmpereHours() const
    {
        return AmpereHours(Value / 3600.0);
    }

    constexpr AmpereHours::AmpereHours(const Coulombs coulombs)
        : Value(coulombs.Value / 3600.0)
    {
    }

    [[nodiscard]] constexpr Coulombs AmpereHours::ToCoulombs() const
    {
        return Coulombs(Value * 3600.0);
    }

    constexpr Coulombs operator"" _C(long double value)
    {
        return Coulombs(static_cast<double>(value));
    }

    constexpr Coulombs operator"" _C(unsigned long long value)
    {
        return Coulombs(static_cast<double>(value));
    }

    constexpr AmpereHours operator"" _Ah(long double value)
    {
        return AmpereHours(static_cast<double>(value));
    }

    constexpr AmpereHours operator"" _Ah(unsigned long long value)
    {
        return AmpereHours(static_cast<double>(value));
    }
}
