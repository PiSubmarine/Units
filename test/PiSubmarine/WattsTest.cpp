#include <gtest/gtest.h>
#include "PiSubmarine/Watts.h"

namespace PiSubmarine
{
	TEST(WattsTest, Constructor)
	{
		Watts unit = 0.1_W;
		ASSERT_EQ(unit.Value, 0.1);
	}
}