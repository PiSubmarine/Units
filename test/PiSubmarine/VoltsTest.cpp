#include <gtest/gtest.h>
#include "PiSubmarine/Volts.h"

namespace PiSubmarine
{
	TEST(VoltsTest, Constructor)
	{
		Volts volts = 0.1_V;
		ASSERT_EQ(volts.Value, 0.1);
	}
}