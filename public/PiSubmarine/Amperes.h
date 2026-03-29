#pragma once

namespace PiSubmarine
{
    struct Amperes
    {
        double Value;
    };

    constexpr Amperes operator"" _A(long double v)
    {
        return Amperes(static_cast<double>(v));
    }

    constexpr Amperes operator"" _A(unsigned long long v)
    {
        return Amperes(static_cast<double>(v));
    }

}