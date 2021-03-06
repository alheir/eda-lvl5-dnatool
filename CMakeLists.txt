cmake_minimum_required(VERSION 3.1.4)
project(main VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 11)

# Imprimir informacion para debuggear
set(CTEST_OUTPUT_ON_FAILURE ON)

# From "Working with CMake" documentation:
if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin" OR ${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    # AddressSanitizer (ASan)
    add_compile_options(-fsanitize=address)
    add_link_options(-fsanitize=address)
endif()
if (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    # UndefinedBehaviorSanitizer (UBSan)
    add_compile_options(-fsanitize=undefined)
    add_link_options(-fsanitize=undefined)
endif()

add_executable(main main.cpp Aligner.cpp DirectionMat.cpp GBReader.cpp)

# Copy resources folder to build folder
# file(COPY ${CMAKE_SOURCE_DIR}/resources  DESTINATION ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE_INIT})

# Test
enable_testing()

add_executable(main_test main_test.cpp Aligner.cpp DirectionMat.cpp GBReader.cpp)

add_test(NAME test1 COMMAND main_test)
