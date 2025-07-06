#pragma once

namespace PiSubmarine
{
    struct Pascals
    {
        double Value;

        explicit constexpr Pascals(double pa) : Value(pa) {}
    };

    constexpr Pascals operator"" _pa(long double pa)
    {
        return Pascals(static_cast<double>(pa));
    }

    constexpr Pascals operator"" _pa(unsigned long long pa)
    {
        return Pascals(static_cast<double>(pa));
    }

}