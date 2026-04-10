#pragma once

namespace PiSubmarine
{
    struct Hertz
    {
        double Value = 0.0;

        constexpr Hertz() = default;

        constexpr explicit Hertz(double value)
            : Value(value)
        {
        }
    };

    constexpr Hertz operator"" _Hz(long double hz)
    {
        return Hertz(static_cast<double>(hz));
    }

    constexpr Hertz operator"" _Hz(unsigned long long hz)
    {
        return Hertz(static_cast<double>(hz));
    }

    constexpr Hertz operator"" _KHz(long double khz)
    {
        return Hertz(static_cast<double>(khz) * 1'000.0);
    }

    constexpr Hertz operator"" _KHz(unsigned long long khz)
    {
        return Hertz(static_cast<double>(khz) * 1'000.0);
    }

    constexpr Hertz operator"" _MHz(long double mhz)
    {
        return Hertz(static_cast<double>(mhz) * 1'000'000.0);
    }

    constexpr Hertz operator"" _MHz(unsigned long long mhz)
    {
        return Hertz(static_cast<double>(mhz) * 1'000'000.0);
    }

    constexpr Hertz operator"" _GHz(long double ghz)
    {
        return Hertz(static_cast<double>(ghz) * 1'000'000'000.0);
    }

    constexpr Hertz operator"" _GHz(unsigned long long ghz)
    {
        return Hertz(static_cast<double>(ghz) * 1'000'000'000.0);
    }
}
