cmake_minimum_required(VERSION 2.6)

project(SZE-MOSZE-2020-POTTYOK)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

get_filename_component(PARENT_DIR ../ ABSOLUTE)
include_directories(${PARENT_DIR})

add_executable( runEntityTests test.cpp ${PARENT_DIR}/Kalandor.cpp ${PARENT_DIR}/JsonParser.cpp ${PARENT_DIR}/Szorny.cpp )
target_link_libraries(runEntityTests gtest gtest_main pthread)
target_compile_features(runEntityTests PRIVATE cxx_std_17)