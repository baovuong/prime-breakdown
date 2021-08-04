cmake_minimum_required(VERSION 3.10)
project(PrimeBreakdown VERSION 1.1)


# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_subdirectory(csv-parser)


configure_file(PrimeBreakdownConfig.h.in PrimeBreakdownConfig.h)

add_executable(prime-breakdown main.cpp)


target_include_directories(prime-breakdown PUBLIC "${PROJECT_BINARY_DIR}")

target_link_libraries(prime-breakdown csv)