cmake_minimum_required(VERSION 3.1)

set(SRC ../src)
set(TEST_SOURCES testfield.cpp testgame.cpp testplayer.cpp ${SRC}/field.h ${SRC}/field.cpp ${SRC}/game.h ${SRC}/game.cpp ${SRC}/player.h ${SRC}/player.cpp ${SRC}/common.h ${SRC}/io.h ${SRC}/io.cpp)
add_executable(testcode ${TEST_SOURCES})
target_include_directories(testcode PUBLIC ${GTEST_SOURCE_DIR}/include)

find_library(GTEST_LIB gtestd ${CMAKE_BINARY_DIR}/lib/Debug)
find_library(GMOCK_LIB gmockd ${CMAKE_BINARY_DIR}/lib/Debug)

if(GTEST_LIB)
    message("GTest is FOUND!")
else()
    message("GTest isn't FOUND!")
endif()

target_link_libraries(testcode gtest gmock_main gtest_main)
add_test(testcode testcode)

