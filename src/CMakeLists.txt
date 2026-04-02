include("${_build_cmake_local}")

add_library(PiSubmarine.Units INTERFACE)
target_include_directories(PiSubmarine.Units INTERFACE "../public")
PiSubmarineInitTarget(PiSubmarine.Units)

PiSubmarineAddDependency("https://github.com/PiSubmarine/Exceptions.git" "")
target_link_libraries(PiSubmarine.Units INTERFACE PiSubmarine.Exceptions)