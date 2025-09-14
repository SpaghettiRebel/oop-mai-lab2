cmake_minimum_required(VERSION 3.14)
project(OOP LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_library(mylib src/func.cpp)
target_include_directories(mylib PUBLIC include)

add_executable(my_app src/lab1.cpp)
target_link_libraries(my_app PRIVATE mylib)

set_target_properties(my_app PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(my_tests tests/test_main.cpp)
target_link_libraries(my_tests PRIVATE mylib GTest::gtest GTest::gtest_main)

set_target_properties(my_tests PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

include(GoogleTest)
gtest_discover_tests(my_tests)
