#pragma once

namespace PiSubmarine
{
    struct Pascals
    {
        double Value;

        explicit constexpr Pascals(double pa) : Value(v) {}
    };

    constexpr Pascals operator"" _pa(long double w)
    {
        return Pascals(static_cast<double>(w));
    }

    constexpr Pascals operator"" _pa(unsigned long long w)
    {
        return Pascals(static_cast<double>(w));
    }

}