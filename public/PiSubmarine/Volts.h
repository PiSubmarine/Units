#pragma once

namespace PiSubmarine
{
    struct Volts
    {
        double Value;
    };

    constexpr Volts operator"" _V(long double v)
    {
        return Volts(static_cast<double>(v));
    }

    constexpr Volts operator"" _V(unsigned long long v)
    {
        return Volts(static_cast<double>(v));
    }

}