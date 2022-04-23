cmake_minimum_required(VERSION 3.13)

project(Algorithms)

include(FetchContent)
FetchContent_Declare(googletest
    GIT_REPOSITORY https://github.com/google/googletest
    GIT_TAG release-1.11.0)

FetchContent_Declare(googletest)

if(NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BUILD_DIR})
endif()

add_library(Game STATIC Game.cpp)

add_executable(main main.cpp)
target_link_libraries(main Game)

add_executable(testRunner test.cpp)
target_link_libraries(testRunner Game gtest_main gmock_main)