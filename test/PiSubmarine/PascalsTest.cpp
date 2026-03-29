#include <gtest/gtest.h>
#include "PiSubmarine/Pascals.h"

namespace PiSubmarine
{
	TEST(PascalsTest, Constructor)
	{
		Pascals unit = 0.1_Pa;
		ASSERT_EQ(unit.Value, 0.1);
	}
}