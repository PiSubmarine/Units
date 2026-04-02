#include <gtest/gtest.h>
#include "PiSubmarine/Celsius.h"

namespace PiSubmarine
{
	TEST(CelciusTest, Constructor)
	{
		Celsius unit = 0.1_DegC;
		ASSERT_EQ(unit.Value, 0.1);
	}
}