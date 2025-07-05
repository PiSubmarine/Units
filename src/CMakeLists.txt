include("${_build_cmake_local}")

add_library(PiSubmarine.Units INTERFACE)
target_include_directories(PiSubmarine.Units INTERFACE "../public")
