cmake_minimum_required(VERSION 3.9...3.19)
project(Project3 CXX)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# add cmake modules
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

# build test driver executable
add_executable(unit_tests catch.hpp unit_tests.cpp
  test_complex.cpp complex.hpp complex.cpp
  test_signal.cpp signal.hpp signal.tpp
  test_fft.cpp fft.hpp fft.cpp
  test_filter.cpp filter.hpp filter.cpp)

# enable testing
enable_testing()

# register Catch tests with cmake
include(Catch)
catch_discover_tests(unit_tests)

