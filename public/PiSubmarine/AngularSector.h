#pragma once

#include "PiSubmarine/Radians.h"

namespace PiSubmarine
{
    struct AngularSector
    {
        Radians Start{};
        Radians Sweep{};

        constexpr AngularSector() = default;

        constexpr AngularSector(const Radians start, const Radians sweep)
            : Start(start)
            , Sweep(sweep)
        {
        }

        [[nodiscard]] constexpr bool IsValid() const noexcept
        {
            return Sweep.Value >= 0.0 && Sweep.Value <= Tau().Value;
        }

        [[nodiscard]] constexpr bool IsFullCircle() const noexcept
        {
            return IsValid() && Sweep.Value == Tau().Value;
        }

        [[nodiscard]] constexpr bool Contains(const Radians angle) const noexcept
        {
            if (!IsValid())
            {
                return false;
            }

            if (IsFullCircle())
            {
                return true;
            }

            return NormalizePositive(angle - Start).Value <= Sweep.Value;
        }
    };
}
