cmake_minimum_required(VERSION 4.0)
project(COMP595_Problem)

# Add UBSan to guarantee no integer overflow
add_compile_options(-fanalyzer -Wall -Wextra -fsanitize=address -fsanitize=signed-integer-overflow -fno-sanitize-recover=signed-integer-overflow)
add_link_options(-fsanitize=address -fsanitize=signed-integer-overflow -fno-sanitize-recover=signed-integer-overflow)
set(CMAKE_CXX_STANDARD 23)

add_executable(AC solns/ac.cpp)
add_executable(TLE_CRT solns/tle_crt.cpp)
add_executable(TLE_simplest solns/tle_simplest.cpp)
add_executable(TLE_simplelift solns/tle_simplelift.cpp)
add_executable(WA_distinct solns/wa_distinctprimes.cpp)

add_executable(findMods findMods.cpp)
add_executable(polyExpand polyExpand.cpp)
