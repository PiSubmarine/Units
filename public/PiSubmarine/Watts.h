#pragma once

namespace PiSubmarine
{
    struct Watts
    {
        double Value;
    };

    constexpr Watts operator"" _W(long double w)
    {
        return Watts(static_cast<double>(w));
    }

    constexpr Watts operator"" _W(unsigned long long w)
    {
        return Watts(static_cast<double>(w));
    }

}