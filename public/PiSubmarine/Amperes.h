#pragma once

namespace PiSubmarine
{
    struct Amperes
    {
        double Value;

        explicit constexpr Amperes(double v) : Value(v) {}
    };

    constexpr Amperes operator"" _a(long double v)
    {
        return Amperes(static_cast<double>(v));
    }

    constexpr Amperes operator"" _a(unsigned long long v)
    {
        return Amperes(static_cast<double>(v));
    }

}