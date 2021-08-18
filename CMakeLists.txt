cmake_minimum_required(VERSION 3.10)
project(PrimeBreakdown VERSION 0.1)

if (UNIX)
  set (CMAKE_CXX_FLAGS "-g3 -Wall -O0")
endif ()   

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack) 

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(csv-parser)
include_directories(inc)
include_directories(src)
set (PrimeBreakdown_SOURCES
    src/main.cpp
    src/prime_breakdown_processor.cpp
    src/cli.cpp
    )


# configure_file(PrimeBreakdownConfig.h.in PrimeBreakdownConfig.h)

add_executable(prime-breakdown ${PrimeBreakdown_SOURCES})

target_link_libraries(prime-breakdown csv)