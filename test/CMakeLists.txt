cmake_minimum_required(VERSION 3.20)

include(FetchContent)

project(PiSubmarine.Units.Test LANGUAGES CXX)

set(PiSubmarine.Units.Test.Sources 
	"PiSubmarine/VoltsTest.cpp"
	"PiSubmarine/AmperesTest.cpp"
	"PiSubmarine/CelciusTest.cpp"
	"PiSubmarine/MetersTest.cpp"
	"PiSubmarine/Pascalstest.cpp"
	"PiSubmarine/WattsTest.cpp"
	"PiSubmarine/NormalizedIntFractionTest.cpp"
	"PiSubmarine/NormalizedFractionTest.cpp"
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