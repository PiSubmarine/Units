#include <gtest/gtest.h>
#include "PiSubmarine/Celcius.h"

namespace PiSubmarine
{
	TEST(CelciusTest, Constructor)
	{
		Celcius unit = 0.1_C;
		ASSERT_EQ(unit.Value, 0.1);
	}
}