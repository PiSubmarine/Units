#pragma once

namespace PiSubmarine
{
    struct Watts
    {
        double Value;

        explicit constexpr Watts(double w) : Value(w) {}
    };

    constexpr Watts operator"" _w(long double w)
    {
        return Watts(static_cast<double>(w));
    }

    constexpr Watts operator"" _w(unsigned long long w)
    {
        return Watts(static_cast<double>(w));
    }

}