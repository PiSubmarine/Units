#pragma once

namespace PiSubmarine
{
    struct Celcius
    {
        double Value;
    };

    constexpr Celcius operator"" _C(long double c)
    {
        return Celcius(static_cast<double>(c));
    }

    constexpr Celcius operator"" _C(unsigned long long c)
    {
        return Celcius(static_cast<double>(c));
    }

}