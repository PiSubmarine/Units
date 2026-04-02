#pragma once
#include <stdexcept>
#include <string>
#include "PiSubmarine/Exceptions.h"

namespace PiSubmarine
{
    struct NormalizedFraction
    {
        constexpr NormalizedFraction(double fraction) : m_Value(fraction)
        {
            if (0.0 > fraction || fraction > 1.0)
            {
                Exceptions::Throw(std::invalid_argument("NormalizedFraction value must be in range [0, 1], got " + std::to_string(fraction) + " instead."));
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
