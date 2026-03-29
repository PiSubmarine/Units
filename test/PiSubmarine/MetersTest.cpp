#include <gtest/gtest.h>
#include "PiSubmarine/Meters.h"

namespace PiSubmarine
{
	TEST(MetersTest, Constructor)
	{
		Meters unit = 0.1_m;
		ASSERT_EQ(unit.Value, 0.1);
	}
}