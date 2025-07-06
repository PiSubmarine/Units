#pragma once

namespace PiSubmarine
{
    struct Celcius
    {
        double Value;

        explicit constexpr Celcius(double c) : Value(c) {}
    };

    constexpr Celcius operator"" _w(long double c)
    {
        return Celcius(static_cast<double>(c));
    }

    constexpr Celcius operator"" _w(unsigned long long c)
    {
        return Celcius(static_cast<double>(c));
    }

}