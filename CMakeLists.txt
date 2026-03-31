cmake_minimum_required(VERSION 4.0)
project(COMP595_Problem)

add_compile_options(-fanalyzer -Wall -Wextra -fsanitize=address)
add_link_options(-fsanitize=address)
set(CMAKE_CXX_STANDARD 23)

add_executable(AC ac.cpp)
add_executable(TLE_CRT tle_crt.cpp)
add_executable(TLE_simplest tle_simplest.cpp)
add_executable(WA_distinct wa_distinctprimes.cpp)

add_executable(findMods findMods.cpp)