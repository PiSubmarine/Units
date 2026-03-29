#include <gtest/gtest.h>
#include "PiSubmarine/Amperes.h"

namespace PiSubmarine
{
	TEST(AmperesTest, Constructor)
	{
		Amperes unit = 0.1_A;
		ASSERT_EQ(unit.Value, 0.1);
	}
}