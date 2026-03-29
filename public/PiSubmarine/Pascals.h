#pragma once

namespace PiSubmarine
{
    struct Pascals
    {
        double Value;
    };

    constexpr Pascals operator"" _Pa(long double pa)
    {
        return Pascals(static_cast<double>(pa));
    }

    constexpr Pascals operator"" _Pa(unsigned long long pa)
    {
        return Pascals(static_cast<double>(pa));
    }

}