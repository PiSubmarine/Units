#pragma once

namespace PiSubmarine
{
    struct Celsius
    {
        double Value;
    };

    constexpr Celsius operator"" _DegC(long double c)
    {
        return Celsius(static_cast<double>(c));
    }

    constexpr Celsius operator"" _DegC(unsigned long long c)
    {
        return Celsius(static_cast<double>(c));
    }

}