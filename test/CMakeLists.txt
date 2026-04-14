cmake_minimum_required(VERSION 3.20)

include(FetchContent)

project(PiSubmarine.Units.Test LANGUAGES CXX)

set(PiSubmarine.Units.Test.Sources 
	"PiSubmarine/VoltsTest.cpp"
	"PiSubmarine/AmperesTest.cpp"
	"PiSubmarine/CelsiusTest.cpp"
	"PiSubmarine/AngularSectorTest.cpp"
	"PiSubmarine/DegreesTest.cpp"
	"PiSubmarine/HertzTest.cpp"
	"PiSubmarine/MetersTest.cpp"
	"PiSubmarine/PascalsTest.cpp"
	"PiSubmarine/RadiansTest.cpp"
	"PiSubmarine/WattsTest.cpp"
	"PiSubmarine/NormalizedIntFractionTest.cpp"
	"PiSubmarine/NormalizedFractionTest.cpp"
	"PiSubmarine/SignedNormalizedFractionTest.cpp"
)

enable_testing()

find_package(spdlog)
find_package(GTest)

add_executable(PiSubmarine.Units.Test ${PiSubmarine.Units.Test.Sources})
PiSubmarineInitTarget(PiSubmarine.Units.Test)
target_link_libraries(PiSubmarine.Units.Test PRIVATE PiSubmarine.Units)
target_link_libraries(PiSubmarine.Units.Test PRIVATE spdlog::spdlog)
target_link_libraries(PiSubmarine.Units.Test PRIVATE GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(PiSubmarine.Units.Test)
