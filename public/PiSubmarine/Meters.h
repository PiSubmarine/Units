#pragma once

namespace PiSubmarine
{
    struct Meters
    {
        double Value;
    };

    constexpr Meters operator"" _m(long double m)
    {
        return Meters(static_cast<double>(m));
    }

    constexpr Meters operator"" _m(unsigned long long m)
    {
        return Meters(static_cast<double>(m));
    }

}