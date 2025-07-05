#pragma once

namespace PiSubmarine
{
    struct Volts
    {
        double Value;

        explicit constexpr Volts(double v) : Value(v) {}
    };

    constexpr Volts operator"" _v(long double v)
    {
        return Volts(static_cast<double>(v));
    }

    constexpr Volts operator"" _v(unsigned long long v)
    {
        return Volts(static_cast<double>(v));
    }

}