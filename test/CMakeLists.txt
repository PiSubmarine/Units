cmake_minimum_required(VERSION 3.20)

include(FetchContent)

project(PiSubmarine.Units.Test LANGUAGES CXX)

set(PiSubmarine.Units.Test.Sources 
	"PiSubmarine/UnitsTest.cpp")

enable_testing()

# spdlog
find_package(spdlog)
find_package(gtest)

add_executable(PiSubmarine.Units.Test ${PiSubmarine.Units.Test.Sources})
target_compile_features(PiSubmarine.Units.Test PRIVATE cxx_std_23)
target_link_libraries(PiSubmarine.Units.Test PRIVATE PiSubmarine.Units)
target_link_libraries(PiSubmarine.Units.Test PRIVATE spdlog::spdlog)
target_link_libraries(PiSubmarine.Units.Test PRIVATE GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(PiSubmarine.Units.Test)