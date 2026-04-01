#pragma once
#include <stdexcept>

namespace PiSubmarine
{
    struct SignedNormalizedFraction
    {
    public:
        constexpr SignedNormalizedFraction(double fraction) : m_Value(fraction)
        {
            if (-1.0 > fraction || fraction > 1.0)
            {
                throw std::invalid_argument("NormalizedFraction value must be in range [-1, +1], got " + std::to_string(fraction) + " instead.");
            }
        }

        constexpr operator double() const
        {
            return m_Value;
        }

    private:
        double m_Value;
    };



}
