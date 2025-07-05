#pragma once

namespace PiSubmarine
{
    struct Meters
    {
        double Value;

        explicit constexpr Meters(double pa) : Value(v) {}
    };

    constexpr Meters operator"" _m(long double w)
    {
        return Meters(static_cast<double>(w));
    }

    constexpr Meters operator"" _m(unsigned long long w)
    {
        return Meters(static_cast<double>(w));
    }

}