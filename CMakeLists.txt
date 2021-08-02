cmake_minimum_required(VERSION 3.10)
project(PrimeBreakdown VERSION 0.1)

add_executable(prime-breakdown main.cpp)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(PrimeBreakdownConfig.h.in PrimeBreakdownConfig.h)


target_include_directories(prime-breakdown PUBLIC "${PROJECT_BINARY_DIR}")
