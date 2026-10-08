
cmake_minimum_required(VERSION 3.20)

project(PaStorage LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_library(pastorage_core
    src/core/PasswordEntry.cpp
)

target_include_directories(pastorage_core PUBLIC src)

add_executable(PaStorage src/main.cpp)
target_link_libraries(PaStorage PRIVATE pastorage_core)

enable_testing()

add_executable(pastorage_tests
    tests/PasswordEntryTest.cpp
)

target_link_libraries(pastorage_tests PRIVATE
    pastorage_core
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(pastorage_tests)
